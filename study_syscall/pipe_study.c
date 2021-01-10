#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int		pipe_fd[2];

void	do_child(void)
{
	char	*p = "hello, dad!!\n";
	printf("this is child.\n");

	close(pipe_fd[0]);

	close(1);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[1]);
	while (*p)
	{
		if (write(1, p, 1) < 0)
		{
			perror("write");
			exit(1);
		}
		p++;
	}
}

void	do_parent(void)
{
	char	ch;
	int		status;

	printf("this is parent.\n");

	close(pipe_fd[1]);

	close(0);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[0]);
	while ((ch = getchar()) != EOF)
		putchar(ch);
	if (wait(&status) < 0)
	{
		perror("wait");
		exit(1);
	}
}

int		main(void)
{
	int		child;

	if (pipe(pipe_fd) < 0)
	{
		perror("pipe");
		exit(1);
	}
	if ((child = fork()) < 0)
	{
		perror("fork");
		exit(1);
	}
	if (child)
		do_parent();
	else
		do_child();
}