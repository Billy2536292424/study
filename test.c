#define _CRT_SECURE_NO_WARNINGS
#include "CommentConvert.h"


void test()
{
	FILE * pfIn = NULL;
	FILE* pfOut = NULL;
	pfIn = fopen("input.c","r");
	if (pfIn == NULL)
	{
		perror("fopen input,c");
		exit(EXIT_FAILURE);
	}
	pfOut = fopen("output.c","w");
	if (pfOut == NULL)
	{
		perror("fopen output,c");
		exit(EXIT_FAILURE);
	}
	CommentConvert(pfIn, pfOut);
	fclose(pfIn);
	fclose(pfOut);

}
int main()
{
	test();
	return 0;
}
