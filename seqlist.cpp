#include<iostream>
#include<assert.h>
using namespace std;
typedef int DataType;
class SeqList
{
public:
	SeqList()//构造函数
		: _array(new DataType[3])
		, _capacity(3)
		, _size(0)
	{}

	// 思考两种方式的优缺点 
	SeqList(DataType* array, size_t size)//构造函数
		: _array(new DataType[size])
		, _capacity(size)
		, _size(size)
	{
		// 1、循环逐个搬移-缺陷：效率低 正确性 
		for (size_t i = 0; i < size; ++i)
			_array[i] = array[i];

		// 2、优点：效率高--->问题？---可能会出错 
		//memcpy(_array, array, size*sizeof(array[0])); 
	}

	// 三大big 
	SeqList(const SeqList& s)//拷贝构造函数
		:_array(NULL)
		, _size(0)
		, _capacity(0)
	{
		SeqList tmp(s._array, s._capacity);
		tmp._size = _size;
		swap(tmp, *this);
	}
	
	SeqList& operator=(const SeqList& s)//赋值运算符重载
	{
		if (this!=&s)
		{
			DataType* tmp = _array;
			_array = new DataType[s._capacity];
			_size = s._size;
			_capacity = s._capacity;
			delete[] tmp;
			for (size_t i = 0; i < _size; i++)
			{
				_array[i] = s._array[i];
			}
		}
		return *this;

	}
	
	~SeqList()//析构函数
	{
		if (_array)
		{
			delete[] _array;
			_size = 0;
			_capacity = 0;
		}
	}

	void PushBack(int data)//尾插
	{
		assert(_array);
		_CheckCapacity();
		_array[_size] = data;
		_size++;

	}
	void PopBack()//尾删
	{
		assert(_array);
		if (_array ==NULL)
		{
			return;
		}
		_size--;
	}
	void Insert(size_t pos, DataType data)//在任意位置插入元素
	{
		assert((pos > 0) && (pos<_size));
		_CheckCapacity();
		for (size_t i = _size; i > pos; i--)
		{
			_array[i] = _array[i - 1];
		}
		_array[pos] = data;
		_size++;
	}
	void Erase(size_t pos)//任意地方删除
	{
		assert((pos > 0) && (pos<_size));
		if (_size == 0)
		{
			return;
		}
		
		size_t last = _size;
		for (size_t i = pos-1; i < _size; i++)
		{
			_array[i] = _array[i + 1];
		}
		--_size;

	}
	size_t Size()const//返回大小
	{
		return _size;
	}
	size_t Capacity()const//返回容量
	{
		return _capacity;
	}
	bool Empty()const//判断顺序表是否为空
	{
		return (_size == NULL);
	}
	DataType& operator[](size_t index)//下标运算符重载
	{
		return _array[index];
	}
	const DataType& operator[](size_t index)const
	{
		return _array[index];
	}

	// 返回顺序表中的第一个元素 
	DataType& Front()
	{
		assert(_size > 0);
		
		return _array[0];
	}
	const DataType& Front()const
	{
		assert(_size > 0);
		
		
			return _array[0];;
		
		
	}
	// 返回顺序表中最后一个元素 
	DataType& Back()
	{
		assert(_size > 0);
		
			return _array[_size-1];
		
	}
	const DataType& Back()const
	{
		assert(_size > 0);
		
			return _array[_size-1];
		
	}

	// 清空顺序表中的所有元素 
	void Clear()
	{
		if (_array!=NULL)
		{
			delete[]_array;
			_size = 0;
			_capacity = 0;
		}
	}

	// reserve() 
	// 将顺序表中元素个数改变到newSize 
	void ReSize(size_t newSize, const DataType& data = DataType())
	{
		if (newSize <= _size)
		{
			_size = newSize;
		}
		else
		{
			int tmp = _size;
			_size = newSize;
			_CheckCapacity();
			for (size_t i = tmp; i < newSize; i++)
			{
				_array[i] = data;
			}

		}
	}
	void display();//打印函数
	friend ostream& operator<<(ostream& _cout, const SeqList& s);
	int Find(const DataType &data)
	{
		for (size_t i = 0; i < _size; i++)
		{
			if (_array[i]==data)
			{
				return 1;
			}
		}
		return 0;
	}
private:
	
		void _CheckCapacity()//判断顺序表是否已经满了，若满进行扩充
	{
			assert(_array);
			if (_capacity <= _size)
			{
				DataType* newarray = new DataType[2 * _capacity];//开辟二倍大的新空间
				for (size_t i = 0; i < _size; i++)//拷贝
				{
					newarray[i] = _array[i];
				}
				delete[]_array;
				_array = NULL;
				_array = newarray;
				_capacity = 2 * _capacity;
			}
		}
	
private:
	DataType* _array;
	size_t _size;
	size_t _capacity;
};

ostream& operator<<(ostream& _cout, const SeqList& s)//输出运算符重载
{
	for (size_t i = 0; i < s._size; i++)
	{
		_cout << s._array[i] << ' ';
	}
	_cout << endl;
	return _cout;
}
void SeqList::display()
{
	for (size_t i = 0; i < _size; i++)
	{
		cout << _array[i] << " ";
	}
	cout << endl;
}
void FunTest()
{
	SeqList s1;
	s1.PushBack(1);//尾插
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);
	s1.PushBack(5);
	s1.PushBack(6);
	s1.display();//打印

	s1.PopBack();//尾删
	s1.display();//打印

	s1.Insert(1, 1);//在第一位后面插入1
	s1.display();

	s1.Erase(3);//删除第三位元素
	s1.display();

	int a = s1.Find(9);
	if (a == 1)
	{
		cout << "找到了！" << endl;
	}
	else
	{
		cout << "没有找到！" << endl;
	}

	int b = s1.Size();
	cout << "Size= " << b << endl;

	int c = s1.Capacity();
	cout << "Capacity= " << c << endl;

	int d = s1.Empty();
	if (d == 0)
	{
		cout << "顺序表不为空！" << endl;
	}

	DataType e = s1.Front();
	s1.display();
	cout << "顺序表中第一个元素为" << e << endl;

	DataType f = s1.Back();
	s1.display();
	cout << "顺序表中第一个元素为" << f << endl;

	//s1.Clear();//清空
	//s1.diplay();//打印

	s1.ReSize(7, 1);
	int b1 = s1.Size();
	cout << "Size= " << b1 << endl;

}
int main()
{
	FunTest();
	system("pause:");
	return 0;
}
