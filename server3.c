#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#define ERR_EXIT(m) do{\
perror(m);\
exit(EXIT_FAILURE);\
}while(0)
int main(void)
{
	umask(0);
	if(mkfifo("mypipe", 00644) < 0)
	{
		ERR_EXIT("mkfifo");	
	}
	int rfd = open("mypipe", O_RDONLY);
	if(rfd < 0){
		ERR_EXIT("open");
	}
	char buf[1024];
	while(1){
		buf[0] = 0;
		printf("please wait ...\n");
		ssize_t ret = read(rfd, buf, sizeof(buf)-1);
		if(ret > 0){
			buf[ret - 1] = 0;
			printf("client say#%s\n:", buf);
		}else if(ret == 0){

			printf("client quit,exit  now\n");
			exit(EXIT_SUCCESS);
		}else{
			ERR_EXIT("read");
		}
	}
	close(rfd);
	return 0;
}
