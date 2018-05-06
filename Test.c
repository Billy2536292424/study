#include<stdio.h>
int add(int a, int b)
{
	return a+b;
}
int sub(int a, int b)
{
	return a-b;
}
int mul(int a, int b)
{
	return a*b;
}
int div(int a, int b)
{
	return a/b;
}
int main(void)
{
	int a  = 20;

	int b  = 10;
	
	printf("ADD final number:%d\n", add(a, b));
	printf("SUB final number:%d\n", sub(a, b));
	printf("MUL final number:%d\n", mul(a, b));
	printf("DIV final number:%d\n", div(a, b));
	return 0;
}
