/* �迭�� ���� */
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
	*/ // �����Ѱ� �ؿ��� ������� �ϽŰ�!
	if (top == (STACK_SZ - 1))
	{
		return TRUE; // ���� 1 ������ 0, ��ǻ�ʹ� 0�̾ƴϸ� �� ���̶�� �Ǵ�.
	}
	else
	{
		return FALSE;// 0�̳� 1���� true�� false�ص���
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