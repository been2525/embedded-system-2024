#include <stdio.h>
#include <stdlib.h>

void main()
{
	char name[50] = "박성빈, 26, 남\n";

	FILE* fp; //파일 포인터
	fp = fopen("importtest.txt", "w");	//파일오픈
	if (fp == NULL)
    {
		fprintf(stderr, "Error"); //앞에 f를 붙이면 파일입출력할때 사용
		exit(1);
	}
	fprintf(fp, "%s", name);    //파일로 출력
	//printf("%s", msg);
	//  printf("file descriptor: %d\n", fp);
	fclose(fp);
}
