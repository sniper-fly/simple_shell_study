#include <stdio.h>
#include <stdlib.h>
 
#include <sys/types.h>  // fork
#include <unistd.h>     // fork
 
#include <err.h>
#include <errno.h>
 
int
main(int argc, char *argv[])
{
        pid_t   pid;
 
        pid = fork ();
 
        if (-1 == pid)
        {
                err (EXIT_FAILURE, "can not fork");
        }
        else if (0 != pid)
        {
                // parent
                puts ("parents1");
				sleep(1);
                puts ("parents2");
                puts ("parents3");
                puts ("parents4");
                puts ("parents5");
        }
        else
        {
                // child
                puts ("child1");
                puts ("child2");
				sleep(2);
                puts ("child3");
                puts ("child4");
                puts ("child5");
                exit(EXIT_SUCCESS);
        }
 
        exit (EXIT_SUCCESS);
}