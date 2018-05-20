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
#endif
#if 0
int main(void)
{
	printf("get pid %d\n", getpid());
	while(1);
	return 0;
}
#endif
#if 0
int main(void)
{
	int count = 1;
	alarm(1);
	for(;1;count++)
{
	printf("count is:%d\n",count);
}
	return 0;
}
#endif



