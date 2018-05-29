#include <stdio.h>
int find(char *str)
{
	unsigned char arr[256] = {0};
	char *tmp = str;
	while (*tmp)
	{
		arr[*tmp]++;
		tmp++;
	}
	tmp =str;
	while (*tmp)
	{
		if (arr[*tmp] == 1)
		{
			return *tmp;
		}
		tmp++;

	}
	return -1;
}
int main()
{
	char *p ="abaccdeff";
	char ret = {0};
	ret = find(p);
	printf("%c\n",ret);

	return 0;
}
