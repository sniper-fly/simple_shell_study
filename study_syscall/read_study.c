#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>

volatile sig_atomic_t e_flag = 0;
void abrt_handler(int sig);
int		is_there_endl(char *buf);
void	quit_handler(int sig);

// int		main(void)
// {
// 	char buf[1000];
// 	int		read_num;
// 	// int		idx = 0;

// 	memset(buf, 0, 1000);
// 	// while (1)
// 	// {
// 		// if ( signal(SIGINT, abrt_handler) == SIG_ERR ) {
// 		// 	exit(1);
// 		// }
// 		write(1, "> ", 2);
// 		if ( signal(SIGQUIT, SIG_IGN) == SIG_ERR ) {
// 			exit(1);
// 		}
// 		read_num = read(STDIN_FILENO, buf, 1000);
// 		// idx = 0;
// 		// if(!is_there_endl(buf))
// 		// {
// 		// 	for (int i = 0; i < 1000; i++)
// 		// 		if (buf[i] == '\0')
// 		// 			idx = i;
// 		// 	continue;
// 		// }
// 		write(STDOUT_FILENO, buf, 10);
// 	// }

// 	(void)read_num;

	
// 	// printf("%s\n", buf);
// }

int main(void)
{
	char buf[1000];
	int        read_num;

	memset(buf, 0, 1000);
	write(1, "> ", 2);
	if ( signal(SIGQUIT, quit_handler) == SIG_ERR ) {
		exit(1);
	}
	if ( signal(SIGINT, abrt_handler) == SIG_ERR ) {
		exit(1);
	}
	read_num = read(STDIN_FILENO, buf, 1000);
	(void)read_num;
	write(STDOUT_FILENO, buf, 10);
}

void abrt_handler(int sig)
{
	(void)sig;
	write(1, "\n> ", 3);
	e_flag = 1;
}

int		is_there_endl(char *buf)
{
	for (int i = 0; i < 1000; i++)
	{
		if (buf[i] == '\n')
			return (1);
	}
	return (0);
}

void	quit_handler(int sig)
{
	(void)sig;
	write(1, "\b\b  \b\b", 6);
}