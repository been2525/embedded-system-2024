/*
�������� : firstproject.cpp

Created : 24-03-13

Author : �ڼ���
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void main()
{
	char myinfo[1024] = "�ڼ���, 26, ��, �λ�";
	int fd;
	char id[20];
	char password[20];
	char id1[20];
	char password1[20];
	fd = open("myinfo.txt", O_CREAT | O_RDWR | O_TRUNC, 0600);

	if (fd < 0)
	{
		printf("Open Error\n");
	}
	if (write(fd, myinfo, strlen(myinfo)) < 0)
	{
		printf("Write Error\n");
	}
	close(fd);
	printf("���̵�� ��й�ȣ�� �����ϼ���.\n");
	printf("���̵�: ");
	scanf("%s", id);
	printf("��й�ȣ : ");
	scanf("%s", password);

	printf("------------------\n");
	printf("���̵�� ��й�ȣ�� �Է��ϼ���.\n");
	printf("���̵�: ");
	scanf("%s", id1);
	printf("��й�ȣ: ");
	scanf("%s", password1);

	if ((strcmp(id, id1) == 0) && (strcmp(password, password1) == 0))
	{
		fd = open("myinfo.txt", O_RDONLY);
		if (fd < 0)
		{
			printf("Open Error\n");
		}
		if (read(fd, myinfo, 1024) < 0)
		{
			printf("Read Error");
		}
		printf("%s\n", myinfo);
		close(fd);
	}
	else
	{
	printf("���̵� ����� Ʋ�Ƚ��ϴ�\n");
	}
}