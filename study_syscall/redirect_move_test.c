#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int		main(void)
{
	// char buf[1000];

	// for (int i = 0; i < 1000; i++)
	// 	buf[i] = 0;
	write(1, "first\n", 6);
	// read(0, buf, 1000);
	// write(1, buf, strlen(buf));
	// write(1, "\n", 1);
	sleep(3);
	// write(1, buf, strlen(buf));
	write(1, "second\n", 7);
	return (0);
}