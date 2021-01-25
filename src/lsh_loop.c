#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "lsh.h"

void	lsh_loop(void)
{
	char	*line;
	char	**args;
	int		status;

	// ここでシグナルハンドラを登録し、フォークして読み取りを別プロセスで行う。
	// 別プロセスでシグナルが起動したら子プロセスを終了して再度同じことをやる。
	// これでCtrl-cやCtrl-\を再現できるのでは
	do {
		write(STDOUT_FILENO, "> ", 2);
		line = lsh_read_line();
		args = lsh_split_line(line);
		status = lsh_execute(args);

		free(line);
		free(args);
	} while (status);
}

// A | B | C ; D ; E | F ; G

// cd
// export
// unset
// A B C
// export foo=foo
// E F
// G
