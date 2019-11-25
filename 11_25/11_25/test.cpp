#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;



int main()
{
	string input1, input2;
	string output;
	cin >> input1 >> input2;
	int num = input1.size();
	int num2 = input2.size();
	int jinwei = 0;
	int benwei = 0;
	while ((num >0)|| (num2>0))
	{
		int jia=0,jia2=0;
		if (num > 0)
		{
			jia = input1[num-1]-'0';
		}	
		if (num2 > 0)
		{
			jia2 = input2[num2-1]-'0';
		}
		benwei = (jia + jia2 + jinwei) % 10;
		jinwei = (jia + jia2 + jinwei) / 10;
		output += (benwei + '0');
		num--;
		num2--;
	}
	if (jinwei == 1)
	{
		output += jinwei+'0';
	}
	string::reverse_iterator it = output.rbegin();
	while (it != output.rend())
	{
		cout << *it;
		++it;
	}
	cout << endl;
	system("pause");
	return 0;
}