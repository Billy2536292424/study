#include <stdio.h>
 #include<stdlib.h>
 #include <time.h>
 #include <string.h>
void replace_space(char arr[], int len)
 {
 	int i = 0;
 	int j = 0;
 
 	int count = 0;
 	int new_len = 0;
 	for(i=0; i<len; i++)
 	{
 		if (arr[i] == ' ')
 		{
 			count++;
 		}
 	}
 	new_len = 2*count +len;
 	i = len;
 	j = new_len;
 	for (; (i != j)&&(i>=0); i--)
 	{
 		if (arr[i] == ' ')
 		{
 			arr[j--] = '0';
 			arr[j--] = '2';
 			arr[j--] = '%';
 			
 		}
 		else
 		{
 			arr[j] = arr[i];
 			
 			j--;
 		}
 	}
 }
 int main()
 {
 	char arr[100] = {"we are happy"};
 	int len = strlen(arr);
 	replace_space(arr, len);
 	printf("%s\n",arr);
 	return 0;
 	
 }

