#include <iostream>
#include <fstream>
#include <string>
#define NULL 0
using namespace std;
struct student //建立学生结构体
{
	long num;
	string name;
	float chinese[3];
	float english[3];
	float math[3];
	float physical[3];
	float chemistry[3];
	float biology[3];
	student *next;
};
int n;
student *creat(void) //建立链表函数
{
	student *head;
	student *p1,*p2;
	n=0;
	p1=p2=new student; //开辟一个新单元，并使p1,p2指向他
	cout<<"学号:";cin>>p1->num;
	cout<<"姓名:";cin>>p1->name;
	cout<<"语文:";
	cin>>p1->chinese[0]>>p1->chinese[1];
	p1->chinese[2]=(p1->chinese[0]*3/10+p1->chinese[1]*7/10);
	cout<<"英语:";
	cin>>p1->english[0]>>p1->english[1];
	p1->english[2]=(p1->english[0]*3/10+p1->english[1]*7/10);
	cout<<"数学:";
	cin>>p1->math[0]>>p1->math[1];
	p1->math[2]=(p1->math[0]*3/10+p1->math[1]*7/10);
	cout<<"物理:";
	cin>>p1->physical[0]>>p1->physical[1];
	p1->physical[2]=(p1->physical[0]*3/10+p1->physical[1]*7/10);
	cout<<"化学:";
	cin>>p1->chemistry[0]>>p1->chemistry[1];
	p1->chemistry[2]=(p1->chemistry[0]*3/10+p1->chemistry[1]*7/10);
	cout<<"生物:";
	cin>>p1->biology[0]>>p1->biology[1];
	p1->biology[2]=(p1->biology[0]*3/10+p1->biology[1]*7/10);
	head=NULL;
	while(p1->num!=0)
	{
		n=n+1;
		if(n==1) head=p1;
		else p2->next=p1;
		p2=p1;
		p1=new student;
		cout<<"学号:";cin>>p1->num;if(p1->num==0)break;
		cout<<"姓名:";cin>>p1->name;
		cout<<"语文:";
		cin>>p1->chinese[0]>>p1->chinese[1];
		p1->chinese[2]=(p1->chinese[0]*3/10+p1->chinese[1]*7/10);
		cout<<"英语:";
		cin>>p1->english[0]>>p1->english[1];
		p1->english[2]=(p1->english[0]*3/10+p1->english[1]*7/10);
		cout<<"数学:";
		cin>>p1->math[0]>>p1->math[1];
		p1->math[2]=(p1->math[0]*3/10+p1->math[1]*7/10);
		cout<<"物理:";
		cin>>p1->physical[0]>>p1->physical[1];
		p1->physical[2]=(p1->physical[0]*3/10+p1->physical[1]*7/10);
		cout<<"化学:";
		cin>>p1->chemistry[0]>>p1->chemistry[1];
		p1->chemistry[2]=(p1->chemistry[0]*3/10+p1->chemistry[1]*7/10);
		cout<<"生物:";
		cin>>p1->biology[0]>>p1->biology[1];
		p1->biology[2]=(p1->biology[0]*3/10+p1->biology[1]*7/10);
	}
	p2->next=NULL;
	return(head);
}

student *shanchu(student *head,long num) //删除结点（学生数据）函数
{
	student *p1,*p2;
	if(head==NULL) //是空表
	{
		cout<<"list null"<<endl;
		return(head);
	}
	p1=head; //使p1指向第一个结点
	while(num!=p1->num&&p1->next!=NULL)
	{
		p2=p1;
		p1=p1->next;
	} //p1后移一个结点
	if(num==p1->num) 
	{
		if(p1==head) head=p1->next; //若p1指向首结点，将第二个结点地址赋予 head
		else p2->next=p1->next; // 否则将下一个结点地址赋予前一结点的 next
		cout<<"delete:"<<num<<endl;
		n=n-1;
		delete p1;
	}
	else cout<<"cannot find"<<num; //找不到该结点
	return(head);
}
student *xiugai(student *head,long num) //修改结点函数
{   student *p1,*p2;
if(head==NULL)
{
	cout<<"list null"<<endl;
	return(head);
}
p1=head;
while(num!=p1->num&&p1->next!=NULL)
{
	p2=p1;
	p1=p1->next;
}
if(num==p1->num)
{  cout<<endl;
cout<<"which subject do you want to change:"<<endl;
cout<<"1:语文"<<endl;
cout<<"2:英语"<<endl;
cout<<"3:数学"<<endl;
cout<<"4:物理"<<endl;
cout<<"5:化学"<<endl;
cout<<"6:生物"<<endl;
cout<<"please enter the command:";
char zif;
cin>>zif;
if(zif=1)
{
	cin>>p1->chinese[0]>>p1->chinese[1];
	p1->chinese[2]=(p1->chinese[0]*3/10+p1->chinese[1]*7/10);
}
else if(zif=2)
{
	cin>>p1->english[0]>>p1->english[1];
	p1->english[2]=(p1->english[0]*3/10+p1->english[1]*7/10);
}
else if(zif=3)
{
	cin>>p1->math[0]>>p1->math[1];
	p1->math[2]=(p1->math[0]*3/10+p1->math[1]*7/10);
}
else if(zif=4)
{
	cin>>p1->physical[0]>>p1->physical[1];
	p1->physical[2]=(p1->physical[0]*3/10+p1->physical[1]*7/10);
}
else if(zif=5)
{
	cin>>p1->chemistry[0]>>p1->chemistry[1];
	p1->chemistry[2]=(p1->chemistry[0]*3/10+p1->chemistry[1]*3/10);
}
else if(zif=6)
{
	cin>>p1->biology[0]>>p1->biology[1];
	p1->biology[2]=(p1->biology[0]*3/10+p1->biology[1]*7/10);
}
else
cout<<"err!";

cout<<"change: "<<num<<endl;
}
else cout<<"cannot find"<<num;
return(head);
}
student *chaxun(student *head,long num) //查询函数
{
	student *p1,*p2;
	if(head==NULL)
	{
		cout<<"list null"<<endl;
		return(head);
	}
	p1=head;
	while(num!=p1->num&&p1->next!=NULL)
	{
		p2=p1;
		p1=p1->next;
	}
	if(num=p1->num)
	{cout<<"学号:";cout<<p1->num<<endl;
	cout<<"姓名:";cout<<p1->name<<endl;
	cout<<"语文:";
	cout<<"    "<<p1->chinese[0]<<"    "<<p1->chinese[1]<<"    "<<p1->chinese[2]<<endl;
	cout<<"英语:";
	cout<<"    "<<p1->english[0]<<"    "<<p1->english[1]<<"    "<<p1->english[2]<<endl;
	cout<<"数学:";
	cout<<"    "<<p1->math[0]<<"    "<<p1->math[1]<<"    "<<p1->math[2]<<endl;
	cout<<"物理:";
	cout<<"    "<<p1->physical[0]<<"    "<<p1->physical[1]<<"    "<<p1->physical[2]<<endl;
	cout<<"化学:";
	cout<<"  "<<p1->chemistry[0]<<"  "<<p1->chemistry[1]<<"  "<<p1->chemistry[2]<<endl;
	cout<<"生物:";
	cout<<"  "<<p1->biology[0]<<"  "<<p1->biology[1]<<"  "<<p1->biology[2]<<endl;
	}
	else cout<<"cannot find"<<num;
	return(head);
}
student *charu(student *head,student *stud) //插入结点函数
{
	student *p0,*p1,*p2; 
	p1=head; 
	p0=stud; 
	if(head==NULL)
	{
		head=p0;
		p0->next=NULL;
	} 
	else
	{
		while((p0->num>p1->num)&&(p1->next!=NULL))
		{
			p2=p1; 
			p1=p1->next; 
		}
		if(p0->num<=p1->num)
		{
			if(head==p1) head=p0; //插到原来第一个结点之前
			else p2->next=p0;  
			p0->next=p1;
			delete p2;
		}
		else
		{
			p1->next=p0;
			p0->next=NULL;
		} 
		n=n+1;
	} 
	return(head);
}

void print(student *head) //输出函数
{
	student *p;
	cout<<"Now .these"<<n<<"records are:"<<endl;
	p=head;
	if(head!=NULL)
		do
		{
			cout<<"学号:";cout<<p->num<<endl;cout<<"                                     总评成绩";cout<<endl;
			cout<<"姓名:";cout<<p->name<<endl;
			cout<<"语文:";
			cout<<"          "<<p->chinese[0]<<"         "<<p->chinese[1]<<"         "<<p->chinese[2]<<endl;
			cout<<"英语:";
			cout<<"          "<<p->english[0]<<"         "<<p->english[1]<<"         "<<p->english[2]<<endl;
			cout<<"数学:";
			cout<<"          "<<p->math[0]<<"         "<<p->math[1]<<"         "<<p->math[2]<<endl;
			cout<<"物理:";
			cout<<"          "<<p->physical[0]<<"         "<<p->physical[1]<<"         "<<p->physical[2]<<endl;
			cout<<"化学:";
			cout<<"          "<<p->chemistry[0]<<"         "<<p->chemistry[1]<<"         "<<p->chemistry[2]<<endl;
			cout<<"生物:";
			cout<<"          "<<p->biology[0]<<"         "<<p->biology[1]<<"         "<<p->biology[2]<<endl;
			p=p->next;
		}while(p!=NULL);
}
void baocun_wenjian(student *head) //保存到指定文件中
{   
	ofstream outfile("f1.dat",ios::out);
	if(!outfile)
	{
		cerr<<"open error!"<<endl;
		exit(1);
	}
	student *p;
	outfile<<"Now .these"<<n<<"records are:"<<endl;
	outfile<<"         "<<"平时成绩"<<"    "<<"期末成绩"<<"    "<<"总评成绩"<<endl;
	p=head;
	if(head!=NULL)
		do
		{
			outfile<<"学号:";outfile<<p->num<<endl;
			outfile<<"姓名:";outfile<<p->name<<endl;
			outfile<<"语文:";
			outfile<<"          "<<p->chinese[0]<<"    "<<p->chinese[1]<<"    "<<p->chinese[2]<<endl;
			outfile<<"英语:";
			outfile<<"          "<<p->english[0]<<"    "<<p->english[1]<<"    "<<p->english[2]<<endl;
			outfile<<"数学:";
			outfile<<"          "<<p->math[0]<<"    "<<p->math[1]<<"    "<<p->math[2]<<endl;
			outfile<<"物理:";
			outfile<<"          "<<p->physical[0]<<"    "<<p->physical[1]<<"    "<<p->physical[2]<<endl;
			outfile<<"化学:";
			outfile<<"          "<<p->chemistry[0]<<"    "<<p->chemistry[1]<<"    "<<p->chemistry[2]<<endl;
			outfile<<"生物:";
			outfile<<"          "<<p->biology[0]<<"    "<<p->biology[1]<<"    "<<p->biology[2]<<endl;
			p=p->next;
		}while(p!=NULL);
		outfile.close();
}
void menu()
{
	cout<<"**********************************************************************"<<endl;
	cout<<"   ～～～欢迎进入学生成绩管理信息体统～～～                           "<<endl;
	cout<<"**********************************************************************"<<endl;
	cout<<"                                                                      "<<endl;
	cout<<"                         学生成绩管理信息系统                         "<<endl;
	cout<<"                                                                      "<<endl;
	cout<<"**********************************************************************"<<endl;
	cout<<"                         1---新建学生成绩信息                         "<<endl;
	cout<<"                         2---修改当前学生成绩信息                     "<<endl;
	cout<<"                         3---删除当前学生成绩信息                     "<<endl;
	cout<<"                         4---显示当前学生成绩信息                     "<<endl;
	cout<<"                         5---插入当前学生成绩信息                     "<<endl;
	cout<<"                         6---保存学生成绩到磁盘子文件                 "<<endl;
	cout<<"                         7---保存到磁盘文件                           "<<endl;
	cout<<"                         8---退出成绩管理系统                         "<<endl;
	cout<<"**********************************************************************"<<endl;
	cout<<"                                                                      "<<endl;
	cout<<"                                                                      "<<endl;
	cout<<"                                                                      "<<endl;
	cout<<"**********************************************************************"<<endl;
	cout<<"                   ×—×小提示：请选择你要进入的界面，输入相应数字： "<<endl;
	cout<<"**********************************************************************"<<endl;
}

int main()
{
	student *head;
	char ch;
	bool flag=true;
	while(flag)
	{
		menu();
		cin>>ch;
		cout<<"              "<<"平时成绩"<<"    "<<"期末成绩"<<"    ";
		if(ch=='1')
		{
			cout<<"please enter the records:"<<endl;
			head=creat();
		}
		else if(ch=='2')
		{
			long change_num;
			cout<<"please enter the num which you want to change:"<<endl;
			cin>>change_num;
			head=xiugai(head,change_num);
		}
		else if(ch=='3')
		{   
			long del_num;
			cout<<"please enter the num which you want to deleate:"<<endl;
			cin>>del_num;
			head=shanchu(head,del_num);
		}
		else if(ch=='4')
			print(head);
		else if(ch=='5')
		{
			student stu;
			cout<<endl;
			cout<<"学号:";cin>>stu.num;
			cout<<"姓名:";cin>>stu.name;
			cout<<"语文:";
			cin>>stu.chinese[0]>>stu.chinese[1];
			stu.chinese[2]=(stu.chinese[0]*3/10+stu.chinese[1]*7/10);
			cout<<"英语:";
			cin>>stu.english[0]>>stu.english[1];
			stu.english[2]=(stu.english[0]*3/10+stu.english[1]*7/10);

			cout<<"数学:";
			cin>>stu.math[0]>>stu.math[1];
			stu.math[2]=(stu.math[0]*3/10+stu.math[1]*7/10);
			cout<<"物理:";
			cin>>stu.physical[0]>>stu.physical[1];
			stu.physical[2]=(stu.physical[0]*3/10+stu.physical[1]*3/10);
			cout<<"化学:";
			cin>>stu.chemistry[0]>>stu.chemistry[1];
			stu.chemistry[2]=(stu.chemistry[0]*3/10+stu.chemistry[1]*3/10);
			cout<<"生物:";
			cin>>stu.biology[0]>>stu.biology[1];
			stu.biology[2]=(stu.biology[0]*3/10+stu.biology[1]*7/10);
			head=charu(head,&stu);
		}
		else if(ch=='6')
		{
			cout<<"please enter the filename:"<<endl;
			string filename;
			cin>>filename;
			filename = "d:\\"+filename;
			filename += ".txt";
			ofstream outfile(filename.c_str());
			char kemu;
			cout<<"1:语文:"<<endl;
			cout<<"2:英语:"<<endl;
			cout<<"3:数学:"<<endl;
			cout<<"4:物理:"<<endl;
			cout<<"5:化学:"<<endl;
			cout<<"6:生物:"<<endl;
			cout<<"choose the subject:"<<endl;
			cin>>kemu;
			student *p;
			p=head;
			if(head!=NULL)
				do
				{
					outfile<<"         "<<"平时成绩"<<"    "<<"期末成绩"<<"    "<<"总评成绩"<<endl;
					switch(kemu)
					{
					case '1':
						outfile<<"学号:";outfile<<p->num<<endl;
						outfile<<"姓名:";outfile<<p->name<<endl;
						outfile<<"语文:";
						outfile<<"          "<<p->chinese[0]<<"          "<<p->chinese[1]<<"         "<<p->chinese[2]<<endl;
						break;
					case '2':
						outfile<<"学号:";outfile<<p->num<<endl;
						outfile<<"姓名:";outfile<<p->name<<endl;
						outfile<<"英语:";
						outfile<<"         "<<p->english[0]<<"          "<<p->english[1]<<"        "<<p->english[2]<<endl;
						break;
					case '3':
						outfile<<"学号:";outfile<<p->num<<endl;
						outfile<<"姓名:";outfile<<p->name<<endl;
						outfile<<"数学:";
						outfile<<"          "<<p->math[0]<<"         "<<p->math[1]<<"         "<<p->math[2]<<endl;
						break;
					case '4':
						outfile<<"学号:";outfile<<p->num<<endl;
						outfile<<"姓名:";outfile<<p->name<<endl;
						outfile<<"物理:";
						outfile<<"         "<<p->physical[0]<<"         "<<p->physical[1]<<"         "<<p->physical[2]<<endl;
						break;
					case '5':
						outfile<<"学号:";outfile<<p->num<<endl;
						outfile<<"姓名:";outfile<<p->name<<endl;
						outfile<<"化学:";
						outfile<<"         "<<p->chemistry[0]<<"        "<<p->chemistry[1]<<"         "<<p->chemistry[2]<<endl;
						break;
					case '6':
						outfile<<"学号:";outfile<<p->num<<endl;
						outfile<<"姓名:";outfile<<p->name<<endl;
						outfile<<"语文:";
						outfile<<"         "<<p->biology[0]<<"        "<<p->biology[1]<<"        "<<p->biology[2]<<endl;
						break;
					}
					p=p->next;
				}while(p!=NULL);
				outfile.close();}
		else if(ch=='7')baocun_wenjian(head);
		else if(ch=='8')
		{
			cout<<"exist......"<<endl;
			flag=false;
			break;
		}
	}
	return 0;
}


