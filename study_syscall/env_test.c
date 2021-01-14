#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>

int		main(int argc, char **argv, char **envp)
{
	(void)argv;
	if (argc == 2)
		for (int i = 0; environ[i]; i++)
			printf("%s\n", environ[i]);
	else
		for (int i = 0; envp[i]; i++)
			printf("%s\n", envp[i]);
}