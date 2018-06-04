//5龙贝格求积分算法
 #include<iostream>
 #include<cmath>
 #define eps 0.000001
 #define B 10
 using namespace std;
 double f(double x)
 {
 	return	(x*sin(x));
 }
 int main()
 {
 	int M=1,n=0,p=0,K=0,i=0,j=0,J=0;
 	double h=0.0,a=0.0,b=0.0,err=1.0,quad=0.0,s=0.0,x=0.0;
 	double R[B][B]={0};
 	const double pi=3.1415926;
 	a=0;
 	b=pi*2;
 	h=b-a;
 	n=4;
 	cout<<"求解函数y=x*sin(x)在(0,2π)上的龙贝格矩阵"<<endl;
 	cout<<"龙贝格矩阵最大行数为"<<n<<endl;
 	cout<<"误差限为"<<eps<<endl;
 	R[0][0]=h*(f(a)+f(b))/2;
 	while(((err>eps)&&(J<n))||(J<4))
 	{
 		J=J+1;
 		h=h/2;
 		s=0;
 		for(p=1;p<=M;p++) 
 		{
 			x=a+h*(2*p-1); 
 			s=s+f(x);
 		}
 		R[J][0]=R[J-1][0]/2+h*s;
 		M=2*M;
 		for(K=1;K<=J;K++)
 		{
 			R[J][K]=R[J][K-1]+(R[J][K-1]-R[J-1][K-1])/(pow(4,K)-1);
 		}
 		err=fabs(R[J-1][J-1]-R[J][K]);
 	}
 	quad=R[J][J];	cout<<"\n龙贝格矩阵为:\n";
 	for(i=0;i<(J+1);i++)
 	{
 		for(j=0;j<(J+1);j++)
 		{
 			cout<<R[i][j]<<"  ";
 		}
 		printf("\n");
 	}
 	cout<<"\n积分值为:quad="<<quad;
 	cout<<"\n误差估计为:err="<<err;
 	cout<<"\n使用过的最小步长:h="<<h<<endl;
 	getchar();
 	return 0;
 }
 6M次多项式曲线拟合
 
 #include<iostream>
 #include<cmath>
 #define N 20
 using namespace std;
 //函数声明
 void inv(double X[N][N],int n,double E[N][N]);
 int main()
 {
 	int n,M,i,j,k;
 	double X[N]={0},Y[N]={0},F[N][N]={0},B[N]={0};
 	double A[N][N]={0},BF[N][N]={0},C[N]={0},E[N][N]={0};
 	cout<<"请先输入待拟合点的个数:";
 	cin>>n;
 	cout<<"\n请输入"<<n<<"个点的X坐标序列:\n";
 	for(i=0;i<n;i++)
 		cin>>X[i];
 	cout<<"\n请输入"<<n<<"个点的Y坐标序列:\n";
 	for(i=0;i<n;i++)
 		cin>>Y[i];
 	cout<<"\n请输入需要拟合的次数:";
 	cin>>M;
 	for(i=0;i<n;i++)
 		for(k=1;k<=M+1;k++)
 			F[i][k-1]=pow(X[i],k-1);
 	//求F的转置
 	for(i=0;i<n;i++)
 	{
 		for(j=0;j<M+1;j++)
 		{
 			BF[j][i]=F[i][j];
 		}
 	} 
 	//计算其转置BF与F的乘
 	for(i=0;i<M+1;i++)
 		for(j=0;j<M+1;j++)
 			for(k=0;k<n;k++)
 				A[i][j]+=BF[i][k]*F[k][j];
 
 	//计算F的转置BF与Y的乘
 	for(i=0;i<M+1;i++)
 		for(j=0;j<n;j++)
 			B[i]+=BF[i][j]*Y[j];
 	//调用inv函数求解矩阵A的逆矩阵E
 	inv(A,n,E);
 
 	//计算A的逆BF与B的乘
 	for(i=0;i<M+1;i++)
 		for(j=0;j<n;j++)
 			C[i]+=E[i][j]*B[j];
 	cout<<"\n拟合后的"<<M<<"次多项式系数为，幂次由高到低：\n";
 	for(i=M;i>=0;i--)
 		cout<<C[i]<<"\t";
 	cout<<"\n拟合后的"<<M<<"次多项式为:\n";
 	cout<<"\nP(x)=";
 	for(i=M;i>=0;i--)
 	{
 		if(i==0)
 		{  if(C[i]>=0)
 		cout<<"+"<<C[i];
 		else
 			cout<<C[i];
 		}
 		else
 		{  if(C[i]>=0)
 		cout<<"+"<<C[i]<<"*x^"<<i;
 		else
 			cout<<C[i]<<"*x^"<<i;
 		}
 	}
 	cout<<endl;
 	return 0;
 }
 //求解任意可逆矩阵的逆
 void inv(double X[N][N],int n,double E[N][N])
 {
 	int i,j,k;
 	double temp=0;
 	for(i=0;i<N;i++)
 	{
 		for(j=0;j<N;j++)
 			if(i==j)
 				E[i][j]=1;
 	}
 	for(i=0;i<n-1;i++)
 	{
 		temp=X[i][i];
 		for(j=0;j<n;j++)
 		{
 			X[i][j]=X[i][j]/temp;
 			E[i][j]=E[i][j]/temp;
 		}
 		for(k=0;k<n;k++)
 		{
 			if(k==i)
 				continue;
 			temp=-X[i][i]*X[k][i];
 			for(j=0;j<n;j++)
 			{
 				X[k][j]=X[k][j]+temp*X[i][j];
 				E[k][j]=E[k][j]+temp*E[i][j];
 			}
 		}
 	}	
 }
 7雅克比迭代
 #include <iostream>
 #include <cmath>
 using namespace std;
 #define delta 0.0000001
 #define n 3
 #define max1 1000
 int main()
 {
 	int i,j,k;
 	double err,norm,A[n][n],B[n],P[n],X[n];
 	cout<<"请输入矩阵A("<<n<<"*"<<n<<")"<<endl;       
 	for (i=0;i<n;i++)
 		for (j=0;j<n;j++)
 			cin>>A[i][j];
 	cout<<"请输入矩阵B("<<n<<"*1)"<<endl;
 	for (i=0;i<n;i++)
 		cin>>B[i];
 	cout<<"请输入矩阵P("<<n<<"*1)"<<endl;
 	for (i=0;i<n;i++)
 		cin>>P[i];
 	for (k=0;k<max1;k++)
 	{
 		for (j=0;j<n;j++)
 		{
 			X[j]=B[j];
 			for (i=0;i<n;i++)
 				X[j]=X[j]-A[j][i]*P[i];
 			X[j]=(X[j]+A[j][j]*P[j])/A[j][j];
 		}
 		norm=0;
 		for (i=0;i<n;i++)
 			norm=norm+pow((X[i]-P[i]),2);
 		norm=pow(norm,0.5);
 		err=fabs(norm);
 		for (i=0;i<n;i++)
 			P[i]=X[i];
 		if (err<delta)
 			goto loop;
 	}
 loop:cout<<"结果X="<<endl;
 	for (i=0;i<n;i++)                                    
 		cout<<X[i]<<endl; }
 8二分法解非线性方程算法
 #include<iostream>
 using namespace std;
 #define eps 0.00000000000001
 double f(double x)
 {
 	return x*x*x+x*x-3*x-3;
 }
 int main()
 {
 	double fa,fb,fc,a,b,c;
 	cout<<"二分法求方程x*x*x+x^2-3*x-3=0的根"<<endl;
 	cout<<"求根区间为(1,2)"<<endl;
 	a=1,b=2;
 	fa=f(a);
 	fb=f(b);
 	while((b-a)>eps)
 	{c=(a+b)/2;
 	fc=f(c);
 	if(fc==0)
 		break;
 	else if(fc*fb<0)
 	{
 		a=c;
 		fa=fc;}
 	else{
 		b=c;
 		fb=fc;}
 	}
 	cout<<"方程的根为:X="<<c<<endl; }
 9复化梯形求积公式求积分
 #include<iostream>
 using namespace std;
 double a[3];
 int main() {
 	double matrap(double xx[], int n);
 	double xx[2];//积分区间
 	int n;//区间的等分数
 	cout << "请输入被积函数的各项系数：" << endl;
 	cout << "    a = "; cin >> a[0];
 	cout << "    b = "; cin >> a[1];
 	cout << "    c = "; cin >> a[2];
 	cout << "请输入积分区间[x0,xn]:   "; cin >> xx[0] >> xx[1];
 	cout << "请输入区间的等分数 n = "; cin >> n;
 	double y = matrap(xx, n);
 	cout << "积分结果为  y = " << y << endl;
 	system("pause");
 	return 0;
 }
 double matrap(double xx[], int n) {
 	double h = (xx[1] - xx[0]) / n, s = 0, x;
 	double fun(double x);
 	int i;
 	for (i = 1; i < n; i++) {
 		x = xx[0] + h*i;
 		s = s + fun(x);
 	}
 	s = h / 2 * (fun(xx[0]) + fun(xx[1]) + 2 * s);
 	return s;
 }
 double fun(double x) {
 	double y = a[0] / (a[1] + a[2] * x*x);
 	return y;
 }
 
 10多项式根的逐步搜索法
 
 #include<iostream>
 #include<iomanip>
 using namespace std;
 //逐步搜索法
 double a[4];//多项式系数矩阵
 int main()
 {
 	double qujian[2], h;
 	void search(double x[], double h);
 	cout << "请输入各项系数：" << endl;
 	cin >> a[0] >> a[1] >> a[2] >> a[3];
 	cout << "请输入搜索区间（a，b）------ ";
 	cin >> qujian[0] >> qujian[1];
 	cout << "请输入搜索步长h ：  ";
 	cin >> h;
 	cout << "有根区间为：" << endl;
 	search(qujian, h);
 	system("pause");
 	return 0;}
 void search(double x[],double h) {
 	double fun(double x);
 	int i, n;
 	n = int((x[1] - x[0]) / h);
 	cout << setw(10) << "a" << setw(10) << "b" << endl;
 	for (i = 0; i < n; i++) {
 		x[0] = x[0] + h;
 		if (fun(x[0])*fun(x[0] + h) <= 0)
 			cout << setw(10) << x[0] << setw(10) << x[0] + h << endl;
 	}
 }
 double fun(double x) {
 	double f;
 	f = a[0] * x*x*x + a[1] * x*x + a[2] * x + a[3];
 	return f;
 }
