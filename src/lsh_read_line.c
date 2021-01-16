#include "lsh.h"
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

volatile sig_atomic_t e_flag = 0;

void abrt_handler(int sig) {
	(void)sig;
	e_flag = 1;
}

char	*lsh_read_line(void)
{
	int		bufsize = LSH_RL_BUFSIZE;
	int		position = 0;
	char	*buffer = (char*)malloc(sizeof(char) * bufsize);
	int		c;

	if (!buffer)//allocation error
		exit(EXIT_FAILURE);
	
	if ( signal(SIGINT, abrt_handler) == SIG_ERR ) {
		exit(1);
	}
	
	while (1)
	{
		// read(0, buf, 100);
		c = getchar();
		if (e_flag)
		{
			printf("\n");
			e_flag = 0;
			// return (NULL);
		}

		if (c == EOF || c == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else
		{
			buffer[position] = c;
		}
		position++;

		if (position >= bufsize)
		{
			bufsize += LSH_RL_BUFSIZE;
			buffer = (char*)realloc(buffer, bufsize);
			if (!buffer)//allocation error
				exit(EXIT_FAILURE);
		}
		
	}
}

// char	*lsh_read_line(void)
// {
// 	char	*line = NULL;
// 	ssize_t	bufsize = 0;

// 	if (getline(&line, &bufsize, stdin) == -1)
// 	{
// 		if (feof(stdin))
// 		{
// 			exit(EXIT_SUCCESS);
// 		}
// 		else
// 		{
// 			perror("readline");
// 			exit(EXIT_FAILURE);
// 		}
// 	}
// }