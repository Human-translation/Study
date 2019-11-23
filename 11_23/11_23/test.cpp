#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


int main()
{
	string a;
	getline(cin, a);

	int pos = a.find('-');

	string zuo = a.substr(0, pos);
	string you = a.substr(pos + 1, a.size()-pos-1);

	string jJ = { "joker JOKER" };
	if (zuo == jJ || you == jJ)
	{
		cout << jJ << endl;
		return 0;
	}

	int zuolen = count(zuo.begin(), zuo.end(), ' ')+1;
	int youlen = count(you.begin(), you.end(), ' ')+1;

	string arr = "345678910JQKA2";
	string temp1 = zuo.substr(0, zuo.find(' '));
	string temp2 = you.substr(0, you.find(' '));

	if (zuolen == youlen)
	{
		if(arr.find(temp1) > arr.find(temp2))
		{
			cout << zuo << endl;
		}
		else
		{
			cout << you << endl;
		}
	}
	else
	{
		if (zuolen == 4)
		{
			cout << zuo << endl;
		}
		else if (youlen == 4)
		{
			cout << you << endl;
		}
		else
		{
			cout << "error" << endl;
		}
	}
	system("pause");
	return 0;
}
