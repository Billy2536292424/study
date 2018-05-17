#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
void* pthread1(void *arg)
{
    printf("thread1 running...\n");
    int *p=(int*)malloc(sizeof(int));
    *p=1;
    return (void*)p;
}
void* pthread2(void *arg)
{
    
    printf("thread2 running...\n");
    int *p = (int *)malloc(sizeof(int));
    *p=2;
    pthread_exit((void*)p);
}
void* pthread3(void *arg)
{
    while(1)
    {
        
    printf("thread3 running...\n");
    sleep(1);
    }
    return NULL;
}
int main()
{
    pthread_t tid;
    void * ret;


    //pthread1 return
    pthread_create(&tid, NULL, pthread1, NULL);
    pthread_join(tid, &ret);
    printf("thread1 return,thread id %X,return code:%d\n", tid, *(int*)ret);
    free(ret);


    //pthread2 return
    pthread_create(&tid, NULL, pthread2, NULL);
    pthread_join(tid, &ret);
    printf("thread1 return,thread id %X,return code:%d\n", tid, *(int*)ret);
    free(ret);


    //pthread3 return
    pthread_create(&tid, NULL, pthread3, NULL);
    sleep(3);
    pthread_cancel(tid);
    pthread_join(tid, &ret);
    if(ret == PTHREAD_CANCELED)
             printf("thread1 return,thread id %X,return code:PTHREAD_CANCELED\n", tid);
    else
        printf("thread return,thread id %X,return code:NULL\n",tid);
}
