#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int fact_s(n)
{	
	int i = 0; 
	int sum = 0;
	int tmp = 1;
	for(i=1; i<=n; i++)
	{
	tmp *=i;
	sum +=tmp;
	}
	return sum;
 
}
int main()
{	
	int ret = 0;
	int n = 0;
	printf("请输入数字:>");
	scanf("%d",&n);
	ret = fact_s(n);
	printf("ret=%d\n",ret);
	return 0;
}
