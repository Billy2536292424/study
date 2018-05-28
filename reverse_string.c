 #include<stdio.h>
 #include <string.h>
 void reverse_string(char * string)
 {
 	int len = strlen(string);
 	char tmp = *string;
 	*string = *(string+len-1);
 	*(string+len-1) = '\0';
 	if (strlen(string+1)>1)
 	
 	{
 		reverse_string(string+1);
 	}
 		*(string+len-1) = tmp;
 	
 	
 }
 int main()
 {
 	char arr[] = "abcdef";
 	reverse_string(arr);
 	printf("%s\n",arr);
 	return 0;
 }
