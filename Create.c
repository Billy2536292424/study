#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int process_create(int (*func)(), const char* file, char *argv[])
{
	pid_t pid;
	int ret = 0;
	if((pid = fork())==0)
	{
		ret = func(file ,argv);
		if(ret == -1)
		{
			printf("调用execpp失败");
			perror("func");
			_exit(-1);
		}else{
			int st;
			pid_t ret = wait(&st);
			if(ret == -1){
				perror("wait");
				exit(-1);
			}
		}
	}
		return 0;
}
int main(void)
{

	char *argv1[] = {"ls"};
	char *argv2[] = {"ls","-al", "/etc/passwd", 0};
	process_create(execvp, *argv1, argv2);
	
	return 0;
}
