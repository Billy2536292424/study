#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>
#include<sys/wait.h>
void do_action(char*argv[])
{
	if(fork()==0)
{
	execvp(argv[0],argv);
}
	else
	wait(NULL);
}
void do_parse(char *buf)
{
	char *argv[8];
	int argc = 0;
	int status = 0;
	int i = 0;
	for(i=0; buf[i] !='\0'; i++)
{
	if(!isspace(buf[i])&&status ==0){
	argv[argc++] = buf+i;
	status = 1;
}
	else if(isspace(buf[i])){
	buf[i] = 0;
	status = 0;

}
}
argv[argc] = NULL;
do_action(argv);
}	


int main(void)
{
	char buf[1024] = {};
	while(1)
{
	printf(":>");
	memset(buf,0x00, sizeof(buf));
	scanf("%[^\n",buf);
	scanf("%*c");
	if(strcmp(buf,"exit")==0)
	break;
	do_parse(buf);
}
}
