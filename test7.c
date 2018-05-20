#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#if 1
int printsigset (sigset_t *set)
{
	int i = 0;
	for(;i<32;i++){
        if(sigismember(set, i))
        {
            putchar('1');
        }else
        {
                
            putchar('0');
            }
    }

        puts("");
}
int main(void)
{
    sigset_t s,p;
    sigemptyset(&s);
    sigaddset(&s, SIGINT);
    sigprocmask(SIG_BLOCK, &s, NULL);
    while(1)
    {
        sigpending(&p);
        printsigset(&p);
        sleep(1);
    }


    return 0;

}
