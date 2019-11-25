#define _CRT_SECURE_NO_WARNINGS
#include <list>
#include <iostream>
using namespace std;

template <class T, class Container>
class Stack
{
public:
	void push(const T& val)
	{
		_con.push_back(val);
	}
	void pop()
	{
		_con.pop_back();
	}

	void top()
	{
		return _con.back();
	}
	bool empty()
	{
		return _con.empty;
	}
	size_t size()
	{
		return _con.size();
	}
private:
	Container _con;
};

int main()
{
	Stack<int, list<int>> st;
	st.push(1);
	st.push(1);
	st.push(1);
	st.push(1);
	st.push(1);
	st.push(1);
	cout << st.size();
	system("pause");
	return 0;
}
