#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//void print(int num, string s)
//{
//	int count = 1;
//	int begin = 1;
//	int end = num < 4 ? num : 4;
//	string::iterator it = s.begin();
//	while (it != s.end())
//	{
//		if (*it == 'D')
//		{
//			count++;
//			if (count > num)
//			{
//				count = 1;
//				begin = 1;
//				end = 4;
//			}
//			if (count > end)
//			{
//				begin++;
//				end++;
//			}
//		}
//		if (*it == 'U')
//		{
//			count--;
//			if (count < 1)
//			{
//				count = num;
//				end = num;
//				begin = num - 3;
//			}
//			if (count < begin)
//			{
//				begin--;
//				end--;
//			}
//		}
//		++it;
//	}
//	for (; begin <= end; begin++)
//	{
//		cout << begin << " ";
//	}
//	cout << endl;
//	cout << count << endl;
//
//}
//
//int main()
//{
//	int num;
//	string s;
//	cin >> num >> s;
//	print(num, s);
//	system("pause");
//	return 0;
//}
//0 1 2 3 4 5
//1 2 3 4 5 6
//1 4 2 5 3 6

//1 2 3 4 5 6 7 8
//1 5 2 6 3 7 4 8
//int main()
//{
//	int count, n, k;
//	cin >> count >> n >> k;
//	int a[6];
//	for (int i = 0; i<2 * n; i++)
//	{
//		cin >> a[i];
//	}
//	int b[3];
//	int c[3];
//	for (int i = 0; i < 2*n; i++)
//	{
//		b[i] = a[i];
//		if (i>=n)
//		{
//			c[i%n] = a[i];
//		}
//	}
//	int i = 0;
//	int j = 0;
//	while (i<2*n)
//	{
//		a[i++] = b[j];
//		a[i++] = c[j];
//		j++;
//	}
//	cout << a[0];
//	system("pause");
//	return 0;
//}

//int main()
//{
//	string s;
//	cin >> s;
//	int arr[26] = {0};
//	string::iterator it = s.begin();
//	while (it != s.end())
//	{
//		arr[*it - 'a']++;
//		++it;
//	}
//	it = s.begin();
//	while (it != s.end())
//	{
//		if (arr[*it - 'a'] == 1)
//		{
//			cout << *it << endl;
//			system("pause");
//			return 0;
//		}	
//		++it;
//	}
//	cout << "-1" << endl;
//	system("pause");
//	return 0;
//}

//int main()
//{
//	string s;
//	while (cin >> s)
//	{
//		int flag = 1;
//		int arr[26] = { 0 };
//		string::iterator it = s.begin();
//		while (it != s.end())
//		{
//			arr[*it - 'a']++;
//			++it;
//		}
//		it = s.begin();
//		while (it != s.end())
//		{
//			if (arr[*it - 'a'] == 1)
//			{
//				cout << *it << endl;
//				flag = 0;
//				break;
//			}
//			++it;
//		}
//		if (flag)
//		cout << "-1" << endl;
//	}
//	return 0;
//}

int gongyinshu(int ability, int b)
{
	for (int i = ability; i>0; i--)
	{
		if (ability%i == 0 && b%i == 0)
		{
			return i;
		}
	}
}

int nengli(int ability, int b)
{
	if (ability >= b)
		return b;
	else
		return gongyinshu(ability, b);
}

int main()
{
	int num, ability, i;
	while (cin >> num >> ability)
	{
		int b[20];
		for (i = 0; i<num; i++)
			cin >> b[i];
		i = 0;
		while (i<num)
		{
			ability += nengli(ability, b[i]);
			i++;
		}
		cout << ability << endl;
	}
	system("pause");
	return 0;
}