#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"

void maopao(int *a, int len)
{
	int i, j;
	int flag;
	int count = 0;
	for (i = len; i > 0; i--)
	{
		flag = 1;
		for (j = 1; j < i; j++)
		{
			if (a[j]<a[j-1])
			{
				int tmp = a[j-1];
				a[j-1] = a[j];
				a[j] = tmp;
				flag = 0;
			}
			count++;
		}
		if (flag)
		{
			return;
		}
	}
}

int get(int *a, int low, int high)
{
	int mid = (high - low) / 2;
	if (a[low] > a[high])
	{
		int x = a[low];
		a[low] = a[high];
		a[high] = x;
	}
	if (a[mid] > a[high])
	{
		int x = a[mid];
		a[mid] = a[high];
		a[high] = x;
	}
	if (a[mid] > a[low])
	{
		int x = a[mid];
		a[mid] = a[low];
		a[low] = x;
	}
	int tmp = a[low];
	while (low < high)
	{
		while (low < high && a[high] >= tmp)
		{
			high--;
		}
		a[low] = a[high];
		while (low < high && a[low] <= tmp)
		{
			low++;
		}
		a[high] = a[low];
	}
	a[low] = tmp;
	return low;
}

void InsertSort(int *a,int len)
{
	for (int i = 0; i<len; i++)
	{
		int j = i;
		int tmp = a[i];
		while (j>0 && tmp < a[j - 1])
		{
			a[j] = a[j - 1];
			j--;
		}
		a[j] = tmp;
	}
}

void kuaipai(int *a, int low ,int high,int len)
{
	if (high - low > 7)
	{
		int index = get(a, low, high);
		kuaipai(a, 0, index - 1, len);
		kuaipai(a, index + 1, high, len);
	}
	else
	{
		InsertSort(a,len);
	}
		
}

void xuanze(int *a ,int len)
{
	int min;
	for (int j = 0; j < len; j++)
	{
		min = j;
		for (int i = j; i < len; i++)
		{
			if (a[min] > a[i])
			{
				min = i;
			}
		}
		int tmp = a[j];
		a[j] = a[min];
		a[min] = tmp;
	}
}

void newkuaipai(int *a, int low, int high)
{
	Stack head;
	StackInit(&head);
	StackPush(&head, low);
	StackPush(&head, high);

	while (!StackEmpty(&head))
	{
		int end = StackTop(&head);
		StackPop(&head);
		int begin = StackTop(&head);
		StackPop(&head);
		int tmp = get(a, begin, end);
		if (begin < tmp-1)
		{
			StackPush(&head, begin);
			StackPush(&head, tmp - 1);
		}
		if (tmp + 1 < end)
		{
			StackPush(&head, tmp + 1);
			StackPush(&head, end);
		}
	}
}

int main()
{
	int a[] = { 5, 3, 8, 1, 6, 7, 9 ,42,11,13,10,4};
	int len = sizeof(a)/sizeof(a[0]);
//	maopao(a,len);
//	kuaipai(a, 0, len-1,len);
//	xuanze(a, len);
//	newkuaipai(a,0,len-1);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}