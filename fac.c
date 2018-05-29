#include <stdio.h>
 /*int fac(int num)
 {
 	int i = 0;
 	int sub = 1;
 	for (i=1; i<=num;i++)
 	{
 	
 		sub*= i;
 	}
 	return sub;
 }*/
int fac(int num)
{
	if (num==1)
	{
		
		return 1;

	}
	else
	{
		return num*fac(num-1);
	}
	

}
int main()
{
	int n = 0;
	int ret =0 ;

	printf("请输入n>>");
	scanf("%d",&n);
	ret = fac(n);
	printf("%d\n",ret);

	return 0;

}
