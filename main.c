#include<stdio.h>
#include"add.h"
#include"sub.h"
#include"mul.h"
#include"div.h"
int main(void)
{
	int a = 20 ;

	int b = 10;
	printf("add(20, 10):%d %d %d\n", a, b, add(a, b));
	printf("sub(20, 10):%d %d %d\n", a, b, sub(a, b));
	printf("mul(20, 10):%d %d %d\n", a, b, mul(a, b));
	printf("div(20, 10):%d %d %d\n", a, b, div(a, b));
}
