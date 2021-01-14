#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>

int		main(void)
{
	char	*argv[4];

	argv[0] = "/bin/ls";
	argv[1] = "-l";
	argv[2] = NULL;
	

	execve("/bin/ls", argv, argv);
}