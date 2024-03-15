#include <stdio.h>

void sumf(int n1,int n2)
{
	int sum = n1+  n2;
	printf("%d\n", sum);
	printf("더한값은 %d입니다.\n", sum);
}
void minusf(int n1, int n2)
{
	int sum = n1 - n2;
	printf("%d\n", sum);
	printf("뺀 값은 %d입니다.\n", sum);
}

void main()
{
	sumf(10, 20);
	minusf(20, 10);
	
	      //출력은 여기서한다.
}
