#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int ary[])
{
	int a;
	a = ary[0];
	ary[0] = ary[1];
	ary[1] = a;
}
void main()
{
	int ary[] = {0, 0};
	printf("�μ��� �Է��Ͻÿ�.");
	scanf_s("%d, %d", &ary[0], &ary[1]);
	if (ary[0] > ary[1])
	{
		printf("ary[0] ���� �� Ů�ϴ�.\n");
		printf("ary[0] : %d\n, ary[1] : %d\n", ary[0], ary[1]);
	}
	else
	{
		swap(ary);
		printf("ary[1]���� �� Ů�ϴ�. ū���� ary[0]�� �ֽ��ϴ�.\n");
		printf("ary[0] : %d\n, ary[1] : %d\n", ary[0], ary[1]);

	}
}