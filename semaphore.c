#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

/*
This program provides a possible solution for first readers writers problem using mutex and semaphore.
I have used 5 readers and 5 producers to demonstrate the solution. You can always play with these values.
*/

sem_t wrt;
pthread_mutex_t mutex;
int cnt = 0;
int numreader = 0;

void *writer(void *wno)
{   
    sem_wait(&wrt);
    cnt = cnt+500;
    sleep(1);
    printf("Writer %d modified cnt to %d and id %d\n",(*((int *)wno)),cnt,gettid());
    sem_post(&wrt);

}

void *reader(void *rno)
{   
    
   
   
     sem_wait(&wrt); 
    
    sleep(1);
    cnt = cnt-500;
    // Reading Section
    printf("Reader %d: read cnt as %d and  id %d\n",*((int *)rno),cnt,gettid());
    

      sem_post(&wrt); 
}








int main()
{   

    pthread_t read[5],write[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&wrt,0,1);

    int a[10] = {1,2,3,4,5}; //Just used for numbering the producer and consumer

    for(int i = 0; i < 5; i++) {
        pthread_create(&read[i], NULL, (void *)reader, (void *)&a[i]);
    
        pthread_create(&write[i], NULL, (void *)writer, (void *)&a[i]);
    }

    for(int i = 0; i < 5; i++) {
        pthread_join(read[i], NULL);
    }
    for(int i = 0; i < 5; i++) {
        pthread_join(write[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
    
}

