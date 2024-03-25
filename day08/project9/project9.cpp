// project9.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
/*
char id[BUF_SZ];
	int price;
	char title[BUF_SZ];
	char author[BUF_SZ];
	char isbn[BUF_SZ];
	char publish[BUF_SZ];
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    char title[100];
    char author[100];
    int year;
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
    newBook->next = head;
    head = newBook;
}

void searchBook(char* title) {
    Book* current = head;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            printf("도서 제목: %s\n", current->title);
            printf("저자: %s\n", current->author);
            printf("출판년도: %d\n", current->year);
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
        printf("도서 제목: %s, 저자: %s, 출판년도: %d\n", current->title, current->author, current->year);
        current = current->next;
    }
}

void menu() {
    int choice;
    char title[100];
    do {
        printf("\n****메뉴****\n");
        printf("1. 도서 구입\n");
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
