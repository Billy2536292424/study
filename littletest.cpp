//#include<iostream>
//using namespace std;
//class Solution {
//public:
//	void sortColors(int A[], int n) {
//		if (A != NULL)
//		{
//			BubbleSort(A, n);
//
//		}
//	}
//	void Swap(int A[], int i, int j)
//	{
//		int tmp = A[i];
//		A[i] = A[j];
//		A[i + 1] = tmp;
//	}
//	void BubbleSort(int A[], int n)
//	{
//		for (int j = 0; j < n - 1;j++)
//		for (int i = 0; i < n - 1 - j; i++)
//		{
//			if (A[i]>A[i + 1])
//				Swap(A, i, i + 1);
//		}
//	}
//};
//#include<iostream>
//#include<vector>
//using namespace std;
//#include<string>
//class Solution {
//public:
//	string multiply(string num1, string num2) {
//		if (num1 == "0" || num2 == "0")
//			return "0";
//		vector<int> arr(num1.size() + num2.size(), 0);
//		string ans = "";
//		char tmp = '0';
//		for (int i = num1.size() - 1; i >= 0;--i)
//		for (int j = num2.size() - 1; j >= 0; --j)
//		{
//			arr[i + j + 1] += (num1[i] - '0')*(num2[j] - '0');
//		}
//		for (int i = arr.size() - 1; i >=0 ; --i)
//		{
//			arr[i - 1] += arr[i] / 10;
//			arr[i] = arr[i] % 10;
//		}
//		int i = 0;
//		while (arr[i] == 0)++i;
//		while (i != arr.size())
//		{
//			tmp = arr[i] + '0';
//			ans += tmp;
//			++i;
//		}
//		return ans;
//};
//class Solution {
//public:
//	string multiply(string num1, string num2) {
//		if (num1 == "0" || num2 == "0")
//			return "0";
//		vector<int> arr(num1.size() + num2.size(), 0);
//		string ans = "";
//		char tmp = '0';
//		for (int i = num1.size() - 1; i >= 0; i--)
//		{
//			for (int j = num2.size() - 1; j >= 0; j--)
//			{
//				arr[i + j + 1] += (num1[i] - '0')*(num2[j] - '0');
//			}
//		}
//			for (int i = arr.size() - 1; i >0; i--)
//			{
//				arr[i - 1] += arr[i] / 10;
//				arr[i] = arr[i] % 10;
//			}
//			int i = 0;
//			while (arr[i] == 0) ++i;
//			while (i != arr.size())
//			{
//				tmp = arr[i] + '0';
//				ans += tmp;
//				++i;
//			}
//
//		
//		return ans;
//	}
//};

 //Definition for singly-linked list.
//#include<iostream>
//using namespace std;
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
//
//class Solution {
//public:
//	ListNode *swapPairs(ListNode *head) {
//		if (head == NULL || head->next == NULL)
//			return head;
//		else if (head->next->next == NULL)
//		{
//			ListNode* pNext = head->next;
//			pNext->next = head;
//			head->next = NULL;
//			return pNext;
//		}
//		else
//		{
//			ListNode* pNext = head->next;
//			ListNode* pnewhead = pNext->next;
//			pNext->next = head;
//			head->next = swapPairs(pnewhead);
//			return pNext;
//		}
//	}
//};


//#include<stdio.h>
//#include<string>
//#include<malloc.h>
//void Test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//	}
//}
//int main()
//	{
//	Test();
//}
//#include<iostream>
//#include<vector>
//using namespace std;
//void dfs(int n, int m, vector<int> v, int begin)
//{
//	if (m == 0)
//	{
//		for (int i = 0; i < v.size(); i++)
//		{
//			i == 0 ? cout << v[i] : cout << " " << v[i];
//		}
//		cout << endl;
//	}
//	
//	for (int i = begin; i <= n&&i <= m; i++)
//	{
//		v.push_back(i);
//		dfs(n, m - i, v, i + 1);
//		v.pop_back();
//	}
//}
//int main()
//{
//	int n, m;
//	
//	while (cin >> n >> m)
//	{
//		vector<int> v;
//		dfs(n,m,v,1);
//	}
//}
//#include<string>
//#include<iostream>
//using namespace std;
//int main()
//{
//	string cur, res,str;
//	cin >> str;
//	for (int i = 0; i <= str.length(); i++)
//	{
//		if (str[i] >= '0'&&str[i] <= '9') 
//			cur += str[i];
//		else
//		{
//			if (res.length() < cur.length())
//			{
//				res = cur;
//				
//			}
//			cur = "";
//		}
//		
//			
//	}
//	cout << res << endl;
//	return 0;
//}
//
#include<iostream>
using namespace std;
void CountSort(int arr[], int size)
{
	int max = arr[0];
	int min = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i]>max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	int _size = max - min + 1;
	int *temp = new int[_size];
	memset(temp, 0x00, _size * 4);
	for (int i = 0; i < size; i++)
	{
		temp[arr[i] - min]++;
	}
	for (int i = 0; i < size; i++)
	{
		while (temp[i]--)
		{
			arr[i] = i + min;
		}
	}
}
int main()
{
	int arr[] = { 0, 2, 5, 6, 9, 8, 8, 6, 7, 3 };
	int size = sizeof(arr) / sizeof(arr[0]);
	CountSort(arr, size);
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
