#ifndef __code_

#define __code_
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#endif //__code_

typedef struct Node
{
	int date;
	struct Node *next;
}Node,*PList;

void chushihua(PList plist);
Node *tianjiajiedian(int num);
void touchafa(PList plist, int num);
void weichafa(PList plist, int num);
void Inversion(PList plist);
Node* FindK(PList plist);
Node* FindMid(PList plist);
