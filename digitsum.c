 #define _CRT_SECURE_NO_WARNINGS//将一个数的各位数相加
 #include<stdio.h>
 int DigitSum(int num)
 {
 	if (num<10)
 	{
 		return num;
 
 	}
 	else 
 	{
 		return num%10+DigitSum(num/10);
 	}
 }
 int main()
 {
 	int ret = 0;
 	ret = DigitSum(1729);
 	printf("ret = %d\n",ret);
 
 
 	return 0;
 }
