#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	pid_t id = fork();
	if(id<0)
	{
		perror("fork");
		return 1;

	}
	else if(id>0)
	//parent
	{
		printf("[%d] is sleeping...\n", getpid());
		sleep(30);
	}
	else{
	//child
		printf("child[%d] is begin z..\n", getpid());
		sleep(5);
		exit(EXIT_SUCCESS);


		}
		return 0;
}
