#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void delarr2(char *str1, char *str2)
{
	int haxi[256] = { 0 };
	while (*str2 != '\0')
	{
		++haxi[*str2++];
	}
	while (*str1 != '\0')
	{
		if (haxi[*str1] != 0)
		{
			int i = 0;
			int j = 0;
			while (str1[i] != '\0')
			{
				if (haxi[str1[i]] == haxi[str1[i + 1 + j]] && haxi[str1[i]]==1)
				{
					j++;
				}
				str1[i] = str1[i + 1 + j];
				i++;
			}
		}
		str1++;
	}
}

int huiwen(int x)
{
	int x_copy = x;
	int num = 0;
	int y = 0;
	while (x_copy)
	{
		num = x_copy % 10;
		x_copy = x_copy / 10;
		y = y * 10 + num;
	}
	if (x == y)
		return 1;
	return 0;
}

int mypow(int x, int y)
{
	int num;
	if (y == 0)
	{
		return 1;
	}
	if (y % 2 == 1)
	{
		num = x*mypow(x, y / 2) * mypow(x, y / 2);
	}
	else
	{
		num = mypow(x, y / 2) * mypow(x, y / 2);
	}
	if (y == 0)
	{
		return 1;
	}
	return num;
}

int main()
{
//	char arr1[] = { "They are studentuuuuuuuuuu" };
//	char arr2[] = { "aeiou" };
	
//	delarr2(arr1, arr2);
//	printf("%s \n",arr1);
//	printf("%d \n",huiwen(123));
	printf("%d \n", mypow(5, 2));
	system("pause");
	return 0;
}