#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
int main(void)
{
	pid_t pid;
	if((pid=fork())==-1){
	perror("fork"),exit(0);
}
if(pid == 0){
int i = 0;
while(1){
	printf("$$\n");
	sleep(1);
}
exit(1);
}
else{
int st;
pid_t r;
if(r=wait(&st)==-1)
perror("wait");
printf("pid=%d,r=%d,ret = %d\n",pid,r);
if(WIFEXITED(ST){
printf("exit code = %d\n",Wexitstatus(ST));
}
else if(WIFSIGNA(st)){
printf("signal code = %d\n",WT
}
}
