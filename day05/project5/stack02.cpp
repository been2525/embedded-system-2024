/*���Ḯ��Ʈ�� ����*/
#include <stdio.h>

#define STACK_SZ 10
typedef struct STACK
{
	int buf[STACK_SZ]; // �����͸� ���� �� �� �ִ°�, c������ ����ü ���ּ� �迭�� ũ�⸦ ����Ѽ� ����.
	int top;
}stack;

void push(stack*, int);
int pop(stack*);

void main()
{
	stack s; // ���� ����ü�� ����
	s.top = -1; //top�� �ʱ�ȭ
	push(&s, 10);
	push(&s, 20);				// &����ϴ� ������ �ش� �Լ��� ���ñ���ü�� �ּҸ� �����ϱ� ���ؼ�
	printf("����� �� : %d\n", pop(&s));
	printf("����� �� : %d\n", pop(&s));
	
}
void push(stack* pstk, int value)
{
	//stack* newstack = (stack*)malloc(sizeof(stakc));
	if (pstk -> top < STACK_SZ - 1)			// �̰Ż���ϴ� ���� ->����ó������.
	{
		pstk->top++;
		pstk->buf[pstk -> top] = value;
		printf("%d\n", value);
	}
}

int pop(stack* pstk)
{
   if (pstk->top < 0)
   {
	    printf("������ ��� �ֽ��ϴ�.\n");
	    return -1;
	}
	int del = pstk->buf[pstk->top];
    pstk->top--;
    return del;
}
