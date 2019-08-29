#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#if 0
#define ROW 4
#define COL 4
void search(int arr[ROW][COL], int *row, int *col, int key)
{
	int x = 0;
	int y = COL-1;
	while (x<ROW || y>=0)
	{
		if (arr[x][y] > key)
		{
			y--;
		}
		if (arr[x][y] < key)
		{
			x++;
		}
		if (arr[x][y] == key)
		{
			*row = x;
			*col = y;
			break;
		}
	}
}
int main()
{
	int arr[ROW][COL] = {
		1, 2,  8,  9,
		2, 4,  9, 12,
		4, 7, 10, 13,
		6, 8, 11, 15
	};
	int x = -1;
	int y = -1;
	search(arr, &x, &y ,5);
	printf("%d %d \n", x, y);
	system("pause");
	return 0;
}


unsigned int numofone(int num)
{
	int count = 0;
	while (num)
	{
		num = num&(num - 1);
		++count;
	}
	return count;
}

int main()
{
	int ret = numofone(25);  // 0001 1001
	printf("%d \n", ret);
	system("pause");
	return 0;
}


int Fibonacci(int n)
{
	if (n == 0)
	{
		return 0;
	}
	int f1 = 1;
	int f2 = 1;
	int f3 = 1;
	while (n > 2)
	{
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
		n--;
	}
	return f3;
}

int main()
{
	int ret = Fibonacci(5);  //1 1 2 3 5 8 13 21
	printf("%d \n", ret);
	system("pause");
	return 0;
}
#endif

char Transfor(char *arr, int len)
{
	char *str = arr;
	int count = 0;
	int p;
	int q;
	while (*str != '\0')
	{
		if (*str == ' ')
		{
			count++;
		}
		str++;
	}
	p = len;
	q = len + count * 2;
	while (p >= 0 && q>p)
	{
		if (arr[p] == ' ')
		{
			arr[q--] = '0';
			arr[q--] = '2';
			arr[q--] = '%';
		}
		else
		{
			arr[q--] = arr[p];
		}
		p--;
	}
}
int main()
{
	char arr[20] = { "abc dfx yz" };
	int len = strlen(arr);
	Transfor(arr, len);
	printf("%s \n", arr);
	system("pause");
	return 0;
}