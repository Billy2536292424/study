#include<stdio.h>
#include<stdlib.h>
struct oper
{
char name[10];
	int(*pf)(int ,int);
char op;
}ops[] = {
{"add",add,'+'},
{"sub",sub,'-'},
{"mul",mul,'X'},
{"power",power,'^'}
};
void math_main(int argc, char* argv[])
{
int len = sizeof(ops)/sizeof(ops[0]);
int i ;
for(i=0; i<len; i++)

{
if(strcmp(ops[i].name,argv[0])==0)
{
int left = atoi(argv[1]);
int right = atoi(argv[2]);
printf((("%s%c%s"),argv[1],ops[i].op,argv[2],ops[i].pf(left,right));
break;
int right = atoi(argv[2])；
printf((("%s%c%s"),argv[1],ops[i].op,argv[2],ops[i].pf(left,right));
break;

}
}
}
if(i==len)

printf("command not dound");
}
void do_parse(char *buf)
{
	char* argv[8] = {};
int argc = 0;
int status = 0;
int i;
for(i=0; buf[i]!= 0; i++)
{
if(status == 0 && !isspace(buf[i]))
{argv[argc++ = buf + i];
status = 1;}else if(isspace (buf[i])
{
	status = 0;
buf[i] = 0;
}
argv[argc ] = NULL;
math_main(argc, argv);
}
int add(int a, int b)
{
return a+b;
}
int sub(int a, int b)
{
return a-b;
}
int main()
{
char buf[100] = {};
while(1)
{
	printf(">");
	memset(buf, 0,sizeof(buf));
	scanf("%[^\n]"buf);
	scanf("%*c");
	printf("buf=[%s]\n",buf);
}
}
