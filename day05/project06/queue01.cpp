#include <stdio.h>

#define Q_SIZE 10
int rear = -1;
int front = -1;
int queue[Q_SIZE];

void enqueue(int _data) // �迭�� �ּ�, �׸��� �����ִ� �Ŵ� main�� �ִ°� �����ؼ� ���
{								// _rear = -1
	if (rear >= Q_SIZE - 1)
	{
		printf("QUEUE OverF!!\n");
		return;
	}
	queue[++rear] = _data;		//_rear = 0
	printf("�Է¿Ϸ�\n");
}
int dequeue()
{
	if (front == rear)
	{
		printf("QUEUE UnderF!!\n");
		return -1;
	}
	return queue[++front];
}

void main()								//�Լ��ۿ��� ������ �����ͷ� ���������
{
//	int rear = -1;
//	int front = -1;
//	int queue[Q_SIZE];

	enqueue(10);
	enqueue(20);
	enqueue(30);

	printf("%d\n", dequeue()); //10
	printf("%d\n", dequeue()); //20
}