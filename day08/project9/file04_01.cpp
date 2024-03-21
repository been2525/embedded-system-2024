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
	// 0600은 4자리로 표현해야함 3자리로 하면 에러뜸 , 0600은 권한을 부여하기 위해서 써주는 것
	fd1 = open("mytest.txt", O_CREAT | O_RDWR | O_TRUNC, 0600); //6은 rw(읽고쓰기만) 7은 rwx(읽고쓰고실행까지) 2진수 ls -l누르면 앞쪽 3자리가 421
	if (fd1 < 0)		// 이러면 에러를 잡을 확률이 높음
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