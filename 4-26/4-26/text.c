#include <stdio.h>

int main()
{
	int a[10];
	int i;
	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", &a[i]);
	}
	int max = a[0];
	for (i = 0; i < 10; i++)
	{

		if (max < a[i])
			max = a[i];
	}
	printf("%d\n", a[i]);
	system("pause");

}