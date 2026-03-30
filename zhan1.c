//栈
#include<stdio.h>
#define MaxSize 10
typedef int Elemtype;
typedef struct {
	Elemtype data[MaxSize];
	int top;
} Sqstack;
typedef enum {
	ERROR, OK
} Status;
Status Initstack(Sqstack *s) {
	s->top = -1;
	return OK;
}
Status emptystack(Sqstack *s) {
	if (s->top == -1) {
	}
	return ERROR;
}
Status Fullstack(Sqstack *s) {
	if (s->top == MaxSize - 1) {	//TODO
	}
	return ERROR;
}
Status pushstack(Sqstack *s, Elemtype val) {
	if (s->top == MaxSize - 1) {
		return ERROR;
	}
	s->data[++(s->top)] = val;//TODO
	return OK;
}
Status popstack(Sqstack *s, Elemtype *val) {
	if (s->top == -1) {
		return ERROR;	
	}
	*val = s->data[s->top--];//TODO
	return OK;
}
Status gaintopelementstack(Sqstack *s, Elemtype *val) {
	if (s->top == -1) {
		return ERROR;
		*val = s->data[s->top];//TODO
	}
	return OK;
}
void printstack(Sqstack *s) {
	if (s->top == -1) {
		return ;	//TODO
	}
	int i;
	for ( i = 0; i <= s->top; i++) {
		printf("%d", s->data[i]);
	}
	printf("\n");
}
int main() {
	Sqstack s;
	Initstack(&s);
	pushstack(&s, 10);
	pushstack(&s, 20);
	pushstack(&s, 40);
	printstack(&s);
	return 0;
}
