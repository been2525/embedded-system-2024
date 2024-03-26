/*
파일제목 : firstproject.cpp

Created : 24-03-13

Author : 박성빈
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void main()
{
	char myinfo[1024] = "박성빈, 26, 남, 부산";
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
	printf("아이디와 비밀번호를 생성하세요.\n");
	printf("아이디: ");
	scanf("%s", id);
	printf("비밀번호 : ");
	scanf("%s", password);

	printf("------------------\n");
	printf("아이디와 비밀번호를 입력하세요.\n");
	printf("아이디: ");
	scanf("%s", id1);
	printf("비밀번호: ");
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
	printf("아이디 비번이 틀렸습니다\n");
	}
}