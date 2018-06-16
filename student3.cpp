#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  //包含对输入，输出流操作的基本信息
#include<conio.h>      //控制台输入，输出
#include<iomanip>   //使用格式化输入输出
#include<stdio.h>      //标准输入输出
#include<string.h>    //字符串处理函数
#include<stdlib.h>   //宏和通用工具函数
#include<fstream>    //用于用户管理的文件的输入输出操作
using namespace std;
class Student          //学生类的定义
{
private:
	char name[20];//姓名
	char sex[6];//性别
	int number;//学号
	int score[7];//各科成绩分别为0-5，6表示平时成绩
	int total;//成绩之和
	int average;//平均分
	int general;//总评分
public:
	Student();    //构造函数，用来对学生的数据初始化及保存学生数据
	void add();//添加学生信息函数
	void output();//输出学生信息函数
	void find();//查找学生信息函数
	void modify();//修改学生信息函数
	void deleted();//删除学生信息函数
	void save();//保存学生信息并写入文件函数
	void load();//打开写有学生信息的文件的函数
	Student&operator=(Student&T);//重载“=”运算符
	friend istream&operator>>(istream&scin,Student&s1);//"重载“>>”运算符"
	friend ostream&operator<<(ostream&scout,Student&s2);//重载"<<"运算符
};
void menu()//系统菜单
{cout<<"\n\n\n\n\n";
cout<<"                 ***************学生成绩管理系统************"<<endl;
cout<<"                  * ** *       1.学生信息录入        * ** *"<<endl;
cout<<"                  * ** *       2.浏览学生信息        * ** *"<<endl;
cout<<"                  * ** *       3.查询学生信息        * ** *"<<endl;
cout<<"                  * ** *       4.修改学生信息        * ** *"<<endl;
cout<<"                  * ** *       5.删除学生信息        * ** *"<<endl;
cout<<"                  * ** *       6.数据存入文件        * ** *"<<endl;
cout<<"                  * ** *       7.文件读出数据        * ** *"<<endl;
cout<<"                  * ** *         8.退出系统          * ** *"<<endl;
cout<<"\n\n\t请输入所需要的操作号：";
}
Student stu[200];//定义200个学生对象，以保证所有人能录入
int n=0;
void Student::add()//类外定义录入学生信息函数
{
	char flag='Y';//设置输入判断字符
	while(toupper(flag)=='Y')//toupper的功能是将小写英文字母转换为对应的大写字母，否则返回原来的值
		{
			cin>>stu[n];//重载后的输入运算
			n++;
			cout<<"请问要继续录入吗？（请输入y或n）";
			cin>>flag;
			if(toupper(flag)!='Y')//判断要继续输入与否
			{	
				if(toupper(flag)=='N'){break;}
				else
				{
					cout<<"输入错误，请重新输入：";
					cin>>flag;
				}
			}
		}
}
void Student::output()//类外定义输出函数
{
	if(n!=0)
	{
		int t;
		cout<<"-------------------------------------------------------------------------"<<endl;
		cout<<"  学号     姓名  性别  语文  数学  英语  物理  化学  生物  平时成绩  总评"<<endl;
		cout<<"-------------------------------------------------------------------------"<<endl;
		for(t=0;t<n;t++)
		{
			cout<<stu[t];
		}//重载后的输出运算，按照定义可以输出对象的各个成员，同时保留输出的缘由功能
	}

}
void Student::find()//类外定义查找学生数据函数
{
	int f3=0;
	char n1[20];
	Student temp;
	cout<<endl;
	cout<<"请输入您要查找的学生姓名：";
	cin>>n1;
	for(int j=0;j<n;j++)
	{
		if(strcmp(stu[j].name,n1)==0)//字符串比较函数
			{
				temp=stu[j];
				f3=1;
			}
	}
	if(f3==0)
	cout<<"对不起，没有您要查找的学生"<<endl;
	else
	{
		cout<<"-------------------------------------------------------------------------"<<endl;
		cout<<"  学号     姓名  性别  语文  数学  英语  物理  化学  生物  平时成绩  总评"<<endl;
		cout<<"-------------------------------------------------------------------------"<<endl;
		cout<<setw(5)<<temp.number<<setw(6)<<temp.name<<setw(6)<<temp.sex<<setw(6)<<temp.score[0]
		<<setw(6)<<temp.score[1]<<setw(6)<<temp.score[2]<<setw(6)<<temp.score[3]<<setw(6)<<temp.score[4]
		<<setw(6)<<temp.score[5]<<setw(6)<<temp.score[6]<<setw(9)<<temp.general<<endl;
	}

}
void Student::modify()//类外定义您要修改的学生信息的函数
{
	int f4=0;int t;char n2[50];
	cout<<endl;
	cout<<"请输入您要修改的学生姓名：";
	cin>>n2;
	for(int j=0;j<n;j++)
	{
		if(strcmp(stu[j].name,n2)==0)//字符串比较函数，对比输入的字符串是否和已有的数据相同
		{
			t=j;f4=1;
		}
	}
	if(f4==0)
		cout<<"对不起，没有您要修改的学生"<<endl;
	else
	{
		cout<<"请输入修改后的学生学号：";//重新输入所有需要修改的数据
		cin>>stu[t].number;
		cout<<"请输入修改后的学生姓名：";
		cin>>stu[t].name;
		cout<<"请输入修改后的学生性别：";
		cin>>stu[t].sex;
		cout<<"请输入修改后的学生语文成绩：";
		cin>>stu[t].score[0];
		cout<<"请输入修改后的数学成绩：";
		cin>>stu[t].score[1];
		cout<<"请输入修改后的英语成绩：";
		cin>>stu[t].score[2];
		cout<<"请输入修改后的物理成绩：";
		cin>>stu[t].score[3];
		cout<<"请输入修改后的化学成绩：";
		cin>>stu[t].score[4];
		cout<<"请输入修改后的生物成绩：";
		cin>>stu[t].score[5];
		cout<<"请输入修改后的平时成绩：";
		cin>>stu[t].score[6];
		stu[t].total=stu[t].score[0]+stu[t].score[1]+stu[t].score[2]+stu[t].score[3]+
			stu[t].score[4]+stu[t].score[5];
		stu[t].average=stu[t].total/6;
		stu[t].general=(int)(stu[t].score[6]*0.3+stu[t].average*0.7);
		cout<<"修改成功！"<<endl;
	}

}
void Student::deleted()//类外定义删除学生信息函数、
{
	char n3[20];
	bool f5=0;
	char c;
	do
		{
			cout<<endl;
			cout<<"请输入您要删除的学生姓名：";//根据姓名删除学生，也可以设置为根据学号
			cin>>n3;
			for(int i=0;i<n;i++)
				{
					if(strcmp(n3,stu[i].name)==0)//查找对应学生姓名
						{
							f5=1;n--;
							do
								{
									stu[i]=stu[i+1];//直接覆盖数据
									i++;
								}
							while(i<=n);
						}
				}
				if(f5==0)
				cout<<"您要删除的学生不存在";
				cout<<"请问要继续删除吗？（请输入y或n）"<<endl;
				cin>>c;
				if(toupper(c)!='Y'&&toupper(c)!='N')
				{
					cout<<"输入错误！您只能输入Y或N"<<endl;
					cin>>c;
				}
		}
	while(toupper(c)=='Y');

}
void Student::save()//类外定义保存函数
{
	char filename1[20];
	cout<<"请输入文件名：";
	cin>>filename1;//输入自定义文件名
	ofstream fout(filename1,ios::app);//fout是向文件里写入数据
	if(!fout)
	cout<<"文件不能打开！"<<endl;
	else
	{
		for(int i=0;i<n;i++)
			fout<<' '<<stu[i].number<<' '<<stu[i].name<<' '<<stu[i].sex
			<<' '<<stu[i].score[0]<<' '<<stu[i].score[1]<<' '<<stu[i].score[2]
		<<' '<<stu[i].score[3]<<' '<<stu[i].score[4]<<' '<<stu[i].score[5]
		<<' '<<stu[i].score[6]<<' '<<stu[i].total<<' '<<stu[i].average
			<<' '<<stu[i].general;
		cout<<"保存成功"<<endl;
	}
	fout.close();

}
void Student::load()//类外定义读取函数
{
	char filename2[20];
	cout<<"请输入您要读取文件名：";
	cin>>filename2;
	ifstream fin(filename2,ios::in);//fin是向文件里读取数据
	if(!fin)
	cout<<"文件打不开！"<<endl;
	else
		{
			for(int i=0;i++;n=i-1)
			{
				if(fin.eof())break;
				fin>>stu[i].number>>stu[i].name>>stu[i].sex
					>>stu[i].score[0]>>stu[i].score[1]>>stu[i].score[2]
					>>stu[i].score[3]>>stu[i].score[4]>>stu[i].score[5]
					>>stu[i].score[6]>>stu[i].total>>stu[i].average
					>>stu[i].general;
			}
				cout<<"文件已读取成功"<<endl;
		}
		fin.close();

 }
Student&Student::operator=(Student&T)//重载=运算定义
{
	strcpy(name,T.name);
	strcpy(sex,T.sex);
	number=T.number;
	for(int i=0;i<7;i++)
		score[i]=T.score[i];
	total=T.total;
	average=T.average;
	general=T.general;
	return(*this);	
}
ostream&operator<<(ostream&scout,Student&s2)//重载流插入运算符<<运算定义
{
	cout<<setw(5)<<s2.number<<setw(6)<<s2.name<<setw(6)<<s2.sex<<setw(6)
		<<s2.score[0]<<setw(6)<<s2.score[1]<<setw(6)<<s2.score[2]<<setw(6)
		<<s2.score[3]<<setw(6)<<s2.score[4]<<setw(6)<<s2.score[5]<<setw(7)
		<<s2.score[6]<<setw(9)<<s2.general<<endl;
	return scout;
}
istream&operator>>(istream&scin,Student&s1)//重载流提取运算符>>运算定义
{
	cout<<endl;
	cout<<"学号：";
	scin>>s1.number;
	cout<<"姓名：";
	scin>>s1.name;
	cout<<"性别：";
	scin>>s1.sex;
	cout<<"语文：";
	scin>>s1.score[0];
	cout<<"数学：";
	scin>>s1.score[1];
	cout<<"英语：";
	scin>>s1.score[2];
	cout<<"物理：";
	scin>>s1.score[3];
	cout<<"化学：";
	scin>>s1.score[4];
	cout<<"生物：";
	scin>>s1.score[5];
	cout<<"平时成绩：";
	scin>>s1.score[6];
	s1.total=s1.score[0]+s1.score[1]+s1.score[2]+s1.score[3]+s1.score[4]+s1.score[5];
	s1.average=s1.total/6;
	s1.general=(int)(s1.score[6]*0.3+s1.average*0.7);
	return scin;
}
Student::Student()//构造函数
{
	strcpy(name," ");
	strcpy(sex," ");
	number=0;
	for(int i=0;i<7;i++)score[i]=0;
	total=0;
	average=0;
	general=0;
}
int main()//主函数
{
	int choose;
	Student s;
	do
	{
	menu();
	cin>>choose;
	switch(choose)
	{
	case 1:s.add();break;
	case 2:s.output();break;
	case 3:s.find();break;
	case 4:s.modify();break;
	case 5:s.deleted();break;
	case 6:s.save();break;
	case 7:s.load();break;
	default:break;
	}
   }
		while(choose!=0);
		return 0;
}
