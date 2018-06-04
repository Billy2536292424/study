//4三次样条插值算法（压紧样条）
 #include<iostream>
 #include<iomanip>
 using namespace std;
 #define N 100//所需定义数组的统一长度
 int n, m;//n为节点向量的个数，m为插值点的个数
 int main() {//三阶样条插值
 	//本算法中所有数组均以[1]开始存放值
 	int i;
 	double x[N] = { 0 }, y[N] = { 0 }, dy[N] = { 0 }, inter[N] = { 0 }, final[N];
 	//x存放节点向量，y存放对应数据，dy存放导数值，xx存放插值点，yy存放最终结果
 	void maspline(double x[], double y[], double dy[], double inter[], double final[]);
 	cout << "请输入节点向量以及插值点的个数：  ";
 	cin >> n >> m;
 	cout << "请输入节点向量： " << endl;
 	for (i = 1; i <= n; i++)cin >> x[i];
 	cout << "请输入对应的数据y：  " << endl;
 	for (i = 1; i <= n; i++)cin >> y[i];
 	cout << "请输入左右两端点的一阶导数值：  ";
 	cin >> dy[1] >> dy[N - 1];
 	cout << "请输入插值点向量：" << endl;
 	for (i = 1; i <= m; i++)cin >> inter[i];
 	maspline(x, y, dy, inter, final);
 	cout << "三次样条插值结果为：" << endl;
 	for (i = 1; i <= m; i++)cout << setw(5) << final[i];
 	cout << endl;
 	system("pause");
 	return 0;
 }
 void maspline(double x[], double y[], double dy[], double inter[], double final[]) {
 	n = n - 1;//现有节点向量的个数-1，即为小区间的个数
 	double hx[N], hy1[N], hy2[N], lambda[N], mu[N], theta[N];
 	void diff(double a[], double b[], int n);
 	void machase(double a[], double b[], double c[], double d[], double x[]);
 	int find(double inter[], double a, int kk[], int command);
 	double a0(double x);
 	double a1(double x);
 	double b0(double x);
 	double b1(double x);
 	diff(x, hx, n + 1); diff(y, hy1, n); diff(y, hy2, n + 1);
 	int i, j;
 	for (i = 1; i < n; i++) {
 		lambda[i] = hx[i + 1] / (hx[i] + hx[i + 1]);
 		mu[i] = 1 - lambda[i];
 		theta[i] = 3 * (lambda[i] * hy1[i] / hx[i] + mu[i]*hy2[i + 1] / hx[i + 1]);
 	}
 	theta[1] = theta[1] - lambda[1] * dy[1];
 	theta[n - 1] = theta[n - 1] - lambda[n - 1] * dy[N - 1];
 	double tows[N];
 	for (i = 0; i < N; i++)tows[i] = 2;
 	machase(lambda, tows, mu, theta, dy);//追赶法解三对角方程组
 	dy[n + 1] = dy[N - 1];//将dyn放入正确位置
 	for (i = 1; i < n + 2; i++)cout << setw(10) << dy[i];
 	double xbar[N];
 	int t = 0, kk[N];
 	for (i = 1; i <= n; i++) {
 		t = 0;
 		if (i == 1)
 			t = find(inter, x[2], kk, 1);	
 		else if (i == n)
 			t = find(inter, x[n], kk, 2);
 		else {
 			double a = x[i], b = x[i + 1];
 			for (j = 1; j <= m; j++)
 				if (inter[j] > a&&inter[j] <= b) {
 					t++;
 					kk[t] = j;
 				}
 		}
 		for (j = 1; j <= t; j++) {
 			xbar[j] = (inter[kk[j]] - x[j]) / hx[j];
 			final[kk[j]] = a0(xbar[j])*y[j] + a1(xbar[j])*y[i + 1] + hx[j] * b0(xbar[j])*dy[j] + hx[j] * b1(xbar[j])*dy[i + 1];
 		}
 	}
 }
 int find(double xx[], double a, int kk[], int command) {
 	int i, k = 0;
 	if (command == 1) {//
 		for (i = 1; i <= m; i++)
 			if (xx[i] <= a) {
 				k++;
 				kk[k] = i;
 			}
 	}
 	else if (command == 2) {
 		for (i = 1; i <= m; i++)
 			if (xx[i] > a) {
 				k++;
 				kk[k] = i;
 			}
 	}
 	return k;
 }
 void diff(double a[], double b[], int nn) {
 	//以此函数实现matlab中diff的功能，a为diff(a)，b为结果值的存放数组，n为数组a中有值的个数
 	int i;
 	for (i = 1; i < nn; i++)b[i] = a[i + 1] - a[i];}
 void machase(double a[], double b[], double c[], double d[], double x[]) {
 	//以此函数实现追赶法解方程组，x为结果值存放的数组
 	//由于在本程序中，结果值最后要在前面和后面分别加上两一阶导数值，故对此程序稍作修改，从[2]开始存放
 	int i, nn = n - 1;
 	for (i = 2; i <= nn - 1; i++) {
 		b[i] = b[i] - a[i] * c[i - 1] / b[i - 1];
 		d[i] = d[i] - a[i] * d[i - 1] / b[i - 1];
 	}
 	x[nn + 1] = d[nn] / b[nn];
 	for (i = nn - 1; i > 0; i--) {
 		x[i + 1] = (d[i] - c[i] * x[i + 2]) / b[i];
 		cout << "  i " << x[i + 1];	}
 	cout << endl;
 }
 double a0(double x) {
 	double y = 2 * x*x*x - 3 * x*x + 1;
 	return y;
 }
 double a1(double x) {
 	double y = -2 * x*x*x + 3 * x*x;
 	return y;
 }
 double b0(double x) {
 	double y = x*x*x - 2 * x*x + x;
 	return y;
 }
 double b1(double x) {
 	double y = x*x*x - x*x;
 	return y;
 }
 
