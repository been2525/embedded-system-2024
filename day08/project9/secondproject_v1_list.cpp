//���Ḯ��Ʈ�� �����ϱ�
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SZ 20

typedef struct BOOK
{
	char id[BUF_SZ];
	int price;
	char title[BUF_SZ];
	char author[BUF_SZ];
	char isbn[BUF_SZ];
	char publish[BUF_SZ];
	
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
			printf("���α׷��� �����մϴ�.");
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
			printf("ISBN�� �Է��ϼ���: ");
			scanf("%s", book[numproduct].isbn);
			printf("���ǻ縦 �Է��ϼ���: ");
			scanf("%s", book[numproduct].publish);
			//strcpy(book[numproduct].id, id);
			//strcpy(book[numproduct].author, author);
			//strcpy(book[numproduct].title, title);
			//book[numproduct].price = price;
			printf("���̵� : %s, ����: %d, ����: %s, ����: %s, ISBN: %s, ���ǻ�: %s\n", book[numproduct].id, &book[numproduct].price, book[numproduct].title, book[numproduct].author, book[numproduct].isbn, book[numproduct].publish);
			numproduct++;
		}
		else if (menunum == 2)
		{
			printf("������ �˻��ϱ� ���� �������� ���ÿ�\n");
			printf("ã�� ������ �̸��� �Է��ϼ���\n");
			printf("> ");
			scanf("%s", findbook);
			int search = 0;
			for (int i = 0; i < numproduct; i++)
			{
				if (strcmp(book[i].title, findbook) == 0)
				{
					printf("ã���ô� å�� �ֽ��ϴ�.\n");
					search = 1;
				}
			}
			if (!search)
			{
				printf("ã���ô� å�� �����ϴ�.\n");
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
				printf("����: %s, id: %s, ����: %d, ����: %s, ISBN: %s, ���ǻ�: %s\n", book[i].author, book[i].id, book[i].price, book[i].title, book[i].isbn, book[i].publish);
			}
		}
	}
}