#include <stdio.h>
#include <stdlib.h>

void main()
{
	char name[50] = "�ڼ���, 26, ��\n";

	FILE* fp; //���� ������
	fp = fopen("importtest.txt", "w");	//���Ͽ���
	if (fp == NULL)
    {
		fprintf(stderr, "Error"); //�տ� f�� ���̸� ����������Ҷ� ���
		exit(1);
	}
	fprintf(fp, "%s", name);    //���Ϸ� ���
	//printf("%s", msg);
	//  printf("file descriptor: %d\n", fp);
	fclose(fp);
}
