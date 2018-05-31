#include<iostream>
 #include <iomanip>
 using namespace std;
 const int n = 5;
 struct student 
 {
 	char num[6];
 	char name[8];
 	int score[4];
 
 }stu[n];
 int main()
 {
 	void print(student stu[]);
 	int i,j;
 	for (i=0; i<n; i++)
 	{
 		cout<<"input scores of student "<<i+1<<":";
 		cout<<"N0.:";
 		cin>>stu[i].num;
 		cout<<"name: ";
 		cin>>stu[i].name;
 		for (j=0; j<3; j++)
 		{
 			cout<<"score"<<j+1<<":";
 			cin>>stu[i].score[j];
 
 		}
 		
 	}
 	print(stu);
 
 	return 0;
 }
 void print(student stu[])
 {
 	int i,j;
 	cout<<"No.          name          score1          score2          score3";
 	for (i=0; i<n; i++)
 	{
 		cout<<stu[i].num<<" "<<setw(10)<<stu[i].name<<"          ";
 		for (j=0; j<3; j++)
 		{
 			cout<<setw(3)<<stu[i].score[j]<<"          ";
 		}
 	}
 }
