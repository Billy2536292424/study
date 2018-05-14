//parent read child write
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#define ERR_EXIT(m) do\
{\
perror(m);\
exit(EXIT_FAILURE);\
}while(0)
int main(int argc, char*argv[])
{
	int pipefd[2];
	//create a pipe
	if(pipe(pipefd) == -1){
		ERR_EXIT("pipe error");
	}
	//fork
	pid_t  pid = fork();
	if(pid == -1){
		ERR_EXIT("fork error");
	}
	
	if(pid == 0){
		//child//close read
		close(pipefd[0]);
		//write to pipe
		write(pipefd[1], "hello", 5);
		close(pipefd[1]);
		exit(EXIT_SUCCESS);
		
		
	 }//parent
	//close write
	close(pipefd[1]);
	char buf[10];
	//read
	read(pipefd[0], buf, 10);
	printf("buf =:%s\n", buf);
	

		return 0;
}
