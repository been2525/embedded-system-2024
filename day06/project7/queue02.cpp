/*순차자료구조를 이용한 큐자료구조*/
#include <stdio.h>
#include <stdlib.h>
#define TRUE
#define FALSE

#define QSIZE 10
typedef struct
{
	int front;
	int rear;
	char queue[QSIZE];
}queue;
queue* create();
void enqueue(queue*, char);
char dequeue(queue*);
void printQueue(queue* pq);
void main()
{
	queue* qa = create();
	enqueue(qa, 'A');
	enqueue(qa, 'B');
	enqueue(qa, 'C');
	enqueue(qa, 'D');
	printf("추출된 값 : %c\n",dequeue(qa));
	printQueue(qa);
}

queue* create()
{
	//queue* newque = (queue*)malloc(sizeof(queue));
	queue* q = (queue*)malloc(sizeof(queue));
	if (q == NULL) exit(1);
	q->front = -1;
	q->rear = -1;

	return q;
}
void enqueue(queue* que, char ch)
{
	int rear = -1;
	if (rear >= QSIZE - 1)
	{
		printf("QUEUE Overf!!\n");
		return;
	}
	que -> queue[++(que -> rear)] = ch;
	printf("%c\n", ch);
	printf("입력완료\n");
}
char dequeue(queue* que)
{
	
	if (que -> front == que -> rear)
	{
		printf("QUEUE UnderF!!\n");
		return -1;
	}
	return que->queue[++(que->front)];
}

void printQueue(queue* pq)
{
	/*내가한거
	for (int i = 0; i < (sizeof(queue) / sizeof(int)); i++)
	{
		printf("%c\n", pq->queue[i]);
	}
	*///강사님이 하신것
	for (int i = pq->front + 1; i <= pq->rear; i++)
	{
		printf("%c\n", pq->queue[i]);
	}
	
}