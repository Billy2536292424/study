#include<iostream>
#include<assert.h>
using namespace std;
typedef int DataType;

struct ListNode
{
	ListNode* _next;
	ListNode* _prev;
	DataType _data;

	ListNode(DataType x)
		:_next(NULL)
		, _prev(NULL)
		, _data(x)
	{}
};

class List
{
	typedef ListNode Node;
public:
	List()
		:_head(NULL)
		, _tail(NULL)
	{}
	List(const List& l)
		:_head(NULL)
		, _tail(NULL)
	{
		if (l._head == NULL)
		{
			return;
		}
		Node* tmp = l._head;
		do
		{
			PushBack(tmp->_data);
			tmp = tmp->_next;
		} while (tmp);
	}
	List& operator=(const List& l)
	{
		List l1(l);
		Swap(l1);
		return *this;

	}
	~List()
	{
		if (_head == _tail)
		{
			delete _head;
			_head = _tail = NULL;
		}
		else
		{
			Node* tmp = _head;
			while (tmp)
			{
				Node* del = tmp;
				tmp = tmp->_next;
				delete del;
			}
			_head = _tail = NULL;
		}
	};
	void Swap(List& l)
	{
		swap(_head, l._head);
		swap(_tail, l._tail);
	}
	void PushBack(DataType x)
	{
		//无节点  
		if (_head == NULL)
		{
			_head = new Node(x);
			_tail = _head;
		}
		else//有节点  
		{
			Node* tmp = new Node(x);
			Node* prev = _tail;
			prev->_next = tmp;
			tmp->_prev = prev;
			_tail = tmp;

		}
	}
	void PopBack()
	{
		//无节点  
		if (_head == NULL)
		{
			cout << "List is empty" << endl;
			return;
		}
		//1个节点  
		if (_head == _tail)
		{
			delete _head;
			_head = _tail = NULL;
			return;
		}
		//多个节点  
		Node* prev = _tail->_prev;
		Node* del = _tail;
		delete del;
		_tail = prev;
		_tail->_next = NULL;
	}
	void PushFront(DataType x)
	{
		//无节点  
		if (_head == NULL)
		{
			_head = new Node(x);
			_tail = _head;
		}
		else//有节点  
		{
			Node* NewNode = new Node(x);
			Node* tmp = _head;
			NewNode->_next = tmp;
			tmp->_prev = NewNode;
			_head = NewNode;
		}
	}
	void PopFront()
	{
		//无节点  
		if (_head == NULL)
		{
			cout << "List is empty" << endl;
			return;
		}
		//1个节点  
		if (_head == _tail)
		{
			delete _head;
			_head = _tail = NULL;
			return;
		}
		//多个节点  
		Node* tmp = _head->_next;
		Node* del = _head;
		delete del;
		_head = tmp;
		_head->_prev = NULL;
	}

	// 在pos的前面插入一个   
	void Insert(Node* pos, DataType x)
	{
		assert(pos);
		if (pos == _head)
		{
			PushFront(x);
		}
		else
		{
			Node* prev = pos->_prev;
			Node* cur = new Node(x);
			prev->_next = cur;
			cur->_prev = prev;
			cur->_next = pos;
			pos->_prev = cur;
		}
	}
	void Erase(Node* pos)
	{
		if (pos == _head)
		{
			PopFront();
		}
		else if (pos == _tail)
		{
			PopBack();
		}
		else
		{
			Node* prev = pos->_prev;
			Node* next = pos->_next;
			Node* del = pos;
			prev->_next = next;
			next->_prev = prev;
			delete del;
		}
	}
	Node* Find(DataType x)
	{
		Node* tmp = _head;
		while (tmp)
		{
			if (tmp->_data == x)
			{
				return tmp;
			}
			tmp = tmp->_next;
		}
		return NULL;
	}
	//逆序双向链表方法一  
	//void Reverse()  
	//{  
	//  if((_head == NULL)||(_head == _tail))  
	//  {  
	//      return;  
	//  }  
	//  Node* begin = _head;  
	//  Node* end = _tail;  
	//  while((begin!=end)&&(begin->_prev!=end))  
	//  {  
	//      swap(begin->_data, end->_data);  
	//      begin = begin->_next;  
	//      end = end->_prev;  
	//  }  
	//}  
	//逆序双向链表方法二  

	void Reverse()
	{
		if ((_head == NULL) || (_head == _tail))
		{
			return;
		}
		Node* begin = _head;
		Node* start = _head;
		while (begin != _tail)
		{
			swap(begin->_next, begin->_prev);
			begin = begin->_prev;
		}
		swap(begin->_next, begin->_prev);
		begin->_prev = NULL;
		start->_next = NULL;
		_head = begin;
		_tail = start;
	}
	void Print()
	{
		if (_head == NULL)
		{
			cout << "List is empty" << endl;
			return;
		}
		Node* cur = _head;
		while (cur)
		{
			cout << cur->_data << "->";
			cur = cur->_next;
		}
		cout << "over" << endl;
	}
private:
	Node* _head;
	Node* _tail;
};
int main()
{
	List l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	l.PushBack(5);
	l.Print();
	system("pause");
	return 0;
}
