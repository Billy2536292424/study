#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<assert.h>
int spin(char *p, char *q)
{
	assert((p!=NULL)&&(q!=NULL));
	strncat(p,p,strlen(p));
	if (strstr(p,q)==NULL)
	{
		return 0;
	}
	else
	{
	return 1;
	}
}
int main()
{

	char p[20] = "abcde";
	char q[20] = "cdeab";
	
	int ret = spin(p,q);
	if(0 == ret)
	{
		printf("不是\n");

	}
	else
	{
		printf("是\n");
	}
 
	return 0;
}
