#include<stdio.h>
char *my_strrchr(const char *p, const char *q)
{
	char *start = NULL;
	char *last = (char*)p;
	int i = 0;
	while (*p && *q)
	{
		start = (char*)p;
		while((p)&&(q[i])&&(*p == q[i]))
		{
			p++;
			i++;
		}
		if (q[i] == '\0')
		{
			last = start;
		}
		
		p = start + 1;
		i = 0;

	}
	if (*p == '\0')
	{
		return last;
	}
	else
	{
		return NULL;
	}
	
}
int main()
{
	char a[] = "hashdhyshuhysahhhyshkhyshnkhjk";
	char *p = my_strrchr(a, "ys");
	printf("%s",p);
	return 0;
}
