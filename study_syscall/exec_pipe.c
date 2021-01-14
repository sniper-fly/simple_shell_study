#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

typedef struct s_cmd {
	char 			*(arg[10]);
	struct s_cmd	*next;
} cmd_lst;

void exec_pipe(cmd_lst *lst);

int		main(void)
{
	cmd_lst *lst;
	lst = (cmd_lst*)malloc(sizeof(cmd_lst) * (1));
	lst->arg[0] = "/usr/bin/wc";  //"cat";
	lst->arg[1] = NULL;  //"-e";
	// lst->arg[2] = NULL;

	lst->next = (cmd_lst*)malloc(sizeof(cmd_lst) * (1));
	lst->next->arg[0] = "/bin/ls";
	lst->next->arg[1] = "-l";
	// lst->next->arg[2] = NULL;

	// lst->next->next = (cmd_lst*)malloc(sizeof(cmd_lst) * (1));
	// lst->next->next->arg[0] = "wc";
	// lst->next->next->arg[1] = NULL;

	exec_pipe(lst);
}

void exec_pipe(cmd_lst *lst)
{
	pid_t pid;
	int fds[2];
	int status;

	if(!(lst->next)) {
		execvp(lst->arg[0], lst->arg);
		exit(0);
	}
	pipe(fds);
	pid =  fork();
	if(pid) {
		// parent
		close(fds[1]);
		dup2(fds[0], 0);
		close(fds[0]);
		waitpid(pid, &status, WUNTRACED);
		execvp(lst->arg[0], lst->arg);
		exit(WEXITSTATUS(status));
	}else{
		// child
		close(fds[0]);
		dup2(fds[1], 1);
		close(fds[1]);
		exec_pipe(lst->next);
		exit(0);
	}
}
