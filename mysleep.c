#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void sig_alrm(int signo)
{}
unsigned int mysleep(unsigned int nsecs)
{
    struct sigaction new,old;
    unsigned int unslept = 0;
    new.sa_handler=sig_alrm;
    sigemptyset(&new.sa_mask);
    new.sa_flags = 0;
    sigaction(SIGALRM,&new, &old);
    alarm(nsecs);
    pause();
    unslept=alarm(0);
    sigaction(SIGALRM, &old,NULL);
    return unslept;
}
int main(void)
{
    while(1)
    {
      //  sleep(5);
        mysleep(5);
        fflush(stdout);
        printf("5 seconds passed\n");
    
    }
    return 0;
}
