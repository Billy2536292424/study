#define _CRT_SECURE_NO_WARNINGS
 #include<stdio.h>
 int my_strncmp(char *p, char *q, int n)
 {
 	int count = 0;
 	while ((*p == *q)&&(count < n))
 	{
 		*p++;
 		*q++;
 		count++;
 	}
 	if (*p == *q)
 	{
 		return 0;
 	}
 	else
 	{
 		return (*p-*q);
 	}
 		
 }
 int main()
 {
 	char a[] = "abcdef";
 	char b[] = "abchkhkhk";
 	int ret = strncmp(a, b, 4);
 	/*int ret = my_strncmp(a,b,4);*/
 	if (ret == 0)
 	{
 		printf("a和b相等");
 	}
 	else if (ret > 0)
 	{
 		printf("a比b大");
 	}
 	else
 	{
 		printf("a比b小");
 	}
 	return 0;
 }
