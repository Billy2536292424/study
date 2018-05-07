#if 1
#include"comm.h"
int main(void)
{


	int shmid = getShm(4096);
	sleep(1);
	char* addr = (char*)shmat(shmid, NULL, 0);
	sleep(2);
	int i = 0;
	while(i<26){
		addr[i] = 'A'+i;
		i++;
		addr[i] = 0;
		sleep(1);
	}
	shmdt(addr);
	sleep(2);
	return 0;
}
#endif

#if 0 
#include"comm.h"
int main(void)
{
	int msgid = getMsgQueue();
	char buf[1024];
	while(1){
		buf[0] = 0;
		printf("please enter# ");
		fflush(stdout);
		ssize_t s = read(0, buf, sizeof(buf));
		if(s>0){
			buf[s-1] = 0;
			sendMsg(msgid, CLIENT_TYPE, buf);
			printf("send done, wait recv..\n");
		}
		recvMsg(msgid, SERVER_TYPE, buf);
		printf("server# %s\n", buf);
	}
	return 0;
}
#endif
#if 0
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

#endif
