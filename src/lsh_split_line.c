#include "lsh.h"
#include <stdlib.h>

char	**lsh_split_line(char *line)
{
	int		bufsize = LSH_TOK_BUFSIZE, position = 0;
	char	**tokens = (char**)malloc(bufsize * sizeof(char*));
	char	*token;

	if (!tokens)
		exit(EXIT_FAILURE);

	//split with delimiter
	token = strtok(line, LSH_TOK_DELIM);

	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += LSH_TOK_BUFSIZE;
			tokens = (char**)realloc(tokens, bufsize * sizeof(char*));
			if (!tokens)
				exit(EXIT_FAILURE);//alloc
		}
		token = strtok(NULL, LSH_TOK_DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}