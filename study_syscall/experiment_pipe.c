#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int		main(void)
{
	pid_t	child;
	char	*args[] = {"ls", "-l", NULL};
	// char	*parent_args[] = {"wc", "-c", NULL};
	char	*parent_args[] = {"grep", "test", NULL};
	int		pipe_fd[2];
	int		status;
	int		status2;

	pipe(pipe_fd);
	child = fork();
	if (child)
	{
		// sleep(2);
		child = fork();
		// close(pipe_fd[0]);
		// close(1);
		// dup2(pipe_fd[1], 1);
		// close(pipe_fd[1]);
		waitpid(child, &status2, WUNTRACED);

		if (child)
		{
			execvp("ls", args);
			sleep(3);
			dup2(pipe_fd[1], 1);
			close(pipe_fd[1]);
			execvp("ls", args);
			return (1);
		}
	}
	else
	{
		waitpid(child, &status, WUNTRACED);
		close(pipe_fd[1]);
		close(0);
		dup2(pipe_fd[0], 0);
		close(pipe_fd[0]);
		// execvp("wc", parent_args);
		execvp("grep", parent_args);
	}
	return (0);
}
