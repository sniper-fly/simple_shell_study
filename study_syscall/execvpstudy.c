#include <unistd.h>

int		main(void)
{
	char *args[] = {"ls", "-l", NULL};

	execvp("ls", args);
}