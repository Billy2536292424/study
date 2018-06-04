 #include <iostream>//3经典四阶龙格库塔法解一阶微分方程组
 #include <iomanip>
 using namespace std;
 double x0,y0,x1,x2,a,b,x,s,k1,k2,k3,k4,yn1,h,y1;//yn1表示y(n-1)
 int i;
 //微分方程的函数
 double f(double x, double y) 
 {double r;
 r=x+y;
 return r;
 }
 //4阶龙格-库塔
 double LK( double (*f)(double x, double y), double x0, double y0, double xn, int s )
 //f表示函数的入口地址，x0、y0表示初值，xn表示所求点，s表示计算次数
 {
 	h=(xn-x0)/s;
 	if(s<=0)
 		return(y0);
 	else
 		if(s==1)
 		{
 			k1=f(x0,y0);
 			k2=f(x0+h/2, y0+h*k1/2);
 			k3=f(x0+h/2, y0+h*k2/2);
 			k4=f(x0+h, y0+h*k3);
 			yn1=y0+h*(k1+2*k2+2*k3+k4)/6;
 		}      
 		else
 		{
 			x1=xn-h;
 			y1=LK(f, x0, y0, xn-h,s-1);
 			k1=f(x1,y1);
 			k2=f(x1+h/2, y1+h*k1/2);
 			k3=f(x1+h/2, y1+h*k2/2);
 			k4=f(x1+h, y1+h*k3);
 			yn1=y1+h*(k1+2*k2+2*k3+k4)/6;
 		}
 		return(yn1);
 }
 //主函数
 int main()
 {
 	cout<<"请输入初值x0,y0:";
 	cin>>x0>>y0;//x0,y0分别为和
 	cout<<"请输入区间：";
 	cin>>a>>b;//a和b分别为和.5
 	cout<<"请输入步长：";
 	cin>>s;//步长s=0.1;
 	for(i=0;i<=(b-a)/s;i++)
 	{
 		x=x0+i*s;
 		cout<<setw(10)<<x<<"  "<<setw(10)<<LK(f,x0,y0,x,i)<<endl;
 	}
 	return 0;
 }
