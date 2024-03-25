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

void borrowBook(char* _title) {
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
    int chioce1;
    char title[100];
    while (1)
    {
        printf("****�޴�****\n");
        printf("1.��������(���)\n2.�����˻�(�뿩 �� �ݳ�)\n3.��������\n4.�������\n0.����\n");
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
            printf("ã�� ������ �̸��� �Է��ϼ���\n");
            printf("> ");
            scanf("%s", title);
            borrowBook(title);
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