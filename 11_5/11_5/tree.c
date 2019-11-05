#define _CRT_SECURE_NO_WARNINGS
#include "tree.h"

void HeapInit(Heap* hp,HPDataType* arr,int n)
{
	hp->a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	int i;
	for (i = 0; i < n; i++)
	{
		hp->a[i] = arr[i];
	}
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		ShiftDown(hp->a, n, i);
	}
	hp->size = hp->capacity = n;
}


void Swap(HPDataType* pa, HPDataType* pb)
{
	HPDataType pc = *pa;
	*pa = *pb;
	*pb = pc;
}

void ShiftDown(HPDataType* arr, int n, int root)
{
	int parent = root;
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child + 1] > arr[child])
			++child;
		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapDestory(Heap* hp);

void HeapPush(Heap* hp, HPDataType x);

void HeadPop(Heap* hp);

HPDataType HeapTop(Heap* hp);

int HeapSize(Heap* hp);

int HeapEmpty(Heap* hp);

void HeapSort(int* a, int n);

void HeapPrint(Heap* hp)
{
	for (int i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->a[i]);
	}
	printf("\n");
}

void TestHeap()
{
	int a[] = { 1, 5, 3, 8, 7, 6 };
	Heap hp;
	HeapInit(&hp ,a , sizeof(a)/sizeof(a[0]));
	HeapPrint(&hp);
}