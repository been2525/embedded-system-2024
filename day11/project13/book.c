#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

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
    printf("대여가능(대여가능이면 0, 아닐경우 1): ");
    scanf("%d", &newBook->borrow);
    newBook->next = head;
    head = newBook;
}

void borrowBook1(char* _title) {
    Book* current = head;
    while (current != NULL) {
        if (strcmp(current->title, _title) == 0) {
            if ((current->borrow) == 0)
            {
                printf("대여가 가능합니다.\n");
            }
            else
            {
                printf("대여가 불가능합니다.\n");
            }
            return;
        }

        current = current->next;
    }
    printf("도서를 찾을 수 없습니다.\n");
}

void borrowBook2(char* _author) {
    Book* current = head;
    while (current != NULL) {
        if (strcmp(current->author, _author) == 0) {
            if ((current->borrow) == 0)
            {
                printf("대여가 가능합니다.\n");
            }
            else
            {
                printf("대여가 불가능합니다.\n");
            }
            return;
        }

        current = current->next;
    }
    printf("도서를 찾을 수 없습니다.\n");
}


void borrowBook3(int _year) {
    Book* current = head;
    while (current != NULL) {
        if ((current->year) == _year) {
            if ((current->borrow) == 0)
            {
                printf("대여가 가능합니다.\n");
            }
            else
            {
                printf("대여가 불가능합니다.\n");
            }
            return;
        }

        current = current->next;
    }
    printf("도서를 찾을 수 없습니다.\n");
}

void borrowBook4(int _price) {
    Book* current = head;
    while (current != NULL) {
        if ((current->price) == _price) {
            if ((current->borrow) == 0)
            {
                printf("대여가 가능합니다.\n");
            }
            else
            {
                printf("대여가 불가능합니다.\n");
            }
            return;
        }

        current = current->next;
    }
    printf("도서를 찾을 수 없습니다.\n");
}

void borrowBook5(char* _isbn) {
    Book* current = head;
    while (current != NULL) {
        if (strcmp(current->isbn, _isbn) == 0) {
            if ((current->borrow) == 0)
            {
                printf("대여가 가능합니다.\n");
            }
            else
            {
                printf("대여가 불가능합니다.\n");
            }
            return;
        }

        current = current->next;
    }
    printf("도서를 찾을 수 없습니다.\n");
}

void returnBook(char* _title) {
    Book* current = head;
    while (current != NULL) {
        if (strcmp(current->title, _title) == 0) {
            if ((current->borrow) == 1) {
                current->borrow = 0;
                printf("도서를 반납했습니다.\n");
            }
            else {
                printf("이미 도서가 반납되었습니다.\n");
            }
            return;
        }
        current = current->next;
    }
    printf("도서를 찾을 수 없습니다.\n");
}


void deleteBook(char* title) {
    Book* current = head;
    Book* prev = NULL;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
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
    printf("도서 목록:\n");
    while (current != NULL) {
        printf("책 제목: %s, 저자: %s, 출판년도: %d, 가격: %d, ISBN: %s,\n", current->title, current->author, current->year, current->price, current->isbn);
        current = current->next;
    }
}