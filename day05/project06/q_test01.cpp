#include <stdio.h>

void main()
{
	int ary[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int queue[20];
	int rear = 0, front = 0;		// 입구(rear)로 삽입하고, 출구(front)를 통해서 삭제한다.
	// 큐에 삽입
	int size = sizeof(ary) / sizeof(int);
	for (int i = 0; i < size; i++)
	{
		queue[rear++] = ary[i];
		printf("%d", queue[rear++]);
		
	}
	printf("QUEUE OverF");
	//큐에서 삭제
	for (int i = 0; i < size; i++)
	{
		printf("%d\n", queue[front++]);
	}
	
}