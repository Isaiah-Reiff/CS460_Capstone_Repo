
#include <schily/mconfig.h>
#ifndef lint
static	UConst char sccsid[] =
	"@(#)cdrdeflt.c	1.25 09/07/10 Copyright 1998-2009 J. Schilling";
#endif

#include <schily/stdlib.h>
#include <schily/unistd.h>
#include <schily/string.h>
#include <schily/stdio.h>
#include <schily/standard.h>
#include <schily/deflts.h>
#include <schily/utypes.h>
#include <schily/schily.h>
#include "cdrdeflt.h"

LOCAL	int	open_cdrdefaults __PR((void));
EXPORT	void	cdr_defaults	__PR((char **devp, int *speedp, long *fsp, long *bufsizep, char **drvoptp));
LOCAL	void	cdr_xdefaults	__PR((char **devp, int *speedp, long *fsp, long *bufsizep, char **drvoptp));
LOCAL	char *	strsv		__PR((char *s));

LOCAL int
open_cdrdefaults()
{
	
	return (defltopen("/etc/default/cdrecord"));
}

EXPORT void
cdr_defaults(devp, speedp, fsp, bufsizep, drvoptp)
	char	**devp;					
	int	*speedp;				
	long	*fsp;					
	long	*bufsizep;				
	char	**drvoptp;				
{
	char	*dev	= NULL;
	int	speed	= 0;
	long	fs	= 0L;
	long	bufsize	= 0L;

	if (devp != NULL)
		dev = *devp;
	if (speedp != NULL)
		speed = *speedp;
	if (fsp != NULL)
		fs = *fsp;
	if (bufsizep != NULL)
		bufsize = *bufsizep;

	if (!dev && devp != NULL) {
		*devp = getenv("CDR_DEVICE");

		if (!*devp && open_cdrdefaults() == 0) {
			dev = defltread("CDR_DEVICE=");
			if (dev != NULL)
				*devp = strsv(dev);
		}
	}
	if (devp != NULL && *devp)
		cdr_xdefaults(devp, &speed, &fs, &bufsize, drvoptp);

	if (speed < 0) {
		char	*p = getenv("CDR_SPEED");

		if (!p) {
			if (open_cdrdefaults() == 0) {
				p = defltread("CDR_SPEED=");
			}
		}
		if (p) {
			speed = atoi(p);
			if (speed < 0 && speed != -1) {
				comerrno(EX_BAD,
					"Bad speed environment (%s).\n", p);
			}
		}
	}
	if (speed >= 0 && speedp != NULL)
		*speedp = speed;

	if (fs < 0L) {
		char	*p = getenv("CDR_FIFOSIZE");

		if (!p) {
			if (open_cdrdefaults() == 0) {
				p = defltread("CDR_FIFOSIZE=");
			}
		}
		if (p) {
			if (getnum(p, &fs) != 1) {
				comerrno(EX_BAD,
					"Bad fifo size environment (%s).\n", p);
			}
		}
	}
	if (fs > 0L && fsp != NULL) {
		char	*p = NULL;
		long	maxfs;

		if (open_cdrdefaults() == 0) {
			p = defltread("CDR_MAXFIFOSIZE=");
		}
		if (p) {
			if (getnum(p, &maxfs) != 1) {
				comerrno(EX_BAD,
					"Bad max fifo size default (%s).\n", p);
			}
			if (fs > maxfs)
				fs = maxfs;
		}
		*fsp = fs;
	}

	if (bufsize < 0L && bufsizep != NULL) {
		char	*p = getenv("CDR_TRANSFERSIZE");

		if (!p) {
			if (open_cdrdefaults() == 0) {
				p = defltread("CDR_TRANSFERSIZE=");
			}
		}
		if (p) {
			if (getnum(p, &bufsize) != 1) {
				comerrno(EX_BAD,
					"Bad transfer size environment (%s).\n", p);
			}
		}
	}
	if (bufsize > 0L && bufsizep != NULL)
		*bufsizep = bufsize;

	defltclose();
}

LOCAL void
cdr_xdefaults(devp, speedp, fsp, bufsizep, drvoptp)
	char	**devp;					
	int	*speedp;				
	long	*fsp;					
	long	*bufsizep;				
	char	**drvoptp;				
{
	char	dname[256];
	char	*p = *devp;
	char	*x = ",:/@";

	while (*x) {
		if (strchr(p, *x))
			return;
		x++;
	}
	js_snprintf(dname, sizeof (dname), "%s=", p);
	if (open_cdrdefaults() != 0)
		return;

	p = defltread(dname);
	if (p != NULL) {
		while (*p == '\t' || *p == ' ')
			p++;
		if ((x = strchr(p, '\t')) != NULL)
			*x = '\0';
		else if ((x = strchr(p, ' ')) != NULL)
			*x = '\0';
		*devp = strsv(p);
		if (x) {
			p = ++x;
			while (*p == '\t' || *p == ' ')
				p++;
			if ((x = strchr(p, '\t')) != NULL)
				*x = '\0';
			else if ((x = strchr(p, ' ')) != NULL)
				*x = '\0';
			if (*speedp < 0)
				*speedp = atoi(p);
			if (*speedp < 0 && *speedp != -1) {
				comerrno(EX_BAD,
					"Bad speed in defaults (%s).\n", p);
			}
		}
		if (x) {
			p = ++x;
			while (*p == '\t' || *p == ' ')
				p++;
			if ((x = strchr(p, '\t')) != NULL)
				*x = '\0';
			else if ((x = strchr(p, ' ')) != NULL)
				*x = '\0';
			if (*fsp < 0L) {
				if (getnum(p, fsp) != 1) {
					comerrno(EX_BAD,
					"Bad fifo size in defaults (%s).\n",
					p);
				}
			}
		}
		if (x) {
			p = ++x;
			while (*p == '\t' || *p == ' ')
				p++;
			if ((x = strchr(p, '\t')) != NULL)
				*x = '\0';
			else if ((x = strchr(p, ' ')) != NULL)
				*x = '\0';
			if (strcmp(p, "\"\"") != '\0') {
				
				if (drvoptp && *drvoptp == NULL)
					*drvoptp = strsv(p);
			}
		}
		if (x) {
			p = ++x;
			while (*p == '\t' || *p == ' ')
				p++;
			if ((x = strchr(p, '\t')) != NULL)
				*x = '\0';
			else if ((x = strchr(p, ' ')) != NULL)
				*x = '\0';
			if (*bufsizep < 0L) {
				if (getnum(p, bufsizep) != 1) {
					comerrno(EX_BAD,
					"Bad transfer size in defaults (%s).\n",
					p);
				}
			}
		}
	}
}

LOCAL char *
strsv(s)
	char	*s;
{
	char	*p;
	int len = strlen(s);

	p = malloc(len+1);
	if (p)
		strcpy(p, s);
	return (p);
}

