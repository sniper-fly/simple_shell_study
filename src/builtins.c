#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		lsh_cd(char **args)
{
	if (args[1] == NULL)
		fprintf(stderr, "expected argument\n");
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("lsh");
		}
	}
	return (1);
}

int lsh_exit(char **args) {
	(void)args;
	return (0);
}
