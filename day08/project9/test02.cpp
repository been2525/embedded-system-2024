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

void searchBook(char* _title) {
    Book* current = head;
    while (current != NULL) {
        if (strcmp(current->title, _title) == 0) {
            printf("찾으시는 책이 있습니다.\n");
            printf("도서 제목: %s\n", current->title);
            printf("저자: %s\n", current->author);
            printf("출판년도: %d\n", current->year);
            printf("ISBN: %s\n", current->isbn);
            printf("가격 : %d\n", current->price);
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
        printf("책 제목: %s, 저자: %s, 출판년도: %d\n", current->title, current->author, current->year);
        current = current->next;
    }
}

void menu() {
    int choice;
    int chioce1;
    char title[100];
    do {
        printf("\n****메뉴****\n");
        printf("1. 도서 등록\n");
        printf("2. 도서 검색\n");
        printf("3. 도서 삭제\n");
        printf("4. 도서 출력\n");
        printf("0. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            addBook();
            break;
        case 2:
            printf("검색할 도서 제목: ");
            scanf("%s", title);
            searchBook(title);
            break;
        case 3:
            printf("삭제할 도서 제목: ");
            scanf("%s", title);
            deleteBook(title);
            break;
        case 4:
            printBooks();
            break;
        case 0:
            printf("프로그램을 종료합니다.\n");
            break;
        default:
            printf("잘못된 선택입니다. 다시 선택하세요.\n");
            break;
        }
    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}


/*do {
        printf("\n****메뉴****\n");
        printf("1. 도서 등록\n");
        printf("2. 도서 검색\n");
        printf("3. 도서 삭제\n");
        printf("4. 도서 출력\n");
        printf("0. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            addBook();
            break;
        case 2:
            printf("검색할 도서 제목: ");
            scanf("%s", title);
            searchBook(title);
            break;
        case 3:
            printf("삭제할 도서 제목: ");
            scanf("%s", title);
            deleteBook(title);
            break;
        case 4:
            printBooks();
            break;
        case 0:
            printf("프로그램을 종료합니다.\n");
            break;
        default:
            printf("잘못된 선택입니다. 다시 선택하세요.\n");
            break;
        }
    } while (choice != 0);
    */