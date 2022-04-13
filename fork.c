#include <stdio.h>
#include <unistd.h>
main()
{
        int a;
	for(a=1;a<5;a++)
		fork();
        printf("Hello\n");


}
