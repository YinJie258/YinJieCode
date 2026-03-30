#include <stdio.h>
#include<stdlib.h>
typedef enum {
	OK, ERROR
} Status;
typedef int elemtype;
typedef struct LNode {
	elemtype data;
	struct LNode *next;
} LNode,*Linklist;
Status Listinsert (Linklist L, int e, elemtype pos) {
	if (pos < 1) {
		return ERROR;
	}
	LNode *p = L;
	LNode *newnode;
	for (int i = 0; p && i < pos - 1; ++i)	p = p->next;

	newnode = (LNode*)malloc(sizeof(LNode));
	newnode->data = e;
	newnode->next = p->next;
	p->next = newnode;

	return OK;
}

Status InitList(Linklist * L) {
	(*L) = (Linklist)malloc(sizeof(LNode));
	(*L)->next = NULL;
	return OK;
}

void PrintList(Linklist L) {
	if (L == NULL)	return;
	LNode * cur = L->next;
	while (cur) {
		printf("%d -> %p\n", cur->data, cur);
		cur = cur->next;
	}
	putchar('\n');
}
Status Getelem(Linklist L, int n, elemtype * e) {
	if (n < 1) {
		return ERROR;
	}
	Linklist p;
	p = L;
	for (int i = 0; p && i < n; i++) {
		p = p->next;	//TODO
	}
	if (!p)	return ERROR;
	*e = p->data;
	return OK;
}

Status LocateElem(Linklist L, elemtype e, int * n) {
	Linklist p;
	p = L->next;
	*n = -1;
	for (int i = 0; p ; i++) {
		if (p->data == e)	{
			*n = i + 1;
			return OK;
		}
		p = p->next;
	}

	return ERROR;
}
int main() {
	int m;
	Linklist L;
	InitList(&L);
	Listinsert(L, 1, 1);
	Listinsert(L, 2, 2);
	Listinsert(L, 3, 3);
	Listinsert(L, 4, 4);
	if (LocateElem(L,22, &m) == OK)
		printf("%d\n", m);
	PrintList(L);
}
