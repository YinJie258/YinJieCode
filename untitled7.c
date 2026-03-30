#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef enum {
	ERROR, OK
} Status;
typedef struct {
	ElemType* data;
	int length;
	int maxsize;
} SqList;
Status initlist(SqList *L, int n) {
	L->data = (ElemType*)malloc(n * sizeof(ElemType));
	(*L).maxsize = n;
	L->length = 0;
	return OK;
}
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
int Merge(SqList L1, SqList L2, SqList *L3) {

	int i = 0;
	int j = 0;
	int k = 0;
	while (i < L1.length && j < L2.length) {
		if (L1.data[i] < L2.data[j]) {
			L3->data[k++] = L1.data[i++];
		} else if (L1.data[i] > L2.data[j]) {
			L3->data[k++] = L2.data[j++];
		} else {
			L3->data[k++] = L1.data[i];
			i++;
			j++;
		}
	}

	while (i < L1.length) {
		L3->data[k++] = L1.data[i++];	//TODO
	}
	while (j < L2.length) {
		L3->data[k++] = L2.data[j++]; //TODO
	}
	L3->length = k;
	return k;
}
void printflist(SqList *L) {
	for (int i = 0; i < L->length; i++) {
		printf("%d\t", L->data[i]);	//TODO
	}
}

#define SIZE 3
#define SIZE2 6
int main() {
	SqList L1, L2, L3;
	initlist(&L1, 3);
	initlist(&L2, 7);
	initlist(&L3, 10);
	int array1[SIZE] = {1, 2, 3};
	for (int i = 0; i < SIZE; ++i)
		ListInsert(&L1, i + 1, array1[i]);
	int array2[SIZE2] = {5, 6, 7, 8, 9, 10};
	for (int i = 0; i < SIZE2; ++i)
		ListInsert(&L2, i + 1, array2[i]);

	Merge(L1, L2, &L3);
	printflist(&L3);
}

