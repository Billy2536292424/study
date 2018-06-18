#include<iostream>
using namespace std;
typedef int DataType;
struct Node
{
	Node(const DataType& data)
	: _pNext(NULL)
	, _pPre(NULL)
	, _data(data)
	{}

	Node* _pNext;
	Node* _pPre;
	DataType _data;
	
};

class List
{
	
public:
	List()
		: _pHead(NULL)
		, _pTail(NULL)
		
	{}

	List(DataType* array, size_t size)
	{
		for (size_t i = 0; i < size; ++i)
			PushBack(array[i]);
	}

	// 有没有问题？ 
	void PushBack(const DataType data)
	{
	
		
		
		if (_pTail)
		{
			Node* pNewNode = new Node(data);
			Node* prev = _pTail;
			
			prev->_pNext = pNewNode;
			pNewNode->_pPre = prev;
		}
		else
		{
			
			_pHead = new Node(data);
			_pTail = _pHead;
		}
	}

	void PopBack()
	{
		if (_pHead == NULL)
		{
			cout << "list is empty" << endl;
			return;
		}
		if (_pHead = _pTail)
		{
			delete _pHead;
			_pHead = _pTail = NULL;
			return;
		}
		Node* prev = _pTail->_pPre;

		Node* del = _pTail;
		
		delete del;
		_pTail = prev;
		_pTail->_pNext = NULL;
	}
	void PushFront(const DataType data)
	{
		if (_pHead==NULL)
		{
			_pHead = new Node(data);
			_pTail = _pHead;
		}
		else
		{
			Node* NewNode = new Node(data);
			Node* tmp = _pHead;
			NewNode->_pNext = tmp;
			tmp->_pPre = NewNode;
			_pHead = NewNode;
		}
	}
	void PopFront()
	{
		if (_pHead == NULL)
		{
			cout << "list is empty" << endl;
			return;
		}
		if (_pHead == _pTail)
		{
			delete _pHead;
			_pHead = _pTail = NULL;
			return;
		}
		Node* tmp = _pHead->_pNext;
		Node* del = _pHead;
		delete del;
		_pHead = tmp;
		_pHead->_pPre = NULL;
	}
	
	Node* Erase(Node* pos)
	{
		if (pos==_pHead)
		{
			PopFront();
		}
		else if (pos == _pTail)
		{
			PopBack();
		}
		else
		{
			Node* prev = pos->_pPre;
			Node* next = pos->_pNext;
			Node* del = pos;
			prev->_pNext = next;
			next->_pPre = prev;
			delete del;
		}
		


	}
	Node* Insert(Node* pos, const DataType& data)
	{
		if (pos==_pHead)
		{
			PushFront(data);	

		}
		else
		{
			Node* prev = pos->_pPre;
			Node* cur = new Node(data);
			prev->_pNext = cur;
			cur->_pPre = prev;
			cur->_pNext = pos;
			pos->_pPre = cur;
		}
	}
	size_t Size()
	{
		size_t count = 0;
		Node* pTail = _pHead;
		while (pTail->_pNext!=	NULL)
		{
			pTail = pTail->_pNext;
			count++;
		}

	}
	void Clear()
	{
		if (_pHead!=NULL)
		{
			delete _pHead;
			_pHead = NULL;
		}
	}
	void display()
	{
		if (_pHead== NULL)
		{
			cout << "list is empty" << endl;
			return;
		}
		Node* cur = _pHead;
		while (cur)
		{
			cout << cur->_data << "->";
			cur = cur->_pNext;
		}
		cout << endl;
	}
private:
	Node* _pHead;
	Node* _pTail;
	
};
void FunTest1()
{
	List l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	l.PushBack(5);
	l.display();
	l.PopBack();
	l.PopBack();
	l.PopBack();
	l.display();

}
void FunTest2()
{
	List l;
	l.PushFront(1);
	l.PushFront(2);
	l.PushFront(3);
	l.PushFront(4);
	l.PushFront(5);
	l.display();
	l.PopFront();
	l.PopFront();
	l.PopFront();
	l.display();
	l.Insert(,2);
}
int main()
{
	FunTest2();
	system("pause");
	return 0;
}
