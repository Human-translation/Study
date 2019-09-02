#define _CRT_SECURE_NO_WARNINGS
#include "code.h"

int main()
{
	Node head;
	Node *ret;
	chushihua(&head);
	weichafa(&head, 12);
	weichafa(&head, 22);
	weichafa(&head, 32);
	weichafa(&head, 42);

//	Inversion(&head);
	print(&head);
	ret = FindMid(&head);
	printf("%d \n", *ret);
	system("pause");
	return 0;
}