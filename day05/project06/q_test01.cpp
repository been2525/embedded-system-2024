#include <stdio.h>

void main()
{
	int ary[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int queue[20];
	int rear = 0, front = 0;		// �Ա�(rear)�� �����ϰ�, �ⱸ(front)�� ���ؼ� �����Ѵ�.
	// ť�� ����
	int size = sizeof(ary) / sizeof(int);
	for (int i = 0; i < size; i++)
	{
		queue[rear++] = ary[i];
		printf("%d", queue[rear++]);
		
	}
	printf("QUEUE OverF");
	//ť���� ����
	for (int i = 0; i < size; i++)
	{
		printf("%d\n", queue[front++]);
	}
	
}