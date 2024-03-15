#include <stdio.h>

void main()
{
	int n1, n2;
	printf("정수 2개를 입력하세요: ");
	scanf("%d", &n1);
	scanf("%d", &n2);
	if(n1>n2)
	{
		printf("%d이 더 큽니다.\n", n1);
	}
	if(n1==n2)
	{
		printf("입력한 값이 같습니다.\n");
	}
	if(n1<n2)
	{
		printf("%d이 더 큽니다.\n", n2);
	}

}
