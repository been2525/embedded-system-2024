#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void main()
{
	int fd1, fd2;
	char str[] = "wonderful day!!";
	char buf[1024];
	// 0600�� 4�ڸ��� ǥ���ؾ��� 3�ڸ��� �ϸ� ������ , 0600�� ������ �ο��ϱ� ���ؼ� ���ִ� ��
	fd1 = open("mytest.txt", O_CREAT | O_RDWR | O_TRUNC, 0600); //6�� rw(�а��⸸) 7�� rwx(�а���������) 2���� ls -l������ ���� 3�ڸ��� 421
	if (fd1 < 0)		// �̷��� ������ ���� Ȯ���� ����
	{
		printf("Open Error");
	}
	if (write(fd1, str, strlen(str)) < 0)
	{
		printf("Write Error");
	}
	close(fd1);
	fd1 = open("mytest.txt", O_RDONLY);
	if (read(fd1, buf, 1024)) < 0)
	{
		printf("Read Error");
	}
	printf("%s\n", buf);
	close(fd1);

}