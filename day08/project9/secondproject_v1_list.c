/*
��������: secondproject_v1_list.c

Created 24-03-27

Author : �ڼ���
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
    newBook->next = head;
    head = newBook;
}

void searchBook1(char* _title) {
    Book* current = head;
    while (current != NULL) {
        if (strcmp(current->title, _title) == 0) {
            printf("ã���ô� å�� �ֽ��ϴ�.\n");
            return;
        }
        current = current->next;
    }
    printf("������ ã�� �� �����ϴ�.\n");
}

void searchBook2(char* _author) {
    Book* current = head;
    while (current != NULL) {
        if (strcmp(current->author, _author) == 0) {
            printf("ã���ô� å�� �ֽ��ϴ�.\n");
            return;
        }
        current = current->next;
    }
    printf("������ ã�� �� �����ϴ�.\n");
}

void searchBook3(int _year) {
    Book* current = head;
    while (current != NULL) {
        if ((current->year) == _year) {
            printf("ã���ô� å�� �ֽ��ϴ�.\n");
            return;
        }
        current = current->next;
    }
    printf("������ ã�� �� �����ϴ�.\n");
}

void searchBook4(char* _isbn) {
    Book* current = head;
    while (current != NULL) {
        if (strcmp(current->isbn, _isbn) == 0) {
            printf("ã���ô� å�� �ֽ��ϴ�.\n");
            return;
        }
        current = current->next;
    }
    printf("������ ã�� �� �����ϴ�.\n");
}

void searchBook5(int _price) {
    Book* current = head;
    while (current != NULL) {
        if ((current->price) == _price) {
            printf("ã���ô� å�� �ֽ��ϴ�.\n");
            return;
        }
        current = current->next;
    }
    printf("������ ã�� �� �����ϴ�.\n");
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
    printf("**���� ���**\n");
    while (current != NULL) {
        printf("å ����: %s, ����: %s, ���ǳ⵵: %d, ����: %d, ISBN: %s,\n", current->title, current->author, current->year, current->isbn, current->price);
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
        printf("****�޴�****\n");
        printf("1.��������(���)\n2.�����˻�\n3.��������\n4.�������\n0.����\n");
        printf("> ");
        scanf_s("%d", &choice);
        if (choice == 0)
        {
            printf("���α׷��� �����մϴ�.\n");
            exit(0);
        }
        else if (choice == 1)
        {
            addBook();
        }
        else if (choice == 2)
        {
            printf("������ �˻��ϱ� ���� �������� ���ÿ�\n");
            printf("1. ����\n2.����\n3.���ǳ⵵\n4.����\n5.ISBn\n");
            printf("> ");
            scanf("%d", &choice1);
            if (choice1 == 1)
            {
                printf("ã�� ������ �̸��� �Է��ϼ���\n");
                printf("> ");
                scanf("%s", title);
                searchBook1(title);
            }
            else if (choice1 == 2)
            {
                printf("ã�� ������ ���ڸ� �Է��ϼ���\n");
                printf("> ");
                scanf("%s", author);
                searchBook2(author);
            }
            else if (choice1 == 3)
            {
                printf("ã�� ������ ���ǳ⵵�� �Է��ϼ���\n");
                printf("> ");
                scanf("%d", &year);
                searchBook3(year);
            }
            else if (choice1 == 4)
            {
                printf("ã�� ������ ������ �Է��ϼ���\n");
                printf("> ");
                scanf("%d", &price);
                searchBook5(price);
            }
            else if (choice1 == 5)
            {
                printf("ã�� ������ ISBNd�� �Է��ϼ���\n");
                printf("> ");
                scanf("%s", isbn);
                searchBook4(isbn);
            }
            else
            {
                printf("�߸��� �Է��Դϴ�.\n");
            }
        }
        else if (choice == 3)
        {
            printf("������ ������ �̸��� �Է��ϼ���\n");
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
            printf("�߸��� �����Դϴ� �ٽ� �������ּ���.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}