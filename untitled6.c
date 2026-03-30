#include<stdio.h>
#include<stdlib.h>
typedef int Elemtype;
typedef enum {
	ERROR, OK
} Status;
typedef struct {
	Elemtype *data;
	int  length;
	int  maxsize;
} Sqlist;
Status Initilist(Sqlist *L, int n) {
	L->data = (Elemtype*)malloc(n * sizeof(Elemtype));
	(*L).maxsize = n;
	L->length = 0;
	return OK;
}

Status Listinsert(Sqlist *L, int i, Elemtype e) {
	if (i < 1 || i > L->length + 1)	return ERROR;
	for (int j = L->length; j >= i; j--) {
		L->data[j] = L->data[j - 1];
	}
	L->data[i - 1] = e;
	L->length++;
	return OK;
}

void PrintList(Sqlist L) {
	for (int i = 1; i <= L.length; ++i) {
		printf("%d ", L.data[i - 1]);
	}
	putchar('\n');
}

#define SIZE1 3
#define SIZE2 7
int main() {
	int array1[SIZE1] = {0, 2, 4}, array2[SIZE2] = {1, 3, 5, 7, 9, 11, 13};
	Sqlist L1, L2, L3;
	Initilist(&L1, 3);
	Initilist(&L2, 7);
	Initilist(&L3, 10);
	for (int i = 1; i <= SIZE1; ++i)
		Listinsert(&L1, i, array1[i - 1]);
	for (int i = 1; i <= SIZE2; ++i)
		Listinsert(&L2, i, array2[i - 1]);
	PrintList(L1);
	PrintList(L2);
	return 0;
}
