#include "seqlist.h"
void test1()
{
	SeqList my_list;
	InitSeqList(&my_list);
	PushBack(&my_list, 1);
	PushBack(&my_list, 2);
	PushBack(&my_list, 3);
	PushBack(&my_list, 4);
	Display(&my_list);
	PopBack(&my_list);
	Display(&my_list);

}
void test2()
{
	SeqList my_list;
	InitSeqList(&my_list);
	PushFront(&my_list, 1);
	PushFront(&my_list, 2);
	PushFront(&my_list, 3);
	PushFront(&my_list, 4);
	Display(&my_list);
	PopFront(&my_list);
	Display(&my_list);
	PopFront(&my_list);
	Display(&my_list); 
	PopFront(&my_list);
	Display(&my_list);
}
void test3()
{
	int pos = 0;
	SeqList my_list;
	InitSeqList(&my_list);
	PushFront(&my_list, 1);
	
	PushFront(&my_list, 2);
	PushFront(&my_list, 3);
	PushFront(&my_list, 4);
	PushFront(&my_list, 5);
	Display(&my_list);
	pos = Find(&my_list, 4);
	if (pos == -1)
	{
		printf("没找到\n");
	}
	else
	{
		Insert(&my_list, 6, pos);
	}
	Display(&my_list);
	Remove(&my_list, 4);
	RemoveAll(&my_list, 4);
	Reverse(&my_list);
	Sort(&my_list);
	Display(&my_list);
	pos = BinarySearch(&my_list, 4);
	printf("%d\n", pos);
	pos = BinarySearch(&my_list, 7);
	printf("%d\n", pos);
	//Display(&my_list);
	


	
}
int main()
{
	test3();
	system("pause");
	return 0;
}
