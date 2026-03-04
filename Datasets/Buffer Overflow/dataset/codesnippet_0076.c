
#include <schily/mconfig.h>
#ifndef lint
static	UConst char sccsid[] =
	"@(#)desktop.c	1.10 09/07/09 joerg, Copyright 1997, 1998, 1999, 2000 James Pearson, Copyright 2000-2009 J. Schilling";
#endif

#ifdef APPLE_HFS_HYB

#include "mkisofs.h"

#define	DB	"Desktop DB"
#define	DBFC	"DMGR"
#define	DBT	"BTFL"

#define	DF	"Desktop DF"
#define	DFT	"DTFL"

extern	void d_putw	__PR((unsigned char *, short));
extern	void d_putl	__PR((unsigned char *, long));

int	make_desktop	__PR((hfsvol *vol, int end));

extern	hce_mem *hce;	

int
make_desktop(vol, end)
	hfsvol	*vol;
	int	end;
{
	hfsfile		*hfp;			
	hfsdirent	ent;			
	unsigned long	clps;			
	unsigned short	blks;			
	unsigned char	*blk;			

	
	memset(&ent, 0, sizeof (hfsdirent));	
	ent.u.file.rsize = 0;			
	strcpy(ent.u.file.creator, DBFC);	
	strcpy(ent.u.file.type, DBT);		
	ent.crdate = ent.mddate = time(0);	
	ent.fdflags = HFS_FNDR_ISINVISIBLE;	

	
	blk = hce->hfs_ce + hce->hfs_ce_size * HFS_BLOCKSZ;
	blks = hce->hfs_dt_size;
	clps = blks * HFS_BLOCKSZ;

	memset(blk, 0, clps);

	
	if (hfs_create(vol, DB, ent.u.file.type, ent.u.file.creator) == 0) {
		
		d_putw(blk + 8, 0x100);
		d_putw(blk + 10, 0x3);

		d_putw(blk + 32, 0x200);
		d_putw(blk + 34, 0x25);

		d_putl(blk + 36, blks);
		d_putl(blk + 40, blks - 1);

		d_putl(blk + 46, clps);
		d_putw(blk + 50, 0xff);

		d_putw(blk + 120, 0x20a);
		d_putw(blk + 122, 0x100);

		d_putw(blk + 248, 0x8000);

		d_putl(blk + 504, 0x1f800f8);
		d_putl(blk + 508, 0x78000e);

		
		ent.u.file.dsize = clps;	

		
		if ((hfp = hfs_open(vol, DB)) == 0)
			perr(hfs_error);

		
		write_fork(hfp, clps);

		
		if (hfs_fsetattr(hfp, &ent) < 0)
			perr(hfs_error);

		
		end += hce->hfs_ce_size;

		
		if (hfs_close(hfp, end, 0) < 0)
			perr(hfs_error);
	} else {
		
		if (hfs_setattr(vol, DB, &ent) < 0)
			perr(hfs_error);
	}

	
	strcpy(ent.u.file.type, DFT);		
	ent.u.file.dsize = 0;			

	
	hfs_create(vol, DF, ent.u.file.type, ent.u.file.creator);

	
	if (hfs_setattr(vol, DF, &ent) < 0)
		perr(hfs_error);

	return (0);
}

#endif	

