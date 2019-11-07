#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
using namespace std;

class String
{
public:
	//String()
	//	:_str(new char[1])
	//{
	//	*_str = '\0';
	//}

	//String(char* str)
	//	:_str(new char[strlen(str)+1])
	//{
	//	strcpy(_str, str);
	//}

	String(char* str = "")
		:_str(new char[strlen(str) + 1])
	{
		strcpy(_str, str);
	}

	//String(const String& str)
	//	:_str(new char[strlen(str._str) + 1])
	//{
	//	strcpy(_str,str._str);
	//}

	String(const String& str)
		:_str(nullptr)
	{
		String tmp(str._str);
		swap(_str, tmp._str);
	}

	//String& operator=(const String& str)
	//{
	//	if (this != &str)
	//	{
	//		delete[] _str;
	//		_str = new char[strlen(str._str)+1];
	//		strcpy(_str, str._str);
	//	}
	//	return *this;
	//}

	String& operator=(String str)
	{
//		String tmp(str._str);
		swap(_str, str._str);
		return *this;
	}

	const char* c_str() const
	{
		return _str;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
		}
	}
private:
	char* _str;
};

void testString1()
{
	String s;
	cout << (int*)s.c_str() << endl;

	char* str = new char[10];
	strcpy(str, "hello");
	String s3(str);

	delete[] str;
}

void testString2()
{
	String s1("hello");
	String s2 = s1;
	s2 = s1;
}

int main()
{
//	testString1();
	testString2();
	system("pause");
	return 0;
}