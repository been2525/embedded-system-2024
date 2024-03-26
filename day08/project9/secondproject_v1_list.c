/*
파일제목: secondproject_v1_list.c

Created 24-03-27

Author : 박성빈
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    char title[100];
    char author[100];
    int year;
    char isbn[100];
    int price;
    struct Book* next;
} Book;

Book* head = NULL;

void addBook() {
    Book* newBook = (Book*)malloc(sizeof(Book));
    printf("도서 제목: ");
    scanf("%s", newBook->title);
    printf("저자: ");
    scanf("%s", newBook->author);
    printf("출판년도: ");
    scanf("%d", &newBook->year);
    printf("가격: ");
    scanf("%d", &newBook->price);
    printf("ISBN: ");
    scanf("%s", newBook->isbn);
    newBook->next = head;
    head = newBook;
}

void searchBook1(char* _title) {
    Book* current = head;
    while (current != NULL) {
        if (strcmp(current->title, _title) == 0) {
            printf("찾으시는 책이 있습니다.\n");
            return;
        }
        current = current->next;
    }
    printf("도서를 찾을 수 없습니다.\n");
}

void searchBook2(char* _author) {
    Book* current = head;
    while (current != NULL) {
        if (strcmp(current->author, _author) == 0) {
            printf("찾으시는 책이 있습니다.\n");
            return;
        }
        current = current->next;
    }
    printf("도서를 찾을 수 없습니다.\n");
}

void searchBook3(int _year) {
    Book* current = head;
    while (current != NULL) {
        if ((current->year) == _year) {
            printf("찾으시는 책이 있습니다.\n");
            return;
        }
        current = current->next;
    }
    printf("도서를 찾을 수 없습니다.\n");
}

void searchBook4(char* _isbn) {
    Book* current = head;
    while (current != NULL) {
        if (strcmp(current->isbn, _isbn) == 0) {
            printf("찾으시는 책이 있습니다.\n");
            return;
        }
        current = current->next;
    }
    printf("도서를 찾을 수 없습니다.\n");
}

void searchBook5(int _price) {
    Book* current = head;
    while (current != NULL) {
        if ((current->price) == _price) {
            printf("찾으시는 책이 있습니다.\n");
            return;
        }
        current = current->next;
    }
    printf("도서를 찾을 수 없습니다.\n");
}



void deleteBook(char* _title) {
    Book* current = head;
    Book* prev = NULL;
    while (current != NULL) {
        if (strcmp(current->title, _title) == 0) {
            if (prev == NULL) {
                head = current->next;
            }
            else {
                prev->next = current->next;
            }
            free(current);
            printf("도서를 삭제했습니다.\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("도서를 찾을 수 없습니다.\n");
}

void printBooks() {
    Book* current = head;
    if (current == NULL) {
        printf("등록된 도서가 없습니다.\n");
        return;
    }
    printf("**도서 목록**\n");
    while (current != NULL) {
        printf("책 제목: %s, 저자: %s, 출판년도: %d, 가격: %d, ISBN: %s,\n", current->title, current->author, current->year, current->isbn, current->price);
        current = current->next;
    }
}

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
        printf("1.도서구입(등록)\n2.도서검색\n3.도서삭제\n4.도서출력\n0.종료\n");
        printf("> ");
        scanf_s("%d", &choice);
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
            printf("도서를 검색하기 위한 상세조건을 고르시오\n");
            printf("1. 제목\n2.저자\n3.출판년도\n4.가격\n5.ISBn\n");
            printf("> ");
            scanf("%d", &choice1);
            if (choice1 == 1)
            {
                printf("찾는 도서의 이름을 입력하세요\n");
                printf("> ");
                scanf("%s", title);
                searchBook1(title);
            }
            else if (choice1 == 2)
            {
                printf("찾는 도서의 저자를 입력하세요\n");
                printf("> ");
                scanf("%s", author);
                searchBook2(author);
            }
            else if (choice1 == 3)
            {
                printf("찾는 도서의 출판년도를 입력하세요\n");
                printf("> ");
                scanf("%d", &year);
                searchBook3(year);
            }
            else if (choice1 == 4)
            {
                printf("찾는 도서의 가격을 입력하세요\n");
                printf("> ");
                scanf("%d", &price);
                searchBook5(price);
            }
            else if (choice1 == 5)
            {
                printf("찾는 도서의 ISBNd을 입력하세요\n");
                printf("> ");
                scanf("%s", isbn);
                searchBook4(isbn);
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

int main() {
    menu();
    return 0;
}