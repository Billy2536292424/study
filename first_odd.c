 #define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include <string.h>
 void show(int arr[], int len)
 {
 	int i = 0;
 	for (i=0; i<len; i++)
 	{
 		printf("%d ",arr[i]);
 	}
 	printf("\n");
 }
 int* first_odd(int arr[], int len)
 {
 	int i = 0;
 	int j = 0;
 	int count1 = 0; 
 	int count2 = 0;
 	int odd[10] = {0};
 	int even[10] = {0};
 	for (i=0; i<len; i++)
 	{
 			if ((arr[i]&1) == 0)
 			{
 				even[count1] = arr[i];
 				count1++;
 			}
 			else
 			{
 				odd[count2] = arr[i];
 				count2++;
 			}
 		
 		
 	}
 	
 
 	for (i=0; i<count2; i++)
 	{
 		arr[i] = odd[i];
 		
 		
 	}
 	for (j=0; j<count1; j++)
 	{
 		arr[i+j] = even[j];
 	}
 	return arr;
 
 }
 int main()
 {
 	int *p = NULL;
 	int arr[10] = {0};
 	int i = 0;
 	srand((unsigned)time(NULL));
 	for(i=0; i<10; i++)
 	{
 		arr[i] = rand()%100;
 	}
 	show(arr, 10);
  	p = first_odd(arr, 10);
  	show(p, 10);
 
 	return 0;
 }
