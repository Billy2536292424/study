 //9复化梯形求积公式求积分
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
