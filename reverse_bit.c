#include <stdio.h>
 #include <math.h>
 unsigned int  reverse_bit(unsigned int value)
 {
 	int i = 0;
 	unsigned int ret = 0;
 	for (i=0; i<32;i++)
 	{
 		
 		 ret +=  ((value>>i)&1)*(unsigned int)pow(2, 31-i);
 	}
 	return ret;
 }
 int main()
 {
 	int num = 25;
 	unsigned int ret = reverse_bit(num);
 	printf("%u",ret);
 
 	return 0;
 }
