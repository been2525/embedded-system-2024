#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	char id[30];
	char password[30];

	printf("아이디: ");
	scanf(" %s", id);
//	getchar();
	printf("비밀번호: ");
	scanf(" %s", password);

	printf("%s %s ", id, password);

	return 0;

}
/*
#include <stdio.h>

int main(void)
{
	char id[20]; // 아이디를 저장할 문자열 배열
	char password[20]; // 비밀번호를 저장할 문자열 배열

	printf("아이디: ");
	fgets(id, sizeof(id), stdin); // fgets 함수를 사용하여 아이디 입력받음

	printf("비밀번호: ");
	fgets(password, sizeof(password), stdin); // fgets 함수를 사용하여 비밀번호 입력받음

	printf("입력된 아이디: %s", id);
	printf("입력된 비밀번호: %s", password);

	return 0;
}*/
