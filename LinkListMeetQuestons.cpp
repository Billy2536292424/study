#include<stdio.h>
#include<malloc.h>
#include<vector>
typedef struct Node
{
	struct Node* _next;
	int _data;
}node_t;
typedef node_t* pNode;
pNode head = NULL;
pNode head1 = NULL;
void PushBack(int data)
{
	pNode pNewNode = (pNode)malloc(sizeof(node_t));
	pNewNode->_data = data;
	pNewNode->_next = NULL;
	if (head == NULL)
		head = pNewNode;
	else
	{
		pNode pcur = head;
		while (pcur->_next)
		{
			pcur = pcur->_next;
		}
		pcur->_next = pNewNode;
	}
		
}
void PopBack()
{
	if (head == NULL)
		return;
	pNode pcur = head;
	pNode ppre = NULL;
	while (pcur->_next)
	{
		ppre = pcur;
		pcur = pcur->_next;
	}
	ppre->_next = NULL;
	free(pcur);
	pcur = NULL;

}
void PushFront(int data)
{
	pNode pNewNode = (pNode)malloc(sizeof(node_t));
	pNewNode->_data = data;
	pNewNode->_next = NULL;
	if (head == NULL)
		head = pNewNode;
	else
	{
		pNewNode->_next = head;
		head = pNewNode;
	}

}
void PopFront()
{
	if (head == NULL)
		return;
	pNode pDel = head;
	head = head->_next;
	free(pDel);
	pDel = NULL;
}
void Display()
{
	if (head == NULL)
		return;
	pNode pcur = head;
	while (pcur)
	{
		
		printf("%d ", pcur->_data);
		pcur = pcur->_next;
	}
	printf("\n");
}
//2.  从尾到头打印单链表
void DisplayReverse(pNode pCur)
{	
	if (pCur == NULL)
		return;
	DisplayReverse(pCur->_next);
	printf("%d ", pCur->_data);
}
//3.  删除一个无头单链表的非尾节点（不能遍历链表）
void DeleteNotTail(pNode pos)
{
	if (pos == NULL)
		return;
	pNode pcur = pos->_next;
	pos->_data = pcur->_data;
	pos->_next = pcur->_next;
	free(pcur);
	pcur = NULL;
}
//4.  在无头单链表的一个非头节点前插入一个节点
void PushInNotHeadFront(pNode pos,int data)
{
	pNode pNewNode = (pNode)malloc(sizeof(node_t));
	pNewNode->_data = data;
	pNewNode->_next = NULL;

	pNode pNext = pos->_next;
	pNewNode->_next = pNext;
	pos->_next = pNewNode;
	int temp = pos->_data;
	pos->_data = pNewNode->_data;
	pNewNode->_data = temp;
}
//5.  单链表实现约瑟夫环(JosephCircle)

void JosephCircle(int n)
{
	if (head == NULL)
		return;
	pNode pcur = head;
	while (pcur->_next)
	{
		pcur = pcur->_next;
	}
	pcur->_next = head;
	int count = 1;
	pcur = head;
	while (pcur)
	{
		if (count == n)
		{
			pNode pDel = pcur;
			printf("%d ", pDel->_data);
			if (pDel->_next!=pDel)
			{
				DeleteNotTail(pDel);
				count = 1;
			}	
			else
			{
				free(pDel);
				pDel = NULL;
				pcur = NULL;
			}	

		}
		++count;
		if (pcur)
		pcur = pcur->_next;

	}
}
//6.  逆置 / 反转单链表
void ReverseLinkList()
{
	pNode pPre = NULL;
	pNode pcur = head;
	pNode pNext = head->_next;
	while (pcur->_next)
	{
		pcur->_next = pPre;
		pPre = pcur;
		pcur = pNext;
		pNext = pNext->_next;
	}
	pcur->_next = pPre;
	head = pcur;

}
//7.  单链表排序（冒泡排序&快速排序）
void BubbleSort(std::vector<pNode> v)
{
	int size = v.size();
	for (int j = 0; j < size - 1; j++)
	for (int i = 0; i < size - j - 1;i++)
	if (v[i]->_data > v[i+1]->_data)
	{
		int tmp = v[i]->_data;
		v[i]->_data = v[i+1]->_data;
		v[i+1]->_data = tmp;
	}
}
void Swap(std::vector<pNode> v, int left, int right)
{
	int tmp = v[left]->_data;
	v[left]->_data = v[right]->_data;
	v[right]->_data = tmp;
}
int adjust(std::vector<pNode> v, int left, int right)
{
	int key = left;
	while (left < right)
	{
		while (left<right&&v[right]->_data >= v[key]->_data)
			right--;
		while (left<right&&v[left]->_data <= v[key]->_data)
			left++;
		if (left<right)
		Swap(v, left, right);
	}
	Swap(v, key, left);
	return left;
	

}
void QuickSort(std::vector<pNode> v,int left, int right)
{
	if (left < right)
	{
		int n = adjust(v, left, right);
		QuickSort(v, left, n - 1);
		QuickSort(v, n + 1, right);
	}
	
}
void SortLinkList()
{
	if (head == NULL)
		return;
	pNode pcur = head;
	std::vector<pNode> v;
	while (pcur)
	{
		v.push_back(pcur);
		pcur = pcur->_next;
	}
	int size = v.size();
	//BubbleSort(v);
	QuickSort(v,0,size-1);
	
	head = v[0];
	for (int i = 0; i < size - 1; i++)
	{
		v[i]->_next = v[i + 1];
	}
}
//8.  合并两个有序链表, //合并后依然有序
pNode MerageLinklist(pNode h1, pNode h2)
{
	if (h1 == NULL)
		return h2;
	if (h2 == NULL)
		return h1;
	pNode pNewHead = NULL;
	if (h1->_data < h2->_data)
	{
		pNewHead = h1;
		pNewHead->_next = MerageLinklist(h1->_next, h2);
	}
	else
	{
		pNewHead = h2;
		pNewHead->_next = MerageLinklist(h1, h2->_next);
	}
	return pNewHead;
}
//9.  查找单链表的中间节点，要求只能遍历一次链表
pNode MidOfList()
{
	if (head == NULL)
		return NULL;
	pNode slow = head;
	pNode fast = head;
	while (fast->_next)
	{
		slow = slow->_next;
		fast = fast->_next->_next;
	}
	return slow;
}
//10.  查找单链表的倒数第k个节点，要求只能遍历一次链表
pNode LastKNode(int k)
{
	if (head == NULL)
		return NULL;
	pNode first = head;
	pNode second = head;
	while (k--)
	{
		first = first->_next;
	}
	while (first)
	{
		first = first->_next;
		second = second->_next;
	}
	return second;
}
//11.  删除链表的倒数第K个结点
void DeleteLastKNode(int k)
{
	pNode pDel = LastKNode(k);
	if (pDel == NULL)
		return;
	 if (pDel->_next)
	{
		pDel->_data = pDel->_next->_data;
		pDel->_next = pDel->_next->_next;
		free(pDel->_next);
		pDel->_next = NULL;

	}
	 else
	 {
		 PopBack();
	 }
}
//12.  判断单链表是否带环？若带环，求环的长度？求环的入口点？并计算每个算法的时间复
//杂度&空间复杂度。
pNode ListIsCircle()
{
	if (head == NULL)
		return NULL;
	pNode fast = head->_next;
	pNode slow = head;
	while (fast->_next)
	{
		if (fast == slow)
			return slow;
		fast = fast->_next->_next;
		slow = slow->_next;
	}
	return NULL;

}
int CircleLength()
{
	pNode meet = ListIsCircle();
	pNode pNext = meet->_next;
	int count = 1;
	while (pNext != meet)
	{
		count++;
		pNext = pNext->_next;
	}
	return count;
}
//13.  判断两个链表是否相交，若相交，求交点。（假设链表不带环）
pNode JudgeCross(pNode h1, pNode h2)
{
	if (h1 == NULL&&h2 == NULL)
		return NULL;
	int count1 = 0;
	int count2 = 0;
	pNode pcur1 = h1;
	pNode pcur2 = h2;
	
	while (pcur1)
	{
		count1++;
		pcur1 = pcur1->_next;
	}
	while (pcur2)
	{
		count2++;
		pcur2 = pcur2->_next;
	}
	pcur1 = h1;
	pcur2 = h2;
	int diff = 0;
	if (count1 > count2)
	{
		diff = count1 - count2;
		while (diff--)
			pcur1 = pcur1->_next;
	}
	else
	{
		diff = count2 - count1;
		while (diff--)
			pcur2 = pcur2->_next;
	}
	while (pcur1&&pcur2)
	{
		if (pcur1 == pcur2)
			return pcur1;
		pcur1 = pcur1->_next;
		pcur2 = pcur2->_next;
	}
	return NULL;
}

//14.  判断两个链表是否相交，若相交，求交点。（假设链表可能带环）【升级版】
pNode ListIsCircle1(pNode head)
{
	if (head == NULL)
		return NULL;
	pNode fast = head->_next;
	pNode slow = head;
	while (fast->_next)
	{
		if (fast == slow)
			return slow;
		fast = fast->_next->_next;
		slow = slow->_next;
	}
	return NULL;

}
pNode JudgeCrossPlus(pNode h1, pNode h2)
{
	pNode meet1 = ListIsCircle1(h1);
	pNode meet2 = ListIsCircle1(h2);

	if (h1 == NULL || h2 == NULL)
		return NULL;
	if (meet1 == NULL&&meet2 == NULL)
	{
		return JudgeCross(h1, h2);
	}
	else if (meet1!=NULL&&meet2!=NULL)
	{
		while (meet2->_next != meet2)
		{
			if (meet2 == meet1)
				return meet1;
			meet2 = meet2->_next;
		}
		if (meet1 == meet2)
		{
			return meet1;
		}
		else
		{
			return NULL;
		}
	}
	else
	{
		return NULL;
	}

}

//15.  复杂链表的复制。一个链表的每个节点，有一个指向next指针指向下一个节点，还有一
//个random指针指向这个链表中的一个随机节点或者NULL，现在要求实现复制这个链表，
//返回复制后的新链表。
typedef struct ComplexNode
{
	struct	ComplexNode * _next;
	struct ComplexNode* _random;
	int _data;
}CNode;
typedef CNode* PNode;
PNode CHead = NULL;
void CPushBack(int data)
{
	PNode pNewNode = (PNode)malloc(sizeof(CNode));
	pNewNode->_data = data;
	pNewNode->_next = NULL;
	pNewNode->_random = NULL;
	if (CHead == NULL)
		CHead = pNewNode;
	else
	{
		PNode pcur = CHead;
		while (pcur->_next)
		{
			pcur = pcur->_next;
		}
		pcur->_next = pNewNode;
	}

}
void Display2(PNode head)
{
	if (head == NULL)
		return;
	PNode pcur = head;
	while (pcur)
	{

		printf("%d ", pcur->_data);
		pcur = pcur->_next;
	}
	printf("\n");
}
void Clone()
{
	PNode pcur = CHead;
	while (pcur)
	{
		PNode pNewNode = (PNode)malloc(sizeof(CNode));
		pNewNode->_data = pcur->_data;
		pNewNode->_next = NULL;
		pNewNode->_random = NULL;

		pNewNode->_next = pcur->_next;
		pcur->_next = pNewNode;
		pcur = pNewNode->_next;
		
	}
	Display2(CHead);
}
void Adjust()
{
	PNode pcur = CHead;
	while (pcur->_next)
	{
		if (pcur->_random)
			pcur->_next->_random = pcur->_random->_next;
		pcur = pcur->_next;
	}
}
PNode Dismantle()
{
	
	PNode node = CHead;
	PNode cloneHead = NULL;
	PNode cloneNode = NULL;
	if (node)
	{
		cloneHead = cloneNode = node->_next;
		node->_next = cloneNode->_next;
		node = node->_next;
	}
	
	while (node)
	{
		cloneNode->_next = node->_next;
		cloneNode = cloneNode->_next;
		node->_next = cloneNode->_next;
		node = node->_next;
		
	}
	return cloneHead;
}
PNode CloneComplexList()
{
	Clone();
	Adjust();
	return Dismantle();
}
//16.  求两个已排序单链表中相同的数据。void UnionSet(Node* l1, Node* l2);
void UnionSet(pNode h1, pNode h2)
{
	pNode pcur1 = h1;
	pNode pcur2 = h2;
	if (pcur1 == NULL&&pcur2 == NULL)
		return;
	while (pcur1&&pcur2)
	{
		if (pcur1->_data == pcur2->_data)
		{
			printf("%d ", pcur1->_data);
			pcur1 = pcur1->_next;
			pcur2 = pcur2->_next;
		}
		else if (pcur1->_data > pcur2->_data)
		{
			pcur2 = pcur2->_next;
		}
		else
			pcur1 = pcur1->_next;
	}
	printf("\n");

}
void Test1()
{
	PushBack(1);
	PushBack(2);
	PushBack(3);
	PushBack(4);
	PushBack(5);
	Display();
	PopBack();
	Display();

	PopBack();
	Display();

	PopBack();
	Display();

}
void Test2()
{
	PushFront(1);
	PushFront(2);
	PushFront(3);
	PushFront(4);
	PushFront(5);
	Display();
	PopFront();
	Display();

	PopFront();
	Display();

	PopFront();
	Display();

}
void Test3()
{
	PushBack(1);
	PushBack(2);
	PushBack(3);
	PushBack(4);
	PushBack(5);
	Display();
	DisplayReverse(head);
	DeleteNotTail(head->_next->_next);
	Display();


}
void Test4()
{
	PushBack(1);
	PushBack(3);
	PushBack(4);
	PushBack(5);
	Display();
	PushInNotHeadFront(head->_next, 2);
	Display();
}
void Test5()
{
	PushBack(1);
	PushBack(2);

	PushBack(3);
	PushBack(4);
	PushBack(5);
	Display();
	//JosephCircle(3);
	ReverseLinkList();
	Display();

}
void Test6()
{
	PushBack(2);
	PushBack(6);
	PushBack(1);
	PushBack(7);
	PushBack(3);
	PushBack(4);
	Display();
	SortLinkList();
	Display();
}
void PushBack1(pNode *head, int data)
{
	
		pNode pNewNode = (pNode)malloc(sizeof(node_t));
		pNewNode->_data = data;
		pNewNode->_next = NULL;
		if (*head == NULL)
			*head = pNewNode;
		else
		{
			pNode pcur = *head;
			while (pcur->_next)
			{
				pcur = pcur->_next;
			}
			pcur->_next = pNewNode;
		}

	
}
void Display1(pNode head)
{
	if (head == NULL)
		return;
	pNode pcur = head;
	while (pcur)
	{

		printf("%d ", pcur->_data);
		pcur = pcur->_next;
	}
	printf("\n");
}
void Test7()
{
	PushBack1(&head, 0);
	PushBack1(&head, 2);
	PushBack1(&head, 4);
	PushBack1(&head, 6);
	PushBack1(&head, 8);
	Display1(head);

	PushBack1(&head1, 1);
	PushBack1(&head1, 3);
	PushBack1(&head1, 5);
	PushBack1(&head1, 7);
	PushBack1(&head1, 9);
	Display1(head1);
	pNode newhead = MerageLinklist(head, head1);
	Display1(newhead);
}
void Test8()
{
		PushBack(1);
		PushBack(2);
		PushBack(3);
		PushBack(4);
		PushBack(5);
		pNode pcur = head;
		while (pcur->_next)
			pcur = pcur->_next;
		pcur->_next = head->_next->_next;
		/*Display();*/
		/*pNode ret = LastKNode(2);
		printf("Last k Node%d\n", ret->_data);
		DeleteLastKNode(1);
		Display();*/
		if (ListIsCircle())
		{
			printf("List is a circle\n");
			printf("entry point%d\n", ListIsCircle()->_data);
			printf("circle length:%d\n", CircleLength());
		}
		else
			printf("List is not a circle\n");
		
		/*pNode ret = MidOfList();
		if (ret != NULL)
			printf("mide node %d\n", ret->_data);
		else
			printf("NULL");*/
}
void Test9()
{
		PushBack1(&head, 0);
		PushBack1(&head, 2);
		PushBack1(&head, 4);
		PushBack1(&head, 6);
		PushBack1(&head, 8);
		PushBack1(&head, 10);
		PushBack1(&head, 12);
		Display1(head);

		PushBack1(&head1, 1);
		PushBack1(&head1, 3);		
		Display1(head1);
		pNode pcur1 = head;
		pNode pcur2 = head1;
		while (pcur1->_next)
		{
			pcur1 = pcur1->_next;
		}
		pcur1->_next = head->_next->_next->_next;
		while (pcur2->_next)
		{
			pcur2 = pcur2->_next;
		}
		pcur2->_next = head->_next->_next->_next;
		pNode ret = JudgeCrossPlus(head, head1);
		if (ret == NULL)
			printf("not cross\n");
		else
			printf("cross\n");
		printf("meet:%d\n", ret->_data);
}

void Test10()
{
	CPushBack(1);
	CPushBack(2);
	CPushBack(3);
	CPushBack(4);
	CPushBack(5);
	CHead->_next->_next->_next->_random = CHead->_next;
	CHead->_next->_next->_random = CHead;

	Display2(CHead);
	PNode ret = CloneComplexList();
	Display2(ret);

}
void Test11()
{
	PushBack1(&head, 1);
	PushBack1(&head, 3);
	PushBack1(&head, 5);
	PushBack1(&head, 7);
	PushBack1(&head, 9);
	Display1(head);

	PushBack1(&head1, 0);
	PushBack1(&head1, 1);
	PushBack1(&head1, 4);
	PushBack1(&head1, 5);

	PushBack1(&head1, 6);
	PushBack1(&head1, 7);
	PushBack1(&head1, 9);
	Display1(head1);
	UnionSet(head,head1);
}
void main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test5();
	//Test6();
	//Test7();
	//Test8();
	//Test9();
	//Test10();
	Test11();
}
