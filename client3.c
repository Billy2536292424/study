#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#define ERR_EXIT(m) do\
{\
perror(m);\
exit(EXIT_FAILURE);\
}while(0)
int main(void)
{
	int wfd = open("mypipe", O_WRONLY);
	if(wfd < 0){
		ERR_EXIT("open");
	}
	char buf[1024];
	while(1){	
		buf[0];
		printf("please enter# ");
		fflush(stdout);
		ssize_t ret = read(0, buf, sizeof(buf)-1);
		if(ret>0){
			buf[ret] = 0;
			write(wfd, buf, strlen(buf));
		}else if(ret<=0){
			ERR_EXIT("read");
		}			
	}
	close(wfd);		
	return 0;
}
