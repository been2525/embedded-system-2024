#include <stdio.h>

int lSearch(int _ary[], int _size, int _num);

void main()
{
	int ary[] = { 3,5,2,4,9,8,1 };
	int ridx;
	int size = sizeof(ary) / sizeof(int);
	ridx = lSearch(ary, size, 3);
	if (ridx == -1)
    {
	    printf("ã�� ���Ұ� �����ϴ�.");
	}
	else
	{
		printf("ã�� �ε��� : %d\n", ridx);
	}
}

int lSearch(int _ary[], int _size, int _num)
{
	for (int i = 0; i < _size; i++)
	{
		if (_ary[i] == _num)
		{
			return i;
		}
	}
	return -1;
}