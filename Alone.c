#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(void)
{
	pid_t pid = fork();
	if(pid < 0)
	{
		perror("fork");
		return 1;
	}
	else if(pid == 0)
	{
		//child
		printf("I am chid,pid: %d\n", getpid());
		sleep(10);
	}
	else{
		//parent
		printf("I am parent,pid: \n", getpid());
		sleep(3);
		exit(0);
	}
	return 0;
}
