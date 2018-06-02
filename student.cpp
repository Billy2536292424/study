#include<iostream>
 using namespace std;
 class Student
 {
 public:
 	Student(int n,float s):num(n),score(s){}
 	void display();
 private:
 	int num;
 	float score;
 
 
 };
 void Student::display()
 {
 	cout<<num<<" "<<score;
 
 }
 int main()
 {
 	Student stud[5]={
 		Student(101,78.5),Student(102,85.5),Student(103,98.5);
 		Student(104,100.0),Student(105,95.5);
 		Student *p = stud;
 		for (int i = 0; i<=2; i++)
 		{
 			p->display();
 			return 0;
 		}
 	}
 }
#include<iostream>
using namespace std;
class Student
{
public:
	Student(int n,float s):num(n),score(s){}
	void change(int n,float s){num = n;score = s;}
	void display(){cout<<num<<" "<<score;}
private:
	int num;
	int score;

};
int main()
{
	Student stud(101,78.5);
	stud.display();
	stud.change(101,80.5);
	stud.display();
	return 0;
}
