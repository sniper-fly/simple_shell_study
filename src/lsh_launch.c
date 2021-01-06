#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int		lsh_launch(char **args)
{
	pid_t	pid, wpid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("lsh");
		}
		exit(EXIT_FAILURE);
	} else if (pid < 0)
		perror("lsh");
	else
	{
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

//WUNTRACED: 子プロセスが停止した場合にも復帰する (子プロセスが ptrace(2) でトレースされている場合は除く)。 このオプションが指定されていない場合でも、停止したプロセスが 「トレース (traced)」されていれば、子プロセスの状態が報告される。
