#include <stdio.h>
#include <unistd.h>
main()
{
        fork();
	fork();
        printf("Hello PID=%d",getpid());


}
