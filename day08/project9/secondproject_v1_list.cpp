//연결리스트로 수정하기
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
		printf("****메뉴****\n");
		printf("1.도서구입(등록)\n2.도서검색\n3.도서삭제\n4.도서출력\n0.종료\n");
		printf("> ");
		scanf_s("%d", &menunum);
		if (menunum == 0)
		{
			printf("프로그램을 종료합니다.");
			exit(0);
		}
		else if (menunum == 1)
		{
			printf("아이디를 입력하세요: ");
			scanf("%s", book[numproduct].id);
			printf("가격을 입력하세요: ");
			scanf("%d", &book[numproduct].price);
			printf("제목을 입력하세요: ");
			scanf("%s", book[numproduct].title);
			printf("저자를 입력하세요: ");
			scanf("%s", book[numproduct].author);
			printf("ISBN을 입력하세요: ");
			scanf("%s", book[numproduct].isbn);
			printf("출판사를 입력하세요: ");
			scanf("%s", book[numproduct].publish);
			//strcpy(book[numproduct].id, id);
			//strcpy(book[numproduct].author, author);
			//strcpy(book[numproduct].title, title);
			//book[numproduct].price = price;
			printf("아이디 : %s, 가격: %d, 제목: %s, 저자: %s, ISBN: %s, 출판사: %s\n", book[numproduct].id, &book[numproduct].price, book[numproduct].title, book[numproduct].author, book[numproduct].isbn, book[numproduct].publish);
			numproduct++;
		}
		else if (menunum == 2)
		{
			printf("도서를 검색하기 위한 상세조건을 고르시오\n");
			printf("찾는 도서의 이름을 입력하세요\n");
			printf("> ");
			scanf("%s", findbook);
			int search = 0;
			for (int i = 0; i < numproduct; i++)
			{
				if (strcmp(book[i].title, findbook) == 0)
				{
					printf("찾으시는 책이 있습니다.\n");
					search = 1;
				}
			}
			if (!search)
			{
				printf("찾으시는 책이 없습니다.\n");
			}
		}
		else if (menunum == 3)
		{
			printf("삭제할 도서의 이름을 입력하세요\n");
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
					printf("도서가 삭제되었습니다");
					exit(0);
				}
			}
			if (!found)
			{
				printf("삭제할 도서를 찾을 수 없습니다.\n");
			}
		}
		else if (menunum == 4)
		{
			for (int i = 0; i < numproduct; i++)
			{
				printf("저자: %s, id: %s, 가격: %d, 제목: %s, ISBN: %s, 출판사: %s\n", book[i].author, book[i].id, book[i].price, book[i].title, book[i].isbn, book[i].publish);
			}
		}
	}
}