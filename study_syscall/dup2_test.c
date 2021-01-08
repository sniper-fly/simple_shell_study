#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	int		file_fd;

	file_fd = open("dup2_test.c", O_RDONLY);
	if (file_fd < 0)
	{
		perror("open");
		close(file_fd);
		exit(1);
	}
	close(0);
	dup2(file_fd, 0);
	close(file_fd);
	execlp("wc", "wc -l", NULL);
}