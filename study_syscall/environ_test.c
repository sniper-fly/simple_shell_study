#include <stdio.h>
#include <errno.h>
#include <string.h>

extern char **environ;

int		main(void)
{
	printf("%s", strerror(errno));

	// printf("env below\n");
	// for (int i = 0; environ[i]; i++)
	// 	printf("%s\n", environ[i]);
}