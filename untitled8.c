#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;
typedef int Status;
enum {ERROR, OK};
typedef struct {
	ElemType * data;
	int length;
	int maxsize;
} SqList;

//初始化线性表
Status initlist(SqList *L, int n) {
	L->data = (ElemType*)malloc(n * sizeof(ElemType));
	(*L).maxsize = n;
	L->length = 0;
	return OK;
}

//销毁线性表
void Destorylist(SqList *L) {
	free(L->data);
	L->data = NULL;
	L->length = 0;
	L->maxsize = 0;
}
//线性表重置为空表
void Clearlist(SqList *L) {
	L->length = 0;
}
//判断线性表是否为空表
bool listempty(SqList *L) {
	if (L->length == 0) {
		return true;
		//TODO
	}
	return false;
}
//线性表上元素的个数
ElemType Listlength(SqList *L) {

	return L->length;
}

//返回第 i(位序) 个元素的值
Status GetElem(SqList *L, int i, int *e) {
	if (i < 1 || i > L->length) {
		return ERROR;	//TODO
	}
	*e = L->data[i - 1];
	return OK;
}

//使用 i 来返回第一个值的位序
Status LocateElem(const SqList * const L, ElemType e, int * i) {
	*i = -1;
	for (int j = 0; j < L->length; j++) {
		if (L->data[j] == e) {
			*i = j + 1;//TODO
			return OK;
		}
	}

	return ERROR;
}

//
Status ListInsert(SqList *L, int i, ElemType e) {
	//位序
	if (L->length == L->maxsize) {
		return ERROR;
	}
	if (i < 1 || i > L->length + 1) {
		return ERROR;
		//TODO
	}
	for (int j = L->length; j >= i; j--) {
		L->data[j] = L->data[j - 1];
	}
	L->data[i - 1] = e;
	L->length++;
	return OK;
}

void PrintList(SqList L) {
	for (int i = 0; i < L.length; ++i) {
		printf("%d ", L.data[i]);
	}
	putchar('\n');
}
void Merge(SqList *L1, SqList L2 ) {
	int m, n;
	int e, j;
	m = L1->length;
	n = L2.length;
	for (int i = 1; i <= n; i++) {
		GetElem(&L2, i, &e);
		if (LocateElem(L1, e, &j) == ERROR) {
			ListInsert(L1, ++m, e);	//TODO
		}//TODO
	}
}
int main() {
	SqList L1, L2;
	initlist(&L1, 8);
	initlist(&L2, 5);
	int arr1[] = {1, 2, 3};
	int i, j;
	for (i = 0; i < 3; i++) {
		ListInsert(&L1, i + 1, arr1[i]);
	}
	int arr2[] = {1, 2, 3, 4, 5};
	for (j = 0; j < 5; j++) {
		ListInsert(&L2, j + 1, arr2[j]); //TODO
	}
	Merge(&L1, L2);
	PrintList(L1);
}
