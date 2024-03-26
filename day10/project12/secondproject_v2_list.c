/*
�������� : secondproject_v2_liste.c

Created : 24-03-27

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
    int borrow;
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
        printf("1.��������(���)\n2.�����˻�(�뿩 �� �ݳ�)\n3.��������\n4.�������\n0.����\n");
        printf("> ");
        scanf("%d", &choice);
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
            printf("�뿩�� ������ �˻��ϱ� ���� �������� ���ÿ�\n");
            printf("1. ����\n2.����\n3.���ǳ⵵\n4.����\n5.ISBn\n6.�����ݳ�\n");
            printf("> ");
            scanf("%d", &choice1);
            if (choice1 == 1)
            {
                printf("ã�� ������ �̸��� �Է��ϼ���\n");
                printf("> ");
                scanf("%s", title);
                borrowBook1(title);
            }
            else if (choice1 == 2)
            {
                printf("ã�� ������ ���ڸ� �Է��ϼ���\n");
                printf("> ");
                scanf("%s", author);
                borrowBook2(author);
            }
            else if (choice1 == 3)
            {
                printf("ã�� ������ ���ǳ⵵�� �Է��ϼ���\n");
                printf("> ");
                scanf("%d", &year);
                borrowBook3(year);
            }
            else if (choice1 == 4)
            {
                printf("ã�� ������ ������ �Է��ϼ���\n");
                printf("> ");
                scanf("%d", &price);
                borrowBook4(price);
            }
            else if (choice1 == 5)
            {
                printf("ã�� ������ ISBNd�� �Է��ϼ���\n");
                printf("> ");
                scanf("%s", isbn);
                borrowBook5(isbn);
            }

            else if (choice1 == 6)
            {
                printf("�ݳ��� ������ ������ �Է��ϼ���\n");
                printf("> ");
                scanf("%s", title);
                returnBook(title);
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