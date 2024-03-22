#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SZ 20

typedef struct
{
	char id[BUF_SZ];
	int price;
	char title[BUF_SZ];
	char author[BUF_SZ];
	int borrow;
}Book;

int main(void)
{

	//char id[BUF_SZ];
	//int price = 0;
	//char title[BUF_SZ];
	//char author[BUF_SZ];
	int menunum = 0;
	char findbook[BUF_SZ];
	char delbook[BUF_SZ];
	int numproduct = 0;
	Book book[BUF_SZ];

	while (1)
	{
		printf("****�޴�****\n");
		printf("1.��������(���)\n2.�����˻�\n3.��������\n4.�������\n0.����\n");
		printf("> ");
		scanf_s("%d", &menunum);
		if (menunum == 0)
		{
			printf("���α׷��� �����մϴ�.\n");
			exit(0);
		}
		else if (menunum == 1)
		{
			printf("���̵� �Է��ϼ���: ");
			scanf("%s", book[numproduct].id);
			printf("������ �Է��ϼ���: ");
			scanf("%d", &book[numproduct].price);
			printf("������ �Է��ϼ���: ");
			scanf("%s", book[numproduct].title);
			printf("���ڸ� �Է��ϼ���: ");
			scanf("%s", book[numproduct].author);
			printf("�뿩���ɿ��θ� �Է��ϼ���.\n");
			printf("�����ϸ� 1, �Ұ����̸� 0\n");
			printf("> ");
			scanf("%d", &book[numproduct].borrow);
			//strcpy(book[numproduct].id, id);
			//strcpy(book[numproduct].author, author);
			//strcpy(book[numproduct].title, title);
			//book[numproduct].price = price;
			printf("���̵� : %s, ����: %d, ����: %s, ����: %s �뿩����: %d\n", book[numproduct].id, &book[numproduct].price, book[numproduct].title, book[numproduct].author, &book[numproduct].borrow);
			numproduct++;
		}
		else if (menunum == 2)
		{
			printf("ã�� ������ �̸��� �Է��ϼ���\n");
			printf("> ");
			scanf("%s", findbook);
			int search = 0;
			int pos = 1;
			for (int i = 0; i < numproduct; i++)
			{
				if (strcmp(book[i].title, findbook) == 0)
				{
					if ((book[i].borrow) == pos)
					{
						printf("�뿩�� �����մϴ�.");
						search = 1;
					}
				}
			}
			if (!search)
			{
				printf("�뿩�� �Ұ����մϴ�.");
			}
		}
		else if (menunum == 3)
		{
			printf("������ ������ �̸��� �Է��ϼ���\n");
			printf("> ");
			scanf("%s", delbook);
			int found = 0;
			for (int i = 0; i < numproduct; i++)
			{
				if (strcmp(delbook, book[i].title) == 0)
				{
					for (int j = i; j < numproduct - 1; j++)
					{
						book[j] = book[j + 1];
					}
					numproduct--;
					found = 1;
					printf("������ �����Ǿ����ϴ�");
					exit(0);
				}
			}
			if (!found)
			{
				printf("������ ������ ã�� �� �����ϴ�.\n");
			}
		}
		else if (menunum == 4)
		{
			for (int i = 0; i < numproduct; i++)
			{
				printf("����: %s, id: %s, ����: %d, ����: %s\n", book[i].author, book[i].id, book[i].price, book[i].title);
			}
		}
	}
}