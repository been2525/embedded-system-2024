/* 배열로 구현 */
#include <stdio.h>
#define STACK_SZ  10
#define TRUE 1
#define FALSE 0

int stack[STACK_SZ];
int top = -1;
void push();
int pop();
int isFull();
int isEmpty();

void main()
{
	push(3);
	push(5);
	push(10);

	printf("%d\n", pop());
	printf("%d\n", pop());
}

void push(int data)
{
	if (isFull())
	{
		printf("stack overflow\n");
		return;
	}
	stack[++top] = data;
	
}

int pop()
{
	if (isEmpty())
	{
		printf("stack underflow\n");
		return -1;
	}
	return stack[top--];
	//top--;
}

int isFull()
{
	/*
	if (top == (STACK_SZ -1)
	{
		printf("stack overflow!!");
		return ;
	}
	*/ // 내가한거 밑에는 강사님이 하신것!
	if (top == (STACK_SZ - 1))
	{
		return TRUE; // 참은 1 거짓은 0, 컴퓨터는 0이아니면 다 참이라고 판단.
	}
	else
	{
		return FALSE;// 0이나 1말고 true나 false해도됨
	}
}

int isEmpty()
{
	if (top <= -1)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}