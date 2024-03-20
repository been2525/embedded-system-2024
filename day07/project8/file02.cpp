/*리눅스에서 하는법*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void main()
{
	char msg[] = "Linux Test!!";
	int fd;
	fd = open("test02.txt", O_CREAT | O_WRONLY);		//opend은 리눅스 전용
	if (fd == -1)
    {
	   printf("file open error");
	   exit(1);
	}
	printf("file descriptor: %d\n", fd);
	if (write(fd, msg, sizeof(msg)) == -1);
	{
		printf("file write error");
	}
	close(fd);

}
*/