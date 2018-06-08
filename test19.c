 //多项式根的逐步搜索法
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
