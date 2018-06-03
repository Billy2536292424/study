 2牛顿法解非线性方程组代码
 #include<iostream>
 #include<cmath>
 #define N 2                     // 非线性方程组中方程个数、未知量个数
 #define M 2                        //迭代次数
 using namespace std;
 const int N2=2*N;
 int main()
 {
 	void ff(float xx[N],float yy[N]);           //计算向量函数的因变量向量yy[N]
 	void ffjacob(float xx[N],float yy[N][N]);            //计算雅克比矩阵yy[N][N]
 	void inv_jacob(float yy[N][N],float inv[N][N]);           //计算雅克比矩阵的逆矩阵inv
 	void newton(float x0[N], float inv[N][N],float y0[N],float x1[N]);          //由近似解向量x0计算近似解向x1
 	float x0[N]={1.60,1.20},y0[N],jacob[N][N],invjacob[N][N],x1[N];
 	int i,j,iter=0;
 	cout<<"输入初始值："<<endl;
 	for(i=0;i<N;i++)
 		cin>>x0[i];
 	cout<<"初始近似解向量："<<endl;
 	for(i=0;i<N;i++)
 		cout<<x0[i]<<"  ";
 	cout<<endl;cout<<endl;
 	do
 	{iter=iter+1;
 	cout<<"第"<<iter<<" 次迭代开始"<<endl;
 	ff(x0,y0);                            //计算向量函数的因变量向量y0                
 	ffjacob(x0,jacob);                 //计算雅克比矩阵jacobian         
 	inv_jacob(jacob,invjacob);        //计算雅克比矩阵的逆矩阵invjacobian
 	newton(x0, invjacob,y0,x1);               //由近似解向量x0 计算近似解向量x1    
 	for(i=0;i<N;i++)
 		x0[i]=x1[i];
 	}while(iter<M);
 	return 0;
 }
 //计算初值对应的函数值
 void ff(float xx[N],float yy[N])              //被调用函数
 {float x,y;
 int i;
 x=xx[0];
 y=xx[1];
 yy[0]=x*x+y*y-4;                       
 yy[1]=x*x-y*y-1;
 cout<<"向量函数的因变量向量是："<<endl;
 for( i=0;i<N;i++)
 cout<<yy[i]<<"  ";
 cout<<endl;
 cout<<endl;}
 //输出雅克比矩阵
 void ffjacob(float xx[N],float yy[N][N])
 {float x,y;
 int i,j;
 x=xx[0];
 y=xx[1];
 yy[0][0]=2*x;
 yy[0][1]=2*y;
 yy[1][0]=2*x;
 yy[1][1]=-2*y;
 cout<<"雅克比矩阵是："<<endl;
 for(i=0;i<N;i++)
 {for(j=0;j<N;j++)
 cout<<yy[i][j]<<"  ";
 cout<<endl;
 }
 cout<<endl;
 }
 //计算雅克比矩阵的逆矩阵
 void inv_jacob(float yy[N][N],float inv[N][N])
 {float expend[N][N2],L;
 int i,j,v;
 cout<<"开始计算雅克比矩阵的逆矩阵："<<endl;
 for(i=0;i<N;i++)
 {for(j=0;j<N;j++)
 expend[i][j]=yy[i][j];
 for(j=N;j<N2;j++)
 if(j==i+N) expend[i][j]=1;
 else expend[i][j]=0;
 }
 for(i=0;i<N;i++)
 {for(j=0;j<N2;j++)
 cout<<expend[i][j]<<"  ";
 cout<<endl;
 }
 cout<<endl;
 for(i=0;i<N;i++)
 {for(v=i+1;v<N;v++)
 {L=-expend[v][i]/expend[i][i];
 for(j=i;j<N2;j++)
 expend[v][j]=expend[v][j]+L*expend[i][j];
 }
 }
 for(i=0;i<N;i++)
 {for(j=0;j<N2;j++)
 cout<<expend[i][j]<<"  ";
 cout<<endl;
 }
 cout<<endl;
 for(i=N-1;i>0;i--)
 {for(v=i-1;v>=0;v--)
 {L=-expend[v][i]/expend[i][i];
 for(j=N2-1;j>=0;j--)
 expend[v][j]=expend[v][j]+L*expend[i][j];
 }
 }
 for(i=0;i<N;i++)
 {for(j=0;j<N2;j++)
 cout<<expend[i][j]<<"  ";
 cout<<endl;
 }
 cout<<endl;
 for(i=N-1;i>=0;i--)
 for(j=N2-1;j>=0;j--)
 expend[i][j]=expend[i][j]/expend[i][i]; //在原雅克比矩阵后添加单位矩阵,通过变换求解逆矩阵
 for(i=0;i<N;i++)
 {for(j=0;j<N2;j++)
 cout<<expend[i][j]<<"  ";
 cout<<endl;
 for(j=N;j<N2;j++)
 inv[i][j-N]=expend[i][j];}
 cout<<endl;                       //将变换后的矩阵对应其逆矩阵
 cout<<"雅克比矩阵的逆矩阵："<<endl;
 for(i=0;i<N;i++)
 {for(j=0;j<N;j++)
 cout<<inv[i][j]<<"  ";
 cout<<endl;
 }
 cout<<endl;
 }
 //迭代求解函数
 void newton(float x0[N], float inv[N][N],float y0[N],float x1[N])
 {int i,j;
 float sum=0;
 for(i=0;i<N;i++)
 {sum=0;
 for(j=0;j<N;j++)
 sum=sum+inv[i][j]*y0[j];
 x1[i]=x0[i]-sum;
 }
 cout<<"近似解向量："<<endl;
 for(i=0;i<N;i++)
 cout<<x1[i]<<"  "<<endl;
 cout<<endl;
 }
