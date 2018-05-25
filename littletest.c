#include <iostream>
using namespace std;
int main()
{
	int num = 0;
	int count = 0;
	int ret = 0;
	int i = 0;
	int arr[4] = {0};
	do 
	{
		cout<<"input the number:";
		cin>>num;
	} while (num>9999);
	cout<<"逆序输出\n";
	while(num%10!=0)
	{
		ret = num % 10;
		num = num / 10;
		count++;
		arr[i] = ret;
		i++;
		cout<<ret<<'\n';
		
	}
	cout<<"位数："<<"count="<<count<<'\n';
	cout<<"正序输出：\n";
	for (i=count-1; i>=0; i-- )
	{
		cout<<arr[i]<<'\n';
	}
	
	return 0;
}
#include<iostream>
using namespace std;
int main()
{
	const int n = 5;
	int a[n],i,tmp;
	cout<<"enter array a:\n";
	for(i=0; i<n; i++)
	{
		cin>>a[i];
		
	}
	cout<<"array a:\n";
	
	for (i=0;i<n;i++)
	{
		cout<<a[i]<<' ';

	}
	for (i=0; i<=n/2; i++)
	{
		tmp = a[i];
		a[i] = a[n-i-1];
		a[n-i-1] =tmp; 

	}
	cout<<'\n';
	cout<<"Now,array a:\n";
	for (i=0; i<n; i++)
	{
		cout<<a[i]<<' ';
		
	}
	return 0;

}

#include<iostream>
using namespace std;
int main()
{
	int i,j,upper,lower,digit,space,other;
	char text[3][80];
	upper = lower = digit = space = other = 0;
	for(i=0; i<3; i++)
	{
		cout<<"please input line"<<i+1<<'\n';
		gets(text[i]);
		for (j=0; j<80&&text[i][j]!='\0';j++ )
		{
			if (text[i][j]>='A'&&text[i][j]<='Z')
			{
				upper++;
			}
			else if (text[i][j]>='a'&&text[i][j]<='z')
			{
				lower++;
				
			}
			else if (text[i][j]>='0'&&text[i][j]<='9')
			{
				digit++;

			}
			else if (text[i][j]==' ')
			{
				space++;
			}
			else
			{
				other++;
			}
		}

	}
			
		cout<<"upper case:"<<upper<<'\n';
		cout<<"lower case:"<<lower<<'\n';
		cout<<"digit     :"<<digit<<'\n';
		cout<<"space     :"<<space<<'\n';
		cout<<"other     :"<<other<<'\n';
		return 0;
}
