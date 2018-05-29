#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
using namespace std;
int main()
{
	void swap(char *,char *);
	char str1[20],str2[30],str3[20];
	cout<<"input three line:";
	gets(str1);
	gets(str2);
	gets(str3);
	if (strcmp(str1,str2)>0) 
	{
		swap(str1, str2);
	}
	if (strcmp(str1,str3)>0) 
	{
		swap(str1, str3);
	}
	if (strcmp(str2,str3)>0) 
	{
		swap(str2, str3);
	}
	
	cout<<"Now ,the order is:";
	cout<<str1<<str2<<str3;

	return 0;
}
void swap(char *p1,char *p2)
{
	char p[20];
	strcpy(p,p1);
	strcpy(p1,p2);
	strcpy(p2,p);
}
