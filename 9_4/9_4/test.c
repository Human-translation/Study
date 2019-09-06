#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char findone(char *str)
{
	int haxi[256] = { 0 };
	char *p = str;
	while (*p != '\0')
	{
		++haxi[*p++];
	}
	while (*str != '\0')
	{
		if (haxi[*str] == 1)
		{
			return *str;
		}
		str++;
	}
}

char findtwo(char *str)
{
	int haxi[256] = { 0 };
	while (*str != '\0')
	{
		++haxi[*str];
		if (haxi[*str] == 2)
		{
			return *str;
		}
		++str;
	}
}

int findnum(int* str,int len,int *x,int *y)
{
	int i = 0;
	int num = 0;
	int count = 0;
	int findnum1 = 0;
	int findnum2 = 0;
	while (i < len)
	{
		num = num^str[i];
		i++;
	}
	while (num % 2 != 1)
	{
		num = num >> 1;
		count++;
	}
	i = 0;
	while (i < len)
	{

		if ((str[i] >> count) % 2 == 0)
		{
			findnum1 = findnum1^str[i];
		}
		else
		{
			findnum2 = findnum2^str[i];
		}
		i++;
	}
	*x = findnum1;
	*y = findnum2;
}

int main()
{
	int arr[] = {1,3,5,7,1,3,5,9};
	int len = sizeof(arr) / sizeof(arr[0]);
	int x = -1;
	int y = -1;
	findnum(arr, len, &x, &y);
	printf("%d  %d",x,y);
	system("pause");
	return 0;
}