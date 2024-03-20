#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
//#include <unistd.h>
#include <string.h>

void main()
{
   char name[50] = "¹Ú¼ººó, 26, ³²\n";
   char copy[100];
   FILE * fp;
   int fd;
   fp = fopen("park.txt", "w");
   if (fp == NULL)
   {
	   fprintf(stderr, "ERROR");
	   exit(1);
	}
	fprintf(fp, "%s", name);
	fclose(fp);
	
	fp = fopen("park.txt", "r");
	if (fp == NULL)
	{
	    fprintf(stderr, "ERROR");
	    exit(1);
	}
	fscanf(fp, "%s", copy);
	fclose(fp);
	fd = open("parkcopy.txt", O_CREAT | O_WRONLY);
	if (fd == -1)
	{
		printf("file open error");
		exit(1);
	}
	printf("file descriptor: %d\n", fd);
	if (write(fd, copy, strlen(copy)) == -1);
	{
		printf("file write error");
	}
	close(fd);
	
}