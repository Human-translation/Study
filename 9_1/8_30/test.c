#define _CRT_SECURE_NO_WARNINGS
#include "code.h"

int main()
{
	Node head;
	chushihua(&head);
	touchafa(&head, 12);
	touchafa(&head, 22);
	touchafa(&head, 32);
	touchafa(&head, 42);
	Inversion(&head);
	print(&head);
	system("pause");
	return 0;
}