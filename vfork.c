#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int glob = 100;
int main()
{
	pid_t pid  = vfork();
	if(pid == -1)
	{
		perror("vfork");
		exit(1);	
	}
	if(pid == 0)
	{
		//child
		sleep(5);
		glob = 200;
		printf("child glob %d\n", glob);
		exit(0);

	}
	else{
		//parent

		printf("parent glob %d\n", glob);
	}
	return 0;
}
