#include <stdio.h>
 #include <string.h>
 #include <assert.h>
 
 char change(char *arr, int n)
 
 {
 		
 	int i = 0;
 	int len = strlen(arr);
 
 	while (n)
 	{
 		char tmp = arr[0];
 		for (i=0; i<len-1; i++)
 		{
 			arr[i]=arr[i+1];
 		}
 		arr[i] = tmp;
 		n--;
 	}
 
 	return *arr;
 }
 int main()
 {
 	int k = 0;
 	char arr[] = "ABCD";
 	int n = 0;
 	
 	
 
 
 	change(arr, 5);//左旋次数为1
 	printf("%s\n",arr);
 	return 0;
 }
