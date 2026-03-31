// 栈
#include <stdbool.h>
#include <stdio.h>

#define MAXSIZE 1024
typedef int Elemtype;
typedef struct {
  Elemtype data[MAXSIZE];
  int top;
} SqStack;

typedef enum { ERROR, OK } Status;

Status InitStack(SqStack* S) {
  S->top = -1;
  return OK;
}

bool IsEmpty(SqStack* S) {
  if (NULL == S || S->top == -1) {
    return true;
  }
  return false;
}

bool IsFull(SqStack* S) {
  if (NULL == S || S->top == MAXSIZE - 1) {
    return true;
  }
  return false;
}

Status Push(SqStack* S, Elemtype val) {
  if (IsFull(S)) {
    return ERROR;
  }

  S->data[++S->top] = val;
  return OK;
}

Status Pop(SqStack* S, Elemtype* val) {
  if (IsEmpty(S)) {
    return ERROR;
  }

  *val = S->data[S->top--];
  return OK;
}

Status GetTop(SqStack* S, Elemtype* val) {
  if (IsEmpty(S) || NULL == val) {
    return ERROR;
  }

  *val = S->data[S->top];
  return OK;
}

void PrintStack(SqStack* S) {
  if (IsEmpty(S)) {
    printf("栈为空\n");
    return;
  }

  for (int i = 0; i <= S->top; i++) {
    printf("%d ", S->data[i]);
  }

  putchar('\n');
}

int StackLength(SqStack* S) {
  if (NULL == S) {
    return 0;
  }

  return S->top + 1;
}

int main() {
  SqStack S;
  InitStack(&S);

  // 压入50个元素
  for (int i = 1; i <= 50; ++i) {
    Push(&S, i);
  }

  printf("----------TEST----------\n");
  printf("栈长度为: %d\n", StackLength(&S));
  printf("栈是否为空: %s\n", IsEmpty(&S) ? "空" : "非空");
  printf("栈是否为满: %s\n", IsFull(&S) ? "满" : "非满");
  printf("栈中元素:\n");
  PrintStack(&S);

  Elemtype e;
  // 退栈20个元素
  printf("退栈元素为:\n");
  for (int i = 1; i <= 20; i++) {
    Pop(&S, &e);
    printf("%d ", e);
  }

  printf("\n栈长度为: %d\n", StackLength(&S));
  printf("栈是否为空: %s\n", IsEmpty(&S) ? "空" : "非空");
  printf("栈是否为满: %s\n", IsFull(&S) ? "满" : "非满");
  printf("栈中元素:\n");
  PrintStack(&S);

  // 压入剩下元素
  int i = 0;
  while (!IsFull(&S)) Push(&S, i);

  printf("栈是否为满: %s\n", IsFull(&S) ? "满" : "非满");
  printf("----------END----------\n");
  return 0;
}
