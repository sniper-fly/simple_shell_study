#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    char *argv[] = {"ls", "|", "head" , "|", "wc", NULL};
    int i, pipe_locate[10], pipe_count = 0;
    pipe_locate[0] = -1;
    for (i = 0; argv[i] != NULL; i++) {
        if (strcmp(argv[i], "|") == 0) {
            pipe_count++;
            pipe_locate[pipe_count] = i;
            argv[i] = NULL;
        }
    }

	//パイプがなかったときの例外処理
    int pfd[9][2];
    if (pipe_count == 0) {
        if (fork() == 0) {
            execvp(argv[0], argv);
            exit(0);
        }
        else {
            int status;
            wait(&status);
        }
    }

    for (i = 0; i < pipe_count + 1 && pipe_count != 0; i++) {
		//最後のコマンドじゃなければパイプ作成
        if (i != pipe_count) pipe(pfd[i]);

		//子プロセス
        if (fork() == 0) {
			//最初のコマンドなのでstdoutを次のパイプの入口につなげる
            if (i == 0) {
                dup2(pfd[i][1], 1);
                close(pfd[i][0]); close(pfd[i][1]);

			//最後のコマンドなのでstdinを前のパイプの出口につなげる
            } else if (i == pipe_count) {
                dup2(pfd[i - 1][0], 0);
                close(pfd[i - 1][0]); close(pfd[i - 1][1]);

			//途中のコマンドなので上記の処理をどちらもやる
            } else {
                dup2(pfd[i - 1][0], 0);
                dup2(pfd[i][1], 1);
                close(pfd[i - 1][0]); close(pfd[i - 1][1]);
                close(pfd[i][0]); close(pfd[i][1]);
            }

			//処理に時間がかかるコマンドだったらwaitしない限り順番通り動くことは保証されないのでは？
            execvp(argv[pipe_locate[i] + 1], argv + pipe_locate[i] + 1);
            exit(0);
        }

		//親プロセス。つなげ終わったパイプを閉じる
        else if (i > 0) {
            close(pfd[i - 1][0]); close(pfd[i - 1][1]);
        }
    }
    int status;

	// このwait意味ある？？
    for (i = 0; i < pipe_count + 1; i++) {
        wait(&status);
    }
    return 0;
}