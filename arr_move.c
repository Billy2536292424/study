 #include <stdio.h>
  void arr_move(int arr[], int sz)
  {
  	int *left = arr;
  	int *right = arr+sz-1;
  	while (left<right)
  
  	{
  		while ((left<right)&&(1 == (*left)%2))
  		{
  			left++;
  		}
  		while ((left<right)&&(0 == (*right)%2))
  		{
  			right--;
  		}
  		if (left<right)
  		{
  			int tmp = 0;
  			tmp = *left;
  			*left = *right;
  			*right = tmp;
  		}
  		left++;
  		right--;
  	}
  
  }
  int main()
  {
  	int i = 0;
  	int arr[] = {1,2,3,4,5,6,7,8,9};
  	int sz = sizeof(arr)/sizeof(arr[0]);
  	
  	arr_move(arr,sz);
  	for(i=0; i<sz; i++)
  	{
  		printf("%d ",arr[i]);
  	}
  	
  	return 0;
  }
