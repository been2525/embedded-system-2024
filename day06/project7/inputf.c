#include <stdio.h>

char* input()
{
	static char str[10];
	static char* pstr = str; // static�� �ٿ��� �Ȼ����

	printf("�Է� > ");
	scanf("%s", str);
	
	return pstr;
}