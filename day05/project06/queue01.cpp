#include <stdio.h>

#define Q_SIZE 10
int rear = -1;
int front = -1;
int queue[Q_SIZE];

void enqueue(int _data) // 배열은 주소, 그리고 여기있는 거는 main에 있는거 복사해서 사용
{								// _rear = -1
	if (rear >= Q_SIZE - 1)
	{
		printf("QUEUE OverF!!\n");
		return;
	}
	queue[++rear] = _data;		//_rear = 0
	printf("입력완료\n");
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

void main()								//함수밖에서 쓸려면 포인터로 전해줘야함
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