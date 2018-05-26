#include<stdio.h>//杀手是谁
int main()
{

	char killer = 0;
	for(killer='A';killer<='D';killer++)
	{
	if(3 == (killer!='A')+(killer=='C')+(killer=='D')+(killer!='D'))
	{
	printf("killer=%c\n",killer);
	}
	}
	return 0;
}
