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
Status LocateElem(const SqList * const L, int e, ElemType * i) {
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

int main() {
	SqList L;
	ElemType e;
	initlist(&L, 10);
	ListInsert(&L, 1, 4);
	ListInsert(&L, 2, 11);
	ListInsert(&L, 2, 2);
//	ListDelete(&L, 2, &e);
//	ListDelete(&L, 2, &e);
//	ListDelete(&L, 1, &e);
	PrintList(L);
	return 0;
}


/*Status ListInsert(SqList * L, int i, ElemType  e) {

int j;
//下标
for (j = L->length - 1; j >= i - 1; j--) {
L->data[j + 1] = L->data[j];
}

//位序
//for (int j = L->length; j >= i; --j) {
//	L->data[j] = L->data[j - 1];
//}

L->data[i - 1] = e;
L->length++;
return OK;
}
*/

//Status ListDelete(SqList * L, int i, ElemType * e) {
//	int j;
//	*e = L->data[i - 1];
//	//下标
//	for (j = i - 1; j < L->length - 1; j++) {
//		L->data[j] = L->data[j + 1];
//	}
//	/*
//	//位序
//	for (j = i; j < L->length; j++) {
//		L->data[j] = L->data[j - 1];
//	}
//	*/
//	L->length--;
//	return OK;
//}
