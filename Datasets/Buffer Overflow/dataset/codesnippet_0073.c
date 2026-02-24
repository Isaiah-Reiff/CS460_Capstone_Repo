

#include <schily/unistd.h>
#include <schily/types.h>
#include <schily/errno.h>
#include <schily/maxpath.h>
#include <schily/string.h>
#include <schily/standard.h>
#include <schily/schily.h>

EXPORT	char	*abspath	__PR((const char *relp, char *absp, size_t asize));
EXPORT	char	*absnpath	__PR((const char *relp, char *absp, size_t asize));
LOCAL	char	*pathabs	__PR((const char *relp, char *absp, size_t asize, int flags));
LOCAL	void	ashorten	__PR((char *name));

EXPORT char *
abspath(relp, absp, asize)
		const	char	*relp;
			char	*absp;
			size_t	asize;
{
	return (pathabs(relp, absp, asize, RSPF_EXIST));
}

EXPORT char *
absnpath(relp, absp, asize)
		const	char	*relp;
			char	*absp;
			size_t	asize;
{
	return (pathabs(relp, absp, asize, 0));
}

EXPORT char *
absfpath(relp, absp, asize, flags)
		const	char	*relp;
			char	*absp;
			size_t	asize;
			int	flags;
{
	return (pathabs(relp, absp, asize, flags));
}

LOCAL char *
pathabs(relp, absp, asize, flags)
		const	char	*relp;
			char	*absp;
			size_t	asize;
			int	flags;
{
	register	char	*rel;
	register	char	*full;
			int	ret;

	ret = resolvefpath(relp, absp, asize, flags);
	if (ret < 0)
		return (NULL);			
	if (ret >= asize) {
		seterrno(ERANGE);
		return (NULL);
	}
	if (absp[0] == '/')
		return (absp);

	if (absp[0] == '.' && absp[1] == '\0')
		return (getcwd(absp, asize));	

	{	int	len = strlen(absp)+1;
#ifdef	HAVE_DYN_ARRAYS
		char	tbuf[len];
#else
		char	*tbuf = malloc(len);
		if (tbuf == NULL)
			return (NULL);
#endif
		strcpy(tbuf, absp);
		absp[0] = '\0';
		full = getcwd(absp, asize);	

		if (full && strlcat(full, "/", asize) >= asize) {
			seterrno(ERANGE);
			full = NULL;
		}
		if (full && strlcat(full, tbuf, asize) >= asize) {
			seterrno(ERANGE);
			full = NULL;
		}

#ifndef	HAVE_DYN_ARRAYS
		free(tbuf);
#endif
		if (full == NULL)
			return (full);
	}
	rel = full;
	for (;;) {
		for (;;) {
			rel = strchr(++rel, '/');
			if (rel == NULL)
				break;
			if (rel[1] == '/' || rel[1] == '\0') {
				*rel++ = '\0';
							
							
				while (rel[0] == '/')
					rel++;
				break;
			}
			if (rel[1] == '.') {
							
				if (rel[2] == '/') {
					*rel = '\0';
					rel += 3;
					break;
				}
							
				if (rel[2] == '\0') {
					*rel = '\0';
					rel += 2;
					break;
				}
				if (rel[2] == '.') {
							
					if (rel[3] == '/') {
						*rel = '\0';
						rel += 4;
						ashorten(full);
						break;
					}
							
					if (rel[3] == '\0') {
						*rel = '\0';
						ashorten(full);
						break;
					}
				}
			}
		}
		if (rel == NULL || rel[0] == '\0')
			break;

#ifdef	DEBUG
		printf("%s / %s\n", full, rel);
#endif
		if (strlcat(full, "/", asize) >= asize) {
			seterrno(ERANGE);
			return (NULL);
		}
		if (strlcat(full, rel, asize) >= asize) {
			seterrno(ERANGE);
			return (NULL);
		}
		rel = full;
	}
	if (full[1] == '.' && full[2] == '\0') 			
		full[1] = '\0';
	return (full);
}

LOCAL void
ashorten(name)
	register	char	*name;
{
	register	char	*p;

	for (p = name++; *p++ != '\0'; );
	while (p > name)
		if (*--p == '/')
			break;
	*p = '\0';
}

