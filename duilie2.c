#include<stdio.h>
#include<stdbool.h>

#define MAXSIZE 100
typedef int Elemtype;
typedef enum {
	ERROR, OK
} status;

typedef struct {
	int front;
	int rear;
	Elemtype data[MAXSIZE];
} SqQueue;

status InitQueue(SqQueue *s) {
	s->front = s->rear = 0;
	return OK;
}

bool IsFull(SqQueue *s) {
	if ((s->rear + 1) % MAXSIZE == s->front)
		return true;
	return false;
}

bool IsEmpty(SqQueue *s) {
	if (s->front == s->rear)
		return true;
	return false;
}

status GetQueue(SqQueue *s, Elemtype * e) {
	if (IsEmpty(s))
		return ERROR;
	*e = s->data[s->front];
	return OK;
}

status EnQueue(SqQueue *s, Elemtype e) {
	if (IsFull(s))
		return ERROR;
	s->data[s->rear] = e;
	s->rear = (s->rear + 1) % MAXSIZE;
	return OK;
}
status DeQueue(SqQueue *s, Elemtype *e) {
	if (IsEmpty(s))
		return ERROR;
	*e = s->data[s->front];
	s->front = (s->front + 1) % MAXSIZE;
	return OK;
}

int QueueLength(SqQueue *s) {
	return (s->rear - s->front + MAXSIZE) % MAXSIZE;
}

status PrintQueue(SqQueue *s) {
	if (IsEmpty(s))
		return ERROR;
	for (int j = s->front;j!=s->rear; j = (j + 1) % MAXSIZE)
		printf("%d ", s->data[j]);
	printf("\n");
	return OK;
}

int main() {
	SqQueue s;
	Elemtype e;

	InitQueue(&s);
	EnQueue(&s, 1);
	EnQueue(&s, 2);
	PrintQueue(&s);
	GetQueue(&s, &e);
	printf("%d \n", e);
	DeQueue(&s, &e);
	printf("%d \n", e);
	PrintQueue(&s);
}


