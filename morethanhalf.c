#include<iostream>  
using namespace std;  
int MorethanHalf(int a[], int size)  
{  
    int temp = a[0];  
    int flag = 1;  
    for (size_t i = 1; i < size; ++i)  
    {  
        if (temp == a[i])  
            flag++;  
        else  
            flag--;  
        if (flag == 0)  
        {  
            temp = a[i];  
            flag = 1;  
        }  
              
    }  
    return temp;  
}  
int main()  
{  
    int a[] = { 2, 3, 2, 2, 2, 2, 2, 5, 4, 1, 2, 3 };  
    cout << "数组中出现超过一半的字符:" <<MorethanHalf(a, sizeof(a)/sizeof(a[0]))<< endl;  
    system("pause");  
    return 0;  
}  
