#include <stdio.h>

char* input()
{
	static char str[10];
	static char* pstr = str; // static을 붙여야 안사라짐

	printf("입력 > ");
	scanf("%s", str);
	
	return pstr;
}