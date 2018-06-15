#define _CRT_SECURE_NO_WARNINGS
 #include <stdio.h>
 #include<stdlib.h>
 #include <time.h>
 #include <string.h>
 void bubble_sort(char *arr[], int sz)
 {
 	int i = 0;
 	int j = 0;
 	for (i=0; i<sz-1; i++)
 	{
 		for(j=0; j<sz-1-i; j++)
 		{
 			if (strcmp(arr[j], arr[j+1])>0)
 			{
 				char *tmp = NULL;
 				tmp = arr[j];
 				arr[j] = arr[j+1];
 				arr[j+1] = tmp;
 			}
 		}
 	}
 
 }
 int main()
 {
 	int i = 0;
 	char *arr[] = {"sangwu","zhangsan","wangliu","anlushan"};
 	int sz = sizeof(arr)/sizeof(arr[0]);
 	bubble_sort(arr, sz);
 	for (i=0; i<sz; i++)
 	{
 		printf("%s\n",arr[i]);
 	}
 	return 0;
 }
