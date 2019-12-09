#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef struct node
{
	int gtime;
	int grade;
	int size;
	char * name;
	struct node * next;
}node;
int n = 0, S = 0, T = 0, X = 0, K = 0;

 node * line()
{
	 node * head=NULL;
	 node * p1;
	 node * p2,* p3, * q3;
	p2 = p1 = (node *)malloc(sizeof ( node));
	if (n == 0)
	{
		p1->gtime = 0;
		p1->grade = 0;
		p1->size = 0;
		scanf("%s", &p1->name);
		scanf("%d", &p1->next);
		head = p1;
		q3 = p3 = head;
		n = n + 1;
	}
	if (n != 0)
	while (p1->next != 0)
	{
		n = n + 1;
		p1 = (node *)malloc(sizeof(node));
		scanf("%d", &p1->gtime);
		scanf("%d", &p1->grade);
		scanf("%d", &p1->size);
		scanf("%s", &p1->name);
		scanf("%d\n", &p1->next);
		p2->next = p1;
		p2 = p1;
	}
	p1 = p2 = head;
	printf("链表创建完成!\n");
	return (head);
}

 void chushihua(node *head)
 {
 }


node * swap( node* R)
{
	 node *p1, *p2, *p3, *q3;
	p1 = p2 = p3 = q3 = R;
	while (p3->next != 0)
	{
		if (p3->gtime > p3->next->gtime)
		{
			if (q3->gtime>p3->next->gtime)
			{
				p1 = p3->next;//1 //2
				p3->next = p3->next->next;//2//3
				p1->next = p2->next;
				p2->next = p1;
				q3 = R;
				p2 = R;
			}
		}
		p2 = q3;
		q3 = q3->next;
		if (p3->gtime <= p3->next->gtime)
			p3 = p3->next;
	}
	return(R);
}


void grad( node *R1)
{
	node * p1, * p2,  * p3,* q3;
	p1 = p2 = p3 = q3 = R1;
	printf("优先级排序：\n");
	p3 = p3->next;
	while (R1->next != 0)
	{
		T = T + R1->next->size;
		printf("%s", R1->next->name);
		printf("%d\n", T);
		S = S + 1;
		if (S == 1)
			p3 = p3->next;
		R1->next = R1->next->next;
		if (p3->next != 0)
		while (p3->next->gtime <= T)
		{
			if (p3->grade>p3->next->grade)
			if (q3->grade>p3->next->grade)
			{
				p1 = p3->next;
				p3->next = p3->next->next;
				p1->next = p2->next;
				p2->next = p1;
				q3 = R1;
				p2 = R1;
			}
			p2 = q3;
			q3 = q3->next;
			if (p3->grade <= p3->next->grade)
				p3 = p3->next;
		}
	}
}                      //优先级算法




void Time( node * R2)
{
	 node * p1, * p2,  * p3, * q3;
	p1 = p2 = p3 = q3 = R2;
	printf("时间片轮转排序：\n");
	int i = n;
	while (i>1)
	{
		if (K == 0)
		if (p3->next != 0)
			K = K + 1;
		if (K == 1)
			p3 = p3->next;
		p3->size = p3->size - 1;
		T = T + 1;
		if (p3->size == 0)
		{
			printf("%s", p3->name);
			printf("%d\n", T);
			i = i - 1;
			if (p3->next != 0)
				p2->next = p3->next;
		}
		if ((p3->size != 0) && (p3->next != 0))
			p2 = p3;
		if ((p3->next == 0) && (i>1))
		{
			p3->next = R2;
			K = 1;
		}
		p3 = p3->next;
	}
}           //时间片轮转算法










void fcfs( node *R3)
{
	 node * p1, * p2, * p3, * q3;
	p1 = p2 = p3 = q3 = R3;
	printf("先到先服务排序：\n");
	while (p3->next != 0)
	{
		X = X + 1;
		if (X == 1)
			p3 = p3->next;
		T = T + p3->size;
		printf("%s", p3->name);
		printf("%d\n", T);
		p3 = p3->next;
	}
	T = T + p3->size;
	printf("%s", p3->name);
	printf("%d\n", T);
}                        //先来先服务算法



int main()
{
	node * R, * R1, * R2,  * R3;
	R = line();
	swap(R);
	R1 = swap(R);
	R2 = swap(R);
	R3 = swap(R);
	printf("1.优先级算法            ");
	printf("2.时间片轮转算法片\n");
	printf("3.先到先服务算法\n");
	int A;
	scanf("%d", &A);
	switch (A)
	{
	case '1': grad(R1); break;
	case '2': Time(R2); break;
	case '3': fcfs(R3); break;
	}
	printf("请输入你的选择：");
	scanf("%d", &A);

	return 0;
}

