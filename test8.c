#include <iostream>
 using namespace std;
 int main()
 {
 	int number[10];
 	void input(int *number);
 	void max_min_value(int *number);
 	void output(int *number);
 
 	input(number);
 	max_min_value(number);
 	output(number);
 
 	return 0;
 }
 void input(int *number)
 {
 	int i;
 	cout<<"input 10 numbers:";
 	for (i=0; i<10; i++)
 	{
 		cin>>number[i];
 
 	}
 
 }
 void max_min_value(int *number)
 {
 	int *max,*min,*p,tmp;
 	max=min=number;
 	for (p=number+1; p<number+1; p++)
 	{
 		if (*p>*max)
 		{
 			max=p;
 		}
 		else if (*p<*min)
 		{
 			min = p;
 		}
 	}
 	
 		tmp = number[0];number[0] = *min;*min = tmp;
 		if (max<number)
 		{
 			max = min;
 		}
 		tmp = number[9];
 		number[9]=*max;
 		*max = tmp;
 
 }
 void output(int *number)
 {
 	int *p;
 	cout<<"Now they are:  ";
 	for (p=number; p<number+10; p++)
 	{
 		cout<<*p<<" ";
 	}
 }
