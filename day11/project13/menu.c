#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

void menu() {
    int choice;
    int choice1;
    char title[100];
    char author[100];
    int year;
    char isbn[100];
    int price;
    while (1)
    {
        printf("****메뉴****\n");
        printf("1.도서구입(등록)\n2.도서검색(대여 및 반납)\n3.도서삭제\n4.도서출력\n0.종료\n");
        printf("> ");
        scanf("%d", &choice);
        if (choice == 0)
        {
            printf("프로그램을 종료합니다.\n");
            exit(0);
        }
        else if (choice == 1)
        {
            addBook();
        }
        else if (choice == 2)
        {
            printf("대여할 도서를 검색하기 위한 상세조건을 고르시오\n");
            printf("1. 제목\n2.저자\n3.출판년도\n4.가격\n5.ISBn\n6.도서반납\n");
            printf("> ");
            scanf("%d", &choice1);
            if (choice1 == 1)
            {
                printf("찾는 도서의 이름을 입력하세요\n");
                printf("> ");
                scanf("%s", title);
                borrowBook1(title);
            }
            else if (choice1 == 2)
            {
                printf("찾는 도서의 저자를 입력하세요\n");
                printf("> ");
                scanf("%s", author);
                borrowBook2(author);
            }
            else if (choice1 == 3)
            {
                printf("찾는 도서의 출판년도를 입력하세요\n");
                printf("> ");
                scanf("%d", &year);
                borrowBook3(year);
            }
            else if (choice1 == 4)
            {
                printf("찾는 도서의 가격을 입력하세요\n");
                printf("> ");
                scanf("%d", &price);
                borrowBook4(price);
            }
            else if (choice1 == 5)
            {
                printf("찾는 도서의 ISBNd을 입력하세요\n");
                printf("> ");
                scanf("%s", isbn);
                borrowBook5(isbn);
            }

            else if (choice1 == 6)
            {
                printf("반납할 도서의 제목을 입력하세요\n");
                printf("> ");
                scanf("%s", title);
                returnBook(title);
            }

            else
            {
                printf("잘못된 입력입니다.\n");
            }
        }
        else if (choice == 3)
        {
            printf("삭제할 도서의 이름을 입력하세요\n");
            printf("> ");
            scanf("%s", title);
            deleteBook(title);

        }
        else if (choice == 4)
        {
            printBooks();
        }

        else
        {
            printf("잘못된 선택입니다 다시 선택해주세요.\n");
        }
    }
}
