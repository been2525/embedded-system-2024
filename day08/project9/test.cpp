#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	char id[30];
	char password[30];

	printf("���̵�: ");
	scanf(" %s", id);
//	getchar();
	printf("��й�ȣ: ");
	scanf(" %s", password);

	printf("%s %s ", id, password);

	return 0;

}
/*
#include <stdio.h>

int main(void)
{
	char id[20]; // ���̵� ������ ���ڿ� �迭
	char password[20]; // ��й�ȣ�� ������ ���ڿ� �迭

	printf("���̵�: ");
	fgets(id, sizeof(id), stdin); // fgets �Լ��� ����Ͽ� ���̵� �Է¹���

	printf("��й�ȣ: ");
	fgets(password, sizeof(password), stdin); // fgets �Լ��� ����Ͽ� ��й�ȣ �Է¹���

	printf("�Էµ� ���̵�: %s", id);
	printf("�Էµ� ��й�ȣ: %s", password);

	return 0;
}*/
