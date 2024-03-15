#include <stdio.h>

void main()
{
	int num;
	printf("숫자를 입력하시오.: ");
	scanf("%d", &num);
	for(int i = 0;i<num;i++)
	{
		for(int j = 0;j<num-i;j++)
		{
			printf(" ");
		}
		for(int j =0;j<=(i*2);j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
