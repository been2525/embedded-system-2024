#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

Book* head = NULL;

void addBook() {
    Book* newBook = (Book*)malloc(sizeof(Book));
    printf("���� ����: ");
    scanf("%s", newBook->title);
    printf("����: ");
    scanf("%s", newBook->author);
    printf("���ǳ⵵: ");
    scanf("%d", &newBook->year);
    printf("����: ");
    scanf("%d", &newBook->price);
    printf("ISBN: ");
    scanf("%s", newBook->isbn);
    printf("�뿩����(�뿩�����̸� 0, �ƴҰ�� 1): ");
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
                printf("�뿩�� �����մϴ�.\n");
            }
            else
            {
                printf("�뿩�� �Ұ����մϴ�.\n");
            }
            return;
        }

        current = current->next;
    }
    printf("������ ã�� �� �����ϴ�.\n");
}

void borrowBook2(char* _author) {
    Book* current = head;
    while (current != NULL) {
        if (strcmp(current->author, _author) == 0) {
            if ((current->borrow) == 0)
            {
                printf("�뿩�� �����մϴ�.\n");
            }
            else
            {
                printf("�뿩�� �Ұ����մϴ�.\n");
            }
            return;
        }

        current = current->next;
    }
    printf("������ ã�� �� �����ϴ�.\n");
}


void borrowBook3(int _year) {
    Book* current = head;
    while (current != NULL) {
        if ((current->year) == _year) {
            if ((current->borrow) == 0)
            {
                printf("�뿩�� �����մϴ�.\n");
            }
            else
            {
                printf("�뿩�� �Ұ����մϴ�.\n");
            }
            return;
        }

        current = current->next;
    }
    printf("������ ã�� �� �����ϴ�.\n");
}

void borrowBook4(int _price) {
    Book* current = head;
    while (current != NULL) {
        if ((current->price) == _price) {
            if ((current->borrow) == 0)
            {
                printf("�뿩�� �����մϴ�.\n");
            }
            else
            {
                printf("�뿩�� �Ұ����մϴ�.\n");
            }
            return;
        }

        current = current->next;
    }
    printf("������ ã�� �� �����ϴ�.\n");
}

void borrowBook5(char* _isbn) {
    Book* current = head;
    while (current != NULL) {
        if (strcmp(current->isbn, _isbn) == 0) {
            if ((current->borrow) == 0)
            {
                printf("�뿩�� �����մϴ�.\n");
            }
            else
            {
                printf("�뿩�� �Ұ����մϴ�.\n");
            }
            return;
        }

        current = current->next;
    }
    printf("������ ã�� �� �����ϴ�.\n");
}

void returnBook(char* _title) {
    Book* current = head;
    while (current != NULL) {
        if (strcmp(current->title, _title) == 0) {
            if ((current->borrow) == 1) {
                current->borrow = 0;
                printf("������ �ݳ��߽��ϴ�.\n");
            }
            else {
                printf("�̹� ������ �ݳ��Ǿ����ϴ�.\n");
            }
            return;
        }
        current = current->next;
    }
    printf("������ ã�� �� �����ϴ�.\n");
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
            printf("������ �����߽��ϴ�.\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("������ ã�� �� �����ϴ�.\n");
}

void printBooks() {
    Book* current = head;
    if (current == NULL) {
        printf("��ϵ� ������ �����ϴ�.\n");
        return;
    }
    printf("���� ���:\n");
    while (current != NULL) {
        printf("å ����: %s, ����: %s, ���ǳ⵵: %d, ����: %d, ISBN: %s,\n", current->title, current->author, current->year, current->price, current->isbn);
        current = current->next;
    }
}