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
