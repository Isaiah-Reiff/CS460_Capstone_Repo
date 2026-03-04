

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include "vlock.h"

static unsigned char lines, columns;
static void *screen_buf = 0;
static int vcs = -1;

void
init_screen(void)
{
	int     failed = 1;
	const char clear_str[] = "\33[3J\33[H\33[J";

	vcs = -1;
	do
	{
		struct stat st;
		unsigned i, size;
		char    path[16];

		if (fstat(STDIN_FILENO, &st) == -1)
			break;

		if (!S_ISCHR(st.st_mode))
			break;

		if ((st.st_rdev >> 8) != 4)
			break;

		i = st.st_rdev & 0xff;
		sprintf(path, "/dev/vcsa%u", i);
		vcs = open(path, O_RDWR);
		if (vcs < 0)
			break;

		if (read(vcs, &columns, 1) != 1)
			break;

		if (read(vcs, &lines, 1) != 1)
			break;

		size = 2 * lines * columns + 2;
		screen_buf = malloc(size);
		if (!screen_buf)
			break;

		if (read(vcs, screen_buf, size) != (int) size)
		{
			free(screen_buf);
			screen_buf = NULL;
			break;
		}

		failed = 0;
	} while (0);

	if (failed && vcs >= 0)
	{
		close(vcs);
		vcs = -1;
	}

	
	if (write(STDOUT_FILENO, clear_str, sizeof(clear_str) - 1) !=
	    sizeof(clear_str) - 1)
		return;
}

void
restore_screen(void)
{
	if (screen_buf)
	{
		do
		{
			if (lseek(vcs, 0, SEEK_SET))
				break;
			if (write(vcs, &columns, 1) != 1)
				break;
			if (write(vcs, &lines, 1) != 1)
				break;
			if (write(vcs, screen_buf, 2 * lines * columns + 2) !=
			    2 * lines * columns + 2)
				break;
		} while (0);
		close(vcs);
	}
}

