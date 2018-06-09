#include <stdio.h>
 void my_strncat(char *p, const char *q,int n)
 {
 	int count = 0;
 	while (*p)
 	{
 		*p++;
 	}
 	while ((*p++ = *q++)&&(count < n-1))
 	{
 		count++;
 	}
 }
 int main()
 {
 	char a[30] = "hello ";
 	char b[] = "abcdefghijklmnopqrstuvwxyz";
 	int i = 0;
 	my_strncat(a, b, 5);
 	printf("%s",a);
 	return 0;
 }
