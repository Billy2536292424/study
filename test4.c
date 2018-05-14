#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<errno.h>
#include<string.h>
int main(void)
{
	pid_t pid = fork();
	if(pid == -1)
	{
		perror("fork()");
		exit(1);
	}
	if(pid == 0)
	{
		//child
		sleep(20);
		
		exit(10);
			
	}
	else
	{	
		//parent
		int st;
		int ret = wait(&st);
		if(ret > 0 && (st&0x7F)==0)
		{
			printf("child exit code: %d\n",(st>>8)&0xFF);
		}
		else if(ret > 0)
		{
			printf("sig code: %d\n", st&0x7F);
		}
	}	
	return 0;
}
