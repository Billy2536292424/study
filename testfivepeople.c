#include<stdio.h>//一个简单的推理题
int main()
{	int arr[5] = {0};
    int A = 0;
	int B = 0;
	int C = 0;
	int D = 0;
	int E = 0;
	for(A=1;A<=5;A++)
	
	for(B=1;B<=5;B++)
	
	for(C=1;C<=5;C++)
	
	for(D=1;D<=5;D++)
	
	for(E=1;E<=5;E++)
	{
		if((B == 1) + (A == 3) == 1 &&\
		(B == 2) + (E == 4) == 1 &&\
		(C == 1) + (D == 2) == 1 &&\
		(C == 5) + (D == 3) == 1 &&\
		(E == 4) + (A == 1) == 1)
	{
	int val = 0;
	int flag = 0;

	val |=(1<<(A-1));
	val |=(1<<(B-1));
	val |=(1<<(C-1));
	val |=(1<<(D-1));
	val |=(1<<(E-1));

	while(val)
	{
	if(val%2==0)
	{
	flag = 0;
	}
	val /=2;
	}
	if(flag == 1)
	{
	printf("a=%d b=%d c=%d d=%d e=%d",A,B,C,D,E);
	}
	}

	}
	
	return 0;
}
