#include <unistd.h>
#include <string.h>
#include <stdio.h>

int		main(void)
{
	char buf[1000];

	memset(buf, 0, 1000);
	getcwd(buf, 1000);
	printf("cwd = %s\n", buf);
}