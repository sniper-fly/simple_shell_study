#ifndef LSH_H
# define LSH_H

# define LSH_RL_BUFSIZE 1024
# define LSH_TOK_BUFSIZE 64
# define LSH_TOK_DELIM " \t\r\n\a"

void	lsh_loop(void);
char	*lsh_read_line(void);
char	**lsh_split_line(char *line);
int		lsh_launch(char **args);
int		lsh_cd(char **args);
int		lsh_exit(char **args);
int		lsh_execute(char **args);
int		get_next_line(int fd, char **line);

#endif
