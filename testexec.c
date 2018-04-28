#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main()
{
	char *argv[] = {"ls","-l",NULL};
	if(execlp("ls","ls","-l",	NULL) == -1)
	perror("exec"),exit(1);
}
