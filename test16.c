#include<iostream>
#include <iomanip>
#include<cmath>
#define N 10
using namespace std;
int n;//方程未知量的个数
int main()
{
	float A[N][N+1], x[N];
	int i, j, k, L0;//i,j,k为循环变量，L0为主元所在行
	float max,tmp,c,sum;//max为列主元，tmp为临时变量，c为消元时的比例系数
	cout << "输入方程组中方程的个数：n=";
	cin >> n; 
	cout << "输入增广矩阵A：" << endl;//输入增广矩阵
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n+1; j++)
			cin >> A[i][j];
	}
	for (i = 0; i < n - 1; i++)
	{
		//找主元
		for (j = i; j < n; j++)
		{
			max = A[i][i];
			L0 = i;
			if (fabs(max) < fabs(A[j][i]))
			{
				max = fabs(A[j][i]);
				L0 = j;
			}
		}
		cout << "第" << i + 1 << "列主元绝对值为：" << max << endl;
		//交换第i+1行和主元所在的第L0行
		for (j = i; j < n+1; j++)
		{
			tmp = A[i][j];
			A[i][j] = A[L0][j];
			A[L0][j] = tmp;
		}
		//输出交换之后的矩阵
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < n+1; k++)
				cout << setw(10) << A[j][k];
			cout << endl;
		}
		//消元
		cout << endl;
		cout << "以第" << i + 1 << "行为工具行消元" << endl;//以第i行为工具行进行消元
		//数组角标从零开始需加一才能转换成平常顺序
		for (j = i + 1; j < N; j++)
		{
			c = -(A[j][i] / A[i][i]);//比例系数
			for (k = i; k < n+1; k++)
			{
				A[j][k] = A[j][k] + c*A[i][k];
			}
		}
		for (j = 0; j<n; j++)//输出消元后的矩阵
		{
			for (k = 0; k < n+1; k++)
				cout <<setw(10)<< A[j][k];
			cout << endl;
		}
	}
	//回代求解
	x[n-1] = A[n - 1][n] / A[n - 1][n - 1];//先求方程组的最后一个解
	cout << "x[" << n << "] = " << x[n - 1] << endl;//输出其他解
	for (i = n - 2; i>=0; i--)
	{
		sum = 0;
		for (j = i+1; j < n;j++)
		{
			sum = sum + A[i][j]*x[j];
		}
		x[i] = (A[i][n] - sum) / A[i][i];
		cout << "x[" << i+1 << "] = " << x[i] << endl;
	}
	return 0;
}
