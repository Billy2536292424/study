#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<semaphore.h>
#define ERR_EXIT(m) \
    do\
    {\
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)
#define CUSTOMERS_COUNT 1
#define PRODUCERS_COUNT 1
#define BUFFSIZE 10

int g_buffer[BUFFSIZE];

unsigned short in = 0;
unsigned short out = 0;
unsigned short produce_id = 0;
unsigned short consume_id = 0;


sem_t g_sem_full;
sem_t g_sem_empty;
pthread_mutex_t g_mutex;

pthread_t g_thread[CUSTOMERS_COUNT+PRDUCERS_COUNT];

void * consume(void *arg)
{
    int i;
    int num =*(int *)arg;
    free(arg);

    while(1)
    {
        printf("%d wait buffer not empty\n", num);
        sem_wait(&g_sem_empty);
        pthread_mutex_lock(&g_mutex);

        for(i=0; i<BUFFSIZE; i++)
        {
            printf("%02d",i);
            if(g_buffer[i]==-1)
                printf("%s","null");
            else
                printf("%d", g_buffer[i]);
            if(i==out)
                printf("\t<--consume");
            printf("\n");
        }
        consume_id = g_buffer[out];
        printf("%d begin consume product %d\n", num , consume_id);
        g_buffer[out] = -1;
        out = (out + 1)% BUFFSIZE;
        printf("%d end consume prduct %d",num, consum_id);
        pthread_mutex_unlock(&g_mutex);
        sem_post(&g_sem_full);
        sleep(1);
    }
    return NULL;
}
void * produce(void * arg)
{
    int i;
    int num = *(int *)arg;
    free(arg);
}
