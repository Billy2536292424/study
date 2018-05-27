 #include<stdio.h>
 #include<assert.h>
 int my_strlen(const char *str)
 {
 
 	int count = 0;
 	
 	assert(str != NULL);
 	while (*str != '\0')
 	{
 		count++;
 		str++;
 	}
 	
 	return count;
 }
 int main()
 {
 	char arr[]="aaaaaaaaaaa";
 	int ret = my_strlen(arr);
 	printf("ret=%d\n",ret);
 	
 
 	
 	return 0;
 }
