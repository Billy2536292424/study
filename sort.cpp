//
////1、冒泡排序
//#include<stdio.h>
//void BubbleSort(int A[],int size)
//{
//	for (int j= 0; j < size - 1; j++)//控制每次循环最大元素浮动到数组最后
//	{
//		for (int i = 0; i < size - 1- j; i++)//控制左右相邻的比较
//		{
//			if (A[i]>A[i + 1])
//			{
//				int tmp = A[i];
//				A[i] = A[i + 1];
//				A[i + 1] = tmp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int A[] = {2,6,4,8,1,5,9};
//	int size = sizeof(A) / sizeof(A[0]);
//	BubbleSort(A, size);
//	for (int i = 0; i < size ; i++)
//	{
//		printf("%d ", A[i]);
//	}
//	printf("\n");
//	return 0;
//}
////2、鸡尾酒排序
//#include<stdio.h>
//void Swap(int A[], int i, int j)
//{
//	int tmp = A[i];
//	A[i] = A[j];
//	A[j] = tmp;
//}
//void BubbleSort(int A[], int size)
//{
//	int left = 0;
//	int right = size - 1;//对边界进行初始化
//	while (left < right)
//	{
//		for (int i = 0; i < right; i++)//前半段控制将最大的元素放在后面
//		{
//			if (A[i]>A[i + 1])
//			{
//				Swap(A, i, i + 1);
//			}
//			
//		}
//		right--;
//		for (int j = right; j > left; j--)//后半段控制将最小元素放在最前面
//		{
//			if (A[j - 1] > A[j])
//			{
//				Swap(A, j - 1, j);
//			}
//		}
//		left++;
//	}
//}
//int main()
//{
//	int A[] = { 2, 6, 4, 8, 1, 5, 9 };
//	int size = sizeof(A) / sizeof(A[0]);
//	BubbleSort(A, size);
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", A[i]);
//	}
//	printf("\n");
//	return 0;
//}
//3、选择排序
//#include<stdio.h>
//void Swap(int A[], int i, int j)
//{
//	int tmp = A[i];
//	A[i] = A[j];
//	A[j] = tmp;
//}
//void SelectSort(int A[], int size)
//{
//	for (int i = 0; i < size - 1; i++)
//	{
//		int min = i;
//		for (int j = i + 1; j < size - 1; j++)
//		{
//			if (A[min] > A[j])
//				min = j;
//		}
//		if (min != i)
//			Swap(A, min, i);
//	}
//
//}
//int main()
//{
//	int A[] = { 2, 6, 4, 8, 1, 5, 9 };
//	int size = sizeof(A) / sizeof(A[0]);
//	SelectSort(A, size);
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", A[i]);
//	}
//	printf("\n");
//	return 0;
//}
//4、插入排序
//#include<stdio.h>
//void InsertSort(int A[], int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		int get = A[i];
//		int j = i - 1;
//		while (j >= 0 && A[j]>get)
//		{
//			A[j+1 ] = A[j];
//			j -- ;
//		}
//		A[j + 1] = get;
//	}
//}
//int main()
//{
//	int A[] = { 2, 6, 4, 8, 1, 5, 9 };
//	int size = sizeof(A) / sizeof(A[0]);
//	InsertSort(A, size);
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", A[i]);
//	}
//	printf("\n");
//	return 0;
//}
//5、二分插入排序
//#include<stdio.h>
//void HalfInsertSort(int A[], int size)
//{
//	for (int i = 1; i < size; i++)
//	{
//		int get = A[i];//右手抓到一张扑克牌
//		int left = 0;//左手上的牌是已排序的
//		int right = i - 1;//手牌左右边界进行初始化
//		while (left <= right)//二分法确定新牌的位置
//		{
//			int mid = left + ((right - left) >> 1);
//			if ( A[mid] > get)
//				right = mid - 1;
//			else 
//				left = mid + 1;
//		}
//		for (int j = i - 1; j >= left; j--)//将新牌吃哈如位置\
//			后面的元素依次向后移动一个位置
//		{
//			A[j + 1] = A[j];
//		}
//		A[left] = get;
//	}
//}
//int main()
//{
//	int A[] = { 2, 6, 4, 8, 1, 5, 9 };
//	int size = sizeof(A) / sizeof(A[0]);
//	HalfInsertSort(A, size);
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", A[i]);
//	}
//	printf("\n");
//	return 0;
//}
//6、希尔排序
//#include<stdio.h>
//void ShellSort(int A[], int size)
//{
//	int h = 0;
//	while (h <= size)//确定初始增量
//	{
//		h = h * 3 + 1;
//
//	}
//	while (h >= 1)
//	{
//		for (int i = h; i < size; i++)
//		{
//			int j = i - h;
//			int get = A[i];
//			while (j >= 0 && A[j]>get)
//			{
//				A[j + h] = A[j];
//				j = j - h;
//			}
//			A[j + h] = get;
//		}
//		h = (h - 1) / 3;//递减增量
//	}
//}
//int main()
//{
//	int A[] = { 2, 6, 4, 8, 1, 5, 9 };
//	int size = sizeof(A) / sizeof(A[0]);
//	ShellSort(A, size);
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", A[i]);
//	}
//	printf("\n");
//	return 0;
//}
//6、归并排序
//#include<stdio.h>
//#include<malloc.h>
//void Merge(int A[], int left, int mid, int right)
//{
//	int size = right - left+1;
//	int *tmp = (int *)malloc(size*sizeof(int));
//
//	int i = left;
//	int j = mid + 1;
//	int index = 0;
//	while (i <= mid&&j <= right)
//	{
//		tmp[index++] = A[i] < A[j] ? A[i++] : A[j++];
//
//	}
//	while (i <= mid)
//	{
//		tmp[index++] = A[i++];
//	}
//	while (j <= right)
//	{
//		tmp[index++] = A[j++];
//	}
//	for (int k = 0; k < size; k++)
//	{
//		A[left++] = tmp[k];
//	}
//
//}
//
//void MergeSort(int A[], int left, int right)
//{
//	if (left == right)
//		return;
//	int mid = left + ((right - left) >> 1);
//	MergeSort(A, left, mid);
//	MergeSort(A, mid + 1, right); 
//	Merge(A, left, mid, right);
//}
//int main()
//{
//	int A[] = { 2, 6, 4, 8, 1, 5, 9 };
//	int size = sizeof(A) / sizeof(A[0]);
//	MergeSort(A, 0,size-1);
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", A[i]);
//	}
//	printf("\n");
//	return 0;
//}
//7、堆排序
//#include<stdio.h>
//void Swap(int A[], int i, int j)
//{
//	int tmp = A[i];
//	A[i] = A[j];
//	A[j] = tmp;
//}
//void HeapModify(int A[], int i, int size)
//{
//	int left_child = 2 * i + 1;
//	int right_child = 2 * i + 2;
//	int max = i;
//	if (left_child<size&&A[left_child]>A[max])
//		max = left_child;
//	if (right_child<size&&A[right_child]>A[max])
//		max = right_child;
//	if (max!=i)
//	{
//		Swap(A, i, max);
//		HeapModify(A, max, size);
//	}
//}
//int HeapBuild(int A[], int size)
//{
//	int Heapsize = size;
//	for (int i = Heapsize / 2 - 1; i >= 0; i--)
//	{
//		HeapModify(A, i, Heapsize);
//	}
//	return Heapsize;
//}
//void HeapSort(int A[], int size)
//{
//	int Heapsize = HeapBuild(A, size);
//	while (Heapsize > 1)
//	{
//		Swap(A, 0, --Heapsize);
//		HeapModify(A, 0, Heapsize);
//	}
//}
//int main()
//{
//	int A[] = { 2, 6, 4, 8, 1, 5, 9 };
//	int size = sizeof(A) / sizeof(A[0]);
//	HeapSort(A, size);
//	printf("堆排序\n");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", A[i]);
//	}
//	printf("\n");
//	return 0;
//}
//8、快速排序
//#include<stdio.h>
//void Swap(int A[], int i, int j)
//{
//	int tmp = A[i];
//	A[i] = A[j];
//	A[j] = tmp;
//}
//
//int position(int A[], int left, int right)
//{
//	int key = left;
//	while (left < right)
//	{
//		while (left < right&& A[key] > A[left]){
//			++left;
//		}
//		while (left < right&& A[key] < A[right])
//		{
//			--right;
//		}
//		
//		
//		if (left < right)
//		{
//			Swap(A, left, right);
//		}
//	}
//	Swap(A, key, left);
//	return left;
//}
//void QuickSort(int A[], int left, int right)
//{
//	if (left < right)
//	{
//		int n =position(A, left, right);
//		QuickSort(A, left, n - 1);
//		QuickSort(A, n+1 , right);
//	}
//}
//int main()
//{
//	int A[] = { 2, 6, 4, 8, 1, 5, 9 };
//	int size = sizeof(A) / sizeof(A[0]);
//	QuickSort(A, 0,size-1);
//	printf("快速排序\n");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", A[i]);
//	}
//	printf("\n");
//	return 0;
//}
//快排2
//#include<stdio.h>
//int position(int A[], int left, int right)
//{
//	int key = A[left];
//	while (left < right)
//	{
//		while (left < right&&key < A[right])
//		{
//			right--;
//		}
//		if (left < right)
//		{
//			A[left] = A[right];
//		}
//		while (left<right&&key>A[left])
//		{
//			left++;
//		}
//		if (left < right)
//			A[right] = A[left];
//	}
//	A[left] = key;
//	return left;
//}
//void QuickSort(int A[], int left, int right)
//{
//	if (left < right)
//	{
//		int n = position(A, left, right);
//		QuickSort(A, left, n - 1);
//		QuickSort(A, n + 1, right);
//	}
//}
//int main()
//{
//	int A[] = { 2, 6, 4, 8, 1, 5, 9 };
//	int size = sizeof(A) / sizeof(A[0]);
//	QuickSort(A, 0, size - 1);
//	printf("快速排序2\n");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", A[i]);
//	}
//	printf("\n");
//	return 0;
//}
//#include<stdio.h>
//void Swap(int A[],int i, int j)
//{
//	int tmp = A[i];
//	A[i] = A[j];
//	A[j] = tmp;
//}	
//void TreeNumberGetMid(int A[], int left, int right)
//{
//	int mid = left + ((right - left) >> 1);
//	if (A[mid] > A[left] && A[mid] < A[right])
//	{
//		Swap(A,mid,right);
//		return;
//	}
//	if (A[left]>A[mid] && A[right] < A[right])
//	{
//		Swap(A,left, right);
//		return;
//	}
//	if (A[right]>A[mid] && A[right] < A[left])
//		return;
//}
//int position(int A[], int left, int right)
//{
//	TreeNumberGetMid(A, left, right);
//	int fast = left;
//	int slow = left - 1;
//	while (fast < right)
//	{
//		if (A[fast] < A[right])
//		{
//			++slow;
//			if (slow != fast)
//				Swap(A,fast, slow);
//		}
//		fast++;
//	}
//	++slow;
//	Swap(A,slow, right);
//	return slow;
//}
//void QuickSort(int A[], int left, int right)
//{
//	if (left < right)
//	{
//		int n = position(A, left, right);
//		QuickSort(A, left, n - 1);
//		QuickSort(A, n + 1, right);
//
//	}
//}
//int main()
//{
//	int A[] = { 2, 6, 4, 8, 1, 5, 9 };
//	int size = sizeof(A) / sizeof(A[0]);
//	QuickSort(A, 0, size - 1);
//	printf("快速排序3\n");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", A[i]);
//	}
//	printf("\n");
//	return 0;
//}
//9、计数排序
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
