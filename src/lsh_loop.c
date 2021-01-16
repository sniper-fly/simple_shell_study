#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "lsh.h"

void	lsh_loop(void)
{
	char	*line;
	char	**args;
	int		status;

	do {
		write(STDOUT_FILENO, "> ", 2);
		line = lsh_read_line();
		args = lsh_split_line(line);
		status = lsh_execute(args);

		free(line);
		free(args);
	} while (status);
}
