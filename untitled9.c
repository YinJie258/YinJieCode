#include<stdio.h>
#include<stdlib.h>
typedef int Elemtype;
typedef enum 
{
	ERRORs,OK
}Status;
#define MAXSIZE 1000
typedef struct
{
	int front;
	int rear;
	Elemtype data[MAXSIZE];
}SqQueue;
Status InitSqQueue(SqQueue *s)
{
	s->front=s->rear=0;
	return OK;
}
Status EmptySqQueue(SqQueue *s)
{
	if(s->front==s->rear)
		return OK;
	else
		return ERRORs;
}
Status fullSqQueue(SqQueue *s)
{
	if(s->rear==MAXSIZE)
		return OK;
	else 
		return ERRORs;
}
Status enSqQueue(SqQueue *s,Elemtype e)
{
	if(fullSqQueue(s))
		return ERRORs;
	s->data[s->rear++]=e;
	return OK;
}
Status desQqueue(SqQueue *s,Elemtype *e)
{
	if(EmptySqQueue(s))
		return ERRORs;
	*e=s->data[s->front++];
	return OK;
}
Status print(SqQueue *s)
{
	int i=s->front;
	while(i<s->rear)
	{
		printf("%d",s->data[i++]);
	}
	printf("\n");
	return OK;
}
int main()
{
	SqQueue q;
	InitSqQueue(&q);
	
}
