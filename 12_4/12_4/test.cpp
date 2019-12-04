#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
using namespace std;

//int main()
//{
//	string s;
//	while (cin >> s)
//	{
//		while (s.size() != 1)
//		{
//			string::iterator it = s.begin();
//			int sum = 0;
//			while (it != s.end())
//			{
//				sum += *it - '0';
//				++it;
//			}
//			s = sum % 10 + '0';
//			sum /= 10;
//			while (sum)
//			{
//				s += sum % 10 + '0';
//				sum /= 10;
//			}
//		}
//		cout << s << endl;
//	}
//	system("pause");
//	return 0;
//}

// 1

//1 1
//2


//1 1 1
//1 2
//2 1
//3

//1111
//1 1 2
//1 2 1
//2 1 1
//1 3
//3 1
//2 2
//4

//1 1 1 1 1
//1 1 1 2
//1 1 2 1
//1 2 1 1
//2 1 1 1
//1 1 3
//1 3 1
//3 1 1
//1 4
//4 1
//5
//2 2 1
//2 1 2
//1 2 2
//2 3
//3 2
//int jumpFloorII(int number) {
//	if (number == 1)
//		return 1;
//	if (number == 2)
//		return 2;
//	return 1 + jumpFloorII(number - 1) + jumpFloorII(number - 2);
//}
////1 (3) (2) 
//int main()
//{
//	int ret = jumpFloorII(4);
//	cout << ret << endl;
//	system("pause");
//	return 0;
//}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	double sum = 0;
	string::iterator it = s2.begin();
	while (it != s2.end())
	{
		sum += 6.24*(*it - '0');
		sum *= 10;
		++it;
	}
	cout << sum << endl;
	system("pause");
	return 0;
}