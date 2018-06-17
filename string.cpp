#include<iostream>
#include<assert.h>
using namespace std;
class String
{
public:
	String(char* pStr = "")

	{
		if (_pStr == NULL)
		{
			_pStr = new char[1];
			*_pStr = '\0';
		}
		else
		{
			_pStr = new char[strlen(_pStr) + 1];
			my_strcpy(pStr, _pStr);
		}
	}

	String(const String& s)
		:_pStr(NULL)//深拷贝
	{
		String temp(s._pStr);
		swap(temp._pStr, _pStr);
	}
	char* my_strcpy(char *ptr, const char* src)
	{
		assert(ptr);
		char* tmp = ptr;
		while (*tmp++ == *src++)
		{
			;
		}
		return ptr;
	}
	char* my_strcat(char *ptr, const char* src)
	{ 
		assert(ptr);
		char *tmp = ptr;
		while (*ptr!='\0')
		{
			*ptr++;
		}
		while (*ptr++==*src++)
		{
			;
		}
		return ptr;

	}
	int my_strcmp(const char* ptr, const char* src)
	{
		while (*ptr++== *src++)
		{
			;
		}
		if (*ptr > *src)
		{
			return 1;
		}
		else if (*ptr < *src)
		{
			return -1;
		}
		else
			return 0;
	}
	int my_strlen(const char *ptr)
	{
		int count = 0;
		assert(ptr != NULL);
		while (*ptr != '\0')
		{
			count++;
			ptr++;
		}
		return count;
	}
	void display()
	{
		cout << _pStr << endl;
	}
	String& operator=(const String& s);
	~String()
	{
		if (_pStr != NULL)
		{
			delete[]_pStr;
			_pStr = NULL;
		}
	}

	// 不能使用库函数 
	size_t Size();
	size_t Length();
	char& operator[](size_t index);
	const char& operator[](const size_t index)const;
	bool operator>(const String& s);
	bool operator<(const String& s);
	bool operator==(const String& s);
	bool operator!=(const String& s);
	bool strstr(const String& s);
	String String::operator+(const String& s);
	String& operator+=(const String& s);
private:
	char* _pStr;
};
String& String:: operator=(const String& s)
{
	if (this != &s)
	{
		delete[] _pStr;
		_pStr = new char[strlen(_pStr) + 1];
		my_strcpy(_pStr, s._pStr);    
	}
	return *this;

}

size_t String::Length()
{
	return my_strlen(_pStr);
}
// 不能使用库函数 
size_t String:: Size()
{	
	return Length()+1;
}

char& String::operator[](size_t index)
{
	return _pStr[index - 1];
}
const char& String::operator[](const size_t index)const
{
	return _pStr[index - 1];

}
bool String::operator>(const String& s)
{
	return my_strcmp(s._pStr, _pStr)>0 ? true : false;
}
bool String::operator<(const String& s)
{
	return my_strcmp(s._pStr, _pStr) > 0 ? true : false;

}
bool String::operator==(const String& s)
{
	return my_strcmp(s._pStr, _pStr) == 0 ? true : false;
}
bool String::operator!=(const String& s)
{
	return my_strcmp(s._pStr, _pStr) != 0 ? true : false;
}


bool String::strstr(const String& s)
{
	char* ptr = s._pStr;
	while (*_pStr)
	{
		while ((*_pStr != *s._pStr)&&(*_pStr != '\0'))
		{
			*_pStr++;

		}
		char *tmp = s._pStr;
		while ((*ptr == *tmp)&&(*tmp !='\0'))
		{
			ptr++;
			tmp++;
		}
	}
	if (*ptr == '\0')
	{
		return 0;

	}
	else
	{
		_pStr++;
	}
	return false;
}
String String::operator+(const String& s)
{
	String d;
	int len =	my_strlen(_pStr) + my_strlen(_pStr);
	d._pStr = new char[len + 1];
	my_strcpy(d._pStr, _pStr);
	my_strcat(d._pStr, _pStr);
	return d;
}
String& String::operator+=(const String& s)
{
	if (s._pStr == NULL)
	{
		return *this;
	}
	if (this ==&s)
	{
		String copy(*this);
		return *this += copy;
	}
	int len = my_strlen(_pStr) + my_strlen(s._pStr);
	char *old = _pStr;
	_pStr = new char[len + 1];
	my_strcpy(_pStr, s._pStr);
	my_strcat(_pStr, s._pStr);
	delete[]old;
	return *this;
}
int main()
{
	String s("helloworld");
	
	String s1("hello");
	String s2(s1);
	String s3("world");
	size_t a = s1.Size();
	size_t b = s1.Length();
	s1 += s3;
	
	bool x = (s == s1);
	system("pause");
	return 0;
}
