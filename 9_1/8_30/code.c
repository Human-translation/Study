#define _CRT_SECURE_NO_WARNINGS
#include "code.h"

void chushihua(PList plist)
{
	assert(plist != NULL);
	plist->date = 0;
	plist->next = NULL;
}

Node *tianjiajiedian(int num)
{
	Node *p = (Node *)malloc(sizeof(Node));
	p->date = num;
	p->next = NULL;
	return p;
}

void print(PList plist)
{
	assert(plist != NULL);
	PList p = plist;
	p = p->next;
	while (p != NULL)
	{
		printf(" %d ", p->date);
		p = p->next;
	}
}

void touchafa(PList plist,int num)
{
	assert(plist != NULL);
	Node* pGet = tianjiajiedian(num);
	Node* p = plist;
	if (p->next != NULL)
	{
		pGet->next = p->next;
	}
	p->next = pGet;
}

void weichafa(PList plist, int num)
{
	assert(plist != NULL);
	Node* pGet = tianjiajiedian(num);
	Node* p = plist;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = pGet;
}

Node* FindK(PList plist,int k)
{
	assert(plist != NULL);
	Node* p = plist;
	Node* q = plist;
	int i = 0;
	while (i<k-1)
	{
		if (p->next == NULL)
			return 0;
		p = p->next;
		i++;
	}
	while (p->next != NULL)
	{
		p = p->next;
		q = q->next;
	}
	return q;
}

void Inversion(PList plist)
{
	assert(plist != NULL);
	Node* p = plist->next;
	Node* q = plist;
	plist->next = NULL;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		q->next = plist->next;
		plist->next = q;
	}
}

Node* FindMid(PList plist)
{
	assert(plist != NULL);
	Node* p = plist;
	Node* q = plist;
	while (p)
	{
		if (p->next != NULL)
		{
			p = p->next->next;
			q = q->next;
		}
		else
		{
			p = p->next;
			q = q->next;
		}

	}
	return q;
}