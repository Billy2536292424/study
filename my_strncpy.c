#include <stdio.h>
 void my_strncpy(char *p, char *q, int n)
 {
 	int count = 0;
 	while ((*p++ = *q++)&&(count < n-1))
 	{
 		count++;
 	}
 }
 int main()
 {
 	char a[20] = "abcdeilajdkfjkl";
 	char b[] = "fghijsdfsdfsdfses";
 	my_strncpy( a, b, 4);
 	printf("%s",a);
 	return 0;
 }
