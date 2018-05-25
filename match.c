#include<stdio.h>
int main()
{
	char ch = 0;
	int count = 0;
	while((ch=getchar())!=EOF)
	{
		if((ch=="}")&&(count==0))
	{
		printf("不匹配\n");
		return 0;

	}
		if(ch=='{')
		{
			count++;
	}
		else if(ch=='}')
		{
			count--;
		}
		
	}
		if(count==0)
		{
			printf("匹配\n");
		}
		else
		{
			printf("不匹配\n");
		}
			


	return 0;
}
