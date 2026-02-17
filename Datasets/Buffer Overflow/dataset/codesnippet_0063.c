

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>	
#include <sys/types.h>
#include <errno.h>
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif
#ifdef HAVE_STRING_H
#include <string.h>
#endif
#ifdef HAVE_SYS_FILE_H
#include <sys/file.h>   
#endif
#if defined(_WIN32) && !defined(__CYGWIN__)
#include <windows.h>
#endif

#ifndef R_OK
#define R_OK 4
#define W_OK 2
#define X_OK 1
#endif

#include "libiberty.h"
extern int mkstemps (char *, int);

#ifndef DIR_SEPARATOR
#define DIR_SEPARATOR '/'
#endif

#define TEMP_FILE "ccXXXXXX"
#define TEMP_FILE_LEN (sizeof(TEMP_FILE) - 1)

#if !defined(_WIN32) || defined(__CYGWIN__)

static inline const char *try_dir (const char *, const char *);

static inline const char *
try_dir (const char *dir, const char *base)
{
  if (base != 0)
    return base;
  if (dir != 0
      && access (dir, R_OK | W_OK | X_OK) == 0)
    return dir;
  return 0;
}

static const char tmp[] = { DIR_SEPARATOR, 't', 'm', 'p', 0 };
static const char usrtmp[] =
{ DIR_SEPARATOR, 'u', 's', 'r', DIR_SEPARATOR, 't', 'm', 'p', 0 };
static const char vartmp[] =
{ DIR_SEPARATOR, 'v', 'a', 'r', DIR_SEPARATOR, 't', 'm', 'p', 0 };

#endif

static char *memoized_tmpdir;

const char *
choose_tmpdir (void)
{
  if (!memoized_tmpdir)
    {
#if !defined(_WIN32) || defined(__CYGWIN__)
      const char *base = 0;
      char *tmpdir;
      unsigned int len;
      
#ifdef VMS
      
      base = try_dir ("/sys$scratch", base);
#else
      base = try_dir (getenv ("TMPDIR"), base);
      base = try_dir (getenv ("TMP"), base);
      base = try_dir (getenv ("TEMP"), base);
#endif
      
#ifdef P_tmpdir
      
      if (strcmp (P_tmpdir, "\\") == 0)
	base = try_dir ("\\.", base);
      else
	base = try_dir (P_tmpdir, base);
#endif

      
      base = try_dir (vartmp, base);
      base = try_dir (usrtmp, base);
      base = try_dir (tmp, base);
      
      
      if (base == 0)
	base = ".";
      
      len = strlen (base);
      tmpdir = XNEWVEC (char, len + 2);
      strcpy (tmpdir, base);
      tmpdir[len] = DIR_SEPARATOR;
      tmpdir[len+1] = '\0';
      memoized_tmpdir = tmpdir;
#else 
      DWORD len;

      
      len = GetTempPath(0, NULL);
      if (len)
	{
	  memoized_tmpdir = XNEWVEC (char, len);
	  if (!GetTempPath(len, memoized_tmpdir))
	    {
	      XDELETEVEC (memoized_tmpdir);
	      memoized_tmpdir = NULL;
	    }
	}
      if (!memoized_tmpdir)
	
	memoized_tmpdir = xstrdup (".\\");
#endif 
    }

  return memoized_tmpdir;
}

char *
make_temp_file (const char *suffix)
{
  const char *base = choose_tmpdir ();
  char *temp_filename;
  int base_len, suffix_len;
  int fd;

  if (suffix == 0)
    suffix = "";

  base_len = strlen (base);
  suffix_len = strlen (suffix);

  temp_filename = XNEWVEC (char, base_len
			   + TEMP_FILE_LEN
			   + suffix_len + 1);
  strcpy (temp_filename, base);
  strcpy (temp_filename + base_len, TEMP_FILE);
  strcpy (temp_filename + base_len + TEMP_FILE_LEN, suffix);

  fd = mkstemps (temp_filename, suffix_len);
  
  if (fd == -1)
    {
      fprintf (stderr, "Cannot create temporary file in %s: %s\n",
	       base, strerror (errno));
      abort ();
    }
  
  if (close (fd))
    abort ();
  return temp_filename;
}

