#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int		main(void)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		puts("child");
		sleep(1);
		return (3);
	}
	else
	{
		// do {
			waitpid(pid, &status, WUNTRACED);
		// } while (!WIFEXITED(status));
		printf("%d\n", status);
		puts("parent");
	}
	return (0);
}