#include<stdio.h>
 #include <string.h>
 char *my_strchr(const char* p, const char *q)
 {
 	while ((*p)&&(*p != *q))
 	{
 		*p++;
 	}
 	while (*p == *q)
 	{
 		
 		*p++;
 		*q++;
 		
 	}
 	if (*q=='\0')
 	{
 		return (char*)p;
 
 	}
 	return NULL;
 		
 	
 	
 	
 }
 int main()
 {
 	char a[] = "theworldisverybeautiful";
 	char *p = my_strchr(a, "world");
 	printf("%s",p);
 	return 0;
 }
