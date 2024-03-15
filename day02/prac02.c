#include <stdio.h>

void main()
{
	int n1, n2;
	char c;
	printf("정수를 입력하세요.");
	scanf("%d %d", &n1, &n2);
	printf("연산자를 입력하세요.");
	getchar();
	scanf("%c", &c);

	if(c=='+')
	{
		printf("%d\n", n1+n2);
	}
	if(c=='-')
	{
		printf("%d\n", n1-n2);
	}
	if(c=='*')
	{
		printf("%d\n", n1*n2);
	}
	if(c=='/')
	{
		printf("%d\n", n1/n2);
	}
}
