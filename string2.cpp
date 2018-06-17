#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include<string.h>
using namespace std;
class String
{
public:
	String(char* ptr = "") :
		_pStr(new char[strlen(ptr) + 1])
	{
		strcpy(_pStr, ptr);
	}
	String(const String& s) :
		_pStr(NULL)
	{
		String temp(s._pStr);
		swap(temp._pStr, _pStr);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			String temp(s);
			swap(temp._pStr, _pStr);
		}
		return *this;
	}
	~String()
	{
		if (_pStr)
		{
			delete[] _pStr;
		}
	}
	size_t Size()const
	{

		return (Lengh()*sizeof(char)+1);
	}
	size_t Lengh()const
	{
		size_t length = 0;
		char* p = _pStr;
		while (*p++)
		{
			length++;
		}
		return length;
	}
	char& operator[](size_t index)
	{
		return *(_pStr + index);

	}
	const char& operator[](size_t index)const
	{
		return *(_pStr + index);
	}
	bool operator>(const String& s)
	{
		char* s1 = _pStr;
		char* s2 = s._pStr;
		while (*s1 == *s2 && *s2)
		{
			++s1;
			++s2;
		}
		if ((*s1 - *s2) > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	bool operator<(const String& s)
	{
		if (*this > s)
		{
			return 0;
		}
		else
		{
			return 1;
		}

	}
	bool operator==(const String& s)
	{
		char* s1 = _pStr;
		char* s2 = s._pStr;
		while (*s1 == *s2 && *s2)
		{
			++s1;
			++s2;
		}
		if ((*s1 - *s2) == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}

	}
	bool operator!=(const String& s)
	{
		if (*this == s)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	void Copy(const String& s)
	{
		char* dest = _pStr;
		char* src = s._pStr;
		if (s.Lengh() < Lengh())
		{
			while (*dest++ = *src++)
			{
				;
			}
		}
		else
		{
			delete[] _pStr;
			_pStr = new char[s.Lengh() + 1];
			while (*dest++ = *src++)
			{
				;
			}
		}

	}
	bool strstr(const String& s)
	{
		char* dest = _pStr;
		char* src = s._pStr;
		char* cur = _pStr;
		while (*cur++)
		{
			dest = cur;
			src = s._pStr;
			while (*dest == *src && *src)
			{
				++src;
				++dest;
			}
			if (*src == '\0')
			{
				return 1;
			}
		}
		return 0;
	}
	String& operator+=(const String& s)
	{

		char* temp = new char[Lengh() + s.Lengh() + 1];
		strcpy(temp, _pStr);
		delete[] _pStr;
		_pStr = temp;
		char* dest = _pStr;
		char* src = s._pStr;
		while (*dest)
		{
			++dest;
		}
		while (*dest++ = *src++)
		{
			;
		}
		return *this;
	}
private:
	char* _pStr;
};
int main()
{
	String s("helloworld");
	String s1("hello");
	String s2(s1);
	String s3("world");
	size_t a = s1.Size();
	size_t b = s1.Lengh();
	s1 += s3;
	s2.Copy(s1);
	bool x = (s == s1);
	system("pause");
	return 0;
}
