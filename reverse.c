 #include <stdio.h>
 #include <assert.h>
 void reverse(char *left, char *right)
 {
 	while (left<right)
 	{
 		int tmp = 0;
 		assert(left);
 		assert(right);
 		
 		tmp = *left;
 		*left = *right;
 		*right = tmp;
 		left++;
 		right--;
 	}
 }
 void reverse_str(char *left, char *right)
 {
 	char *cur = left;
 	char * start = NULL;
 	reverse(left, right );//翻转整个字符串
	//翻转每一个单词
 	while (*cur)
 	{
 		start = cur;
 		while ((*cur != ' ' )&&(*cur != '\0'))
 
 		{
 			cur++;
 		}
 		reverse(start, cur - 1);
 		if (*cur != '\0')
 		{
 			cur++;
 		}
 
 	}
 }
 int main()
 {
 	char arr[] = "student a am i";
 	reverse_str(arr,arr+sizeof(arr)/sizeof(arr[0])-2);
 	printf("%s\n",arr);
 	return 0;
 }
