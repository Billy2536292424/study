#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
typedef struct node node;
struct node
{
	node *next;
	node (*fun)(void);
};
node *head = NULL;
void headput (int data)
{
if(head == NULL)
{
	node *p = malloc(sizeof(node));
	head->next = p;
	p->next = NULL;
	p->fun = myf;
}
else
{

	node *p = malloc(sizeof(node));
	head->next = p;
	p->next = NULL;
	p->fun = myf;
}
int myexit(int d)
{

	node*p = head;
	while(p!=NULL)
{
	p->func();
	p= p->next;
}
	_exit(d);
	return d;

}


void exitreg()
{
	printf("11111\n");	
}

void exitreg2()
{
	printf("22222\n");	
}
void f1(void){printf("f1\n");}
int main()

{
	atexit(f1);
	myexit();
	printf("hello1");
	printf("hello2");
	printf("hello3");
	
//	exit(0);
}
