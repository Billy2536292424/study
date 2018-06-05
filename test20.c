// 8二分法解非线性方程算法
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
