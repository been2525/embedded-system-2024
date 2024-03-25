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

void searchBook(char* _title) {
    Book* current = head;
    while (current != NULL) {
        if (strcmp(current->title, _title) == 0) {
            printf("ã���ô� å�� �ֽ��ϴ�.\n");
            printf("���� ����: %s\n", current->title);
            printf("����: %s\n", current->author);
            printf("���ǳ⵵: %d\n", current->year);
            printf("ISBN: %s\n", current->isbn);
            printf("���� : %d\n", current->price);
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
        printf("å ����: %s, ����: %s, ���ǳ⵵: %d\n", current->title, current->author, current->year);
        current = current->next;
    }
}

void menu() {
    int choice;
    int chioce1;
    char title[100];
    do {
        printf("\n****�޴�****\n");
        printf("1. ���� ���\n");
        printf("2. ���� �˻�\n");
        printf("3. ���� ����\n");
        printf("4. ���� ���\n");
        printf("0. ����\n");
        printf("����: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            addBook();
            break;
        case 2:
            printf("�˻��� ���� ����: ");
            scanf("%s", title);
            searchBook(title);
            break;
        case 3:
            printf("������ ���� ����: ");
            scanf("%s", title);
            deleteBook(title);
            break;
        case 4:
            printBooks();
            break;
        case 0:
            printf("���α׷��� �����մϴ�.\n");
            break;
        default:
            printf("�߸��� �����Դϴ�. �ٽ� �����ϼ���.\n");
            break;
        }
    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}


/*do {
        printf("\n****�޴�****\n");
        printf("1. ���� ���\n");
        printf("2. ���� �˻�\n");
        printf("3. ���� ����\n");
        printf("4. ���� ���\n");
        printf("0. ����\n");
        printf("����: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            addBook();
            break;
        case 2:
            printf("�˻��� ���� ����: ");
            scanf("%s", title);
            searchBook(title);
            break;
        case 3:
            printf("������ ���� ����: ");
            scanf("%s", title);
            deleteBook(title);
            break;
        case 4:
            printBooks();
            break;
        case 0:
            printf("���α׷��� �����մϴ�.\n");
            break;
        default:
            printf("�߸��� �����Դϴ�. �ٽ� �����ϼ���.\n");
            break;
        }
    } while (choice != 0);
    */