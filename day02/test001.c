#include <stdio.h>
#define MAX 20

void main()
{
	int arr[MAX];
	int num;
	
	printf("Input Data>>");
	scanf("%d", &num);
	printf("배열입력\n");
	for (int i=0;i<num;i++)
	{
		printf("입력하세요.: ");
		scanf("%d", &arr[i]);
	}
	for (int i = num-1;i>=0;i--)
	{
		printf("%d", arr[i]);
	}
	printf("\n");
}
