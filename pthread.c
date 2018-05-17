#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void *rout(void * arg)
{
    int i;
    for(;;)
    {
        printf("I'm pthread 1\n");
        sleep(1);
    }
}
int main()
{
    pthread_t tid;
    int ret;
    if((ret=pthread_create(&tid, NULL,rout, NULL)) !=0)
    {
        fprintf(stderr,"pthread_create: %s\n", strerror(ret));
        exit(EXIT_FAILURE);
    }
   // pthread_create(&tid, NULL, rout, NULL);
    int i;
    for(;;)
    {
        printf("I'm main pthread\n");
        sleep(1);
    }
    return 0;
}
