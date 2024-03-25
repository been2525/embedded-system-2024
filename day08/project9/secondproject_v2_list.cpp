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

void borrowBook(char* _title) {
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

void menu() {
    int choice;
    int chioce1;
    char title[100];
    while (1)
    {
        printf("****메뉴****\n");
        printf("1.도서구입(등록)\n2.도서검색(대여 및 반납)\n3.도서삭제\n4.도서출력\n0.종료\n");
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
            printf("찾는 도서의 이름을 입력하세요\n");
            printf("> ");
            scanf("%s", title);
            borrowBook(title);
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