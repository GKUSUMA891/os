#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
int i;
void *numbers(void *ptr)
{
    while(i<=10)
  {
    sleep(1);
    printf("%d ",i);
    i++;
   }
}
int main()
{
    pthread_t thread;
    pthread_create(&thread,NULL,&numbers,NULL);
    //thread_create(&thread[2],NULL,&)
    pthread_join(thread,NULL);
    printf("\n");
}

