#include<stdio.h>
int binary_search(int arr[],int key,int left,int right)
{
	

	
	
	while(left<=right)
	{
		int mid = left+((right-left)>>1);
	
	if(key > arr[mid])
 		{
 			left = mid+1;
 		}
 		else if(key < arr[mid])
 		{
 			right = mid-1;
 		}
 		else
 		{
 			return mid;
 		}
 	}
 	return -1;
 
 }
int main()
{	
	int arr[]={1,2,3,4,5,6,7,8,9,10};
	int key = 4;
	
	int sz = sizeof(arr)/sizeof(arr[0]);
	
	int ret = binary_search(arr,key,0,9);
	
	if(ret==-1)
	{
	printf("找不到\n");
	}
	else
	{
		printf("找到了: %d\n",ret);
	}
	
	return 0;
}
