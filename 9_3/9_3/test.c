#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int kuaipai(int *str,int left,int right)
{
	int tmp = str[left];
	while (left < right)
	{
		while (left < right && str[right] >= tmp)
		{
			right--;
		}
		if (left >= right)
		{
			break;
		}
		else
		{
			str[left] = str[right];
		}
		while (left < right && str[left] <= tmp)
		{
			left++;
		}
		if (left >= right)
		{
			break;
		}
		else
		{
			str[right] = str[left];
		}
	}
	str[left] = tmp;
	return left;
}

int findk(int *str,int len,int k)
{
	int left = 0;
	int right = len - 1;
	int par = kuaipai(str, left, right);
	while (par != k)
	{
		if (par < k)
		{
			left = par + 1;
			par = kuaipai(str, left, right);
		}
		if (par > k)
		{
			right = par - 1;
			par = kuaipai(str, left, right);
		}
	}
	return par;
}

int findmid(int *str, int len)
{
	int left = 0;
	int right = len - 1;
	int par = kuaipai(str, left, right);
	int midlen = len / 2;
	while (par != midlen)
	{
		if (par < midlen)
		{
			left = par + 1;
			par = kuaipai(str, left, right);
		}
		if (par > midlen)
		{
			right = par - 1;
			par = kuaipai(str, left, right);
		}
	}
	return par;
}

int maxsubarray(int *str,int len)
{
	int sum = 0;
	int max = 0;
	int i = 0;
	while (i < len)
	{
		sum = sum + str[i];
		if (sum < 0)
		{
			sum = 0;
		}
		max = (max>sum) ? max : sum;
		i++;
	}
	return max;
}

int main()
{
	int arr[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int max = maxsubarray(arr,len);
	printf("%d \n",max);
	system("pause");
	return 0;
}