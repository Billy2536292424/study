#include<stdio.h>
 #include<assert.h>
 void *my_strcpy(char *pdest,const char *psrc)
 
 {
 	char* ret = pdest;
 	assert(pdest);
 	assert(psrc);
 	while(*pdest++ = *psrc++)
 	{
 		;
 
 // 		*pdest++ = *psrc++;
 // 		*pdest = *psrc;
 // 	
 	}
 	return ret;
 	
 }
int main()
 {
 	
 
 	char a[]="aaaaaaaaaaaa";
 	char *p = "hello world.";
 // 	
 // 	my_strcpy(a,"hello world.");
 	printf("%s\n",my_strcpy(a,p));
	
	return 0;
 }
