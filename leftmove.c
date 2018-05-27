#include <stdio.h>  
#include <stdlib.h>  
#include<assert.h>  
#include<string.h>  
char  *left_move(char *string,int n)  
{  
	assert(string);  
	char *str = string;  
	int len = strlen(str)-1;  
	int i = 0;  
	int j = 0;  
	for (i=0; i < n; i++)  
	{  
		char tem = str[0];//把第一个字符保存到临时变量  

		for (j = 0; j < len; j++)   
		{  
			str[j] = str[j + 1];  
		}  
		str[len] = tem;  
	}  
	return str;  
}  
int main()  
{  
	char arr[] = "ABCDE";  
	int k = 0;  
	printf("before:%s\n", arr);  
	printf("请输入要左旋几个字符:");  
	scanf("%d", &k);  
	left_move(arr, k);  

	printf("after:%s\n",arr);  
	system("pause");  
	return 0;  
}  
