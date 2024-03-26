/*
파일제목 : secondproject_v2_liste.c

Created : 24-03-27

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
        printf("1.도서구입(등록)\n2.도서검색(대여 및 반납)\n3.도서삭제\n4.도서출력\n0.종료\n");
        printf("> ");
        scanf("%d", &choice);
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
            printf("대여할 도서를 검색하기 위한 상세조건을 고르시오\n");
            printf("1. 제목\n2.저자\n3.출판년도\n4.가격\n5.ISBn\n6.도서반납\n");
            printf("> ");
            scanf("%d", &choice1);
            if (choice1 == 1)
            {
                printf("찾는 도서의 이름을 입력하세요\n");
                printf("> ");
                scanf("%s", title);
                borrowBook1(title);
            }
            else if (choice1 == 2)
            {
                printf("찾는 도서의 저자를 입력하세요\n");
                printf("> ");
                scanf("%s", author);
                borrowBook2(author);
            }
            else if (choice1 == 3)
            {
                printf("찾는 도서의 출판년도를 입력하세요\n");
                printf("> ");
                scanf("%d", &year);
                borrowBook3(year);
            }
            else if (choice1 == 4)
            {
                printf("찾는 도서의 가격을 입력하세요\n");
                printf("> ");
                scanf("%d", &price);
                borrowBook4(price);
            }
            else if (choice1 == 5)
            {
                printf("찾는 도서의 ISBNd을 입력하세요\n");
                printf("> ");
                scanf("%s", isbn);
                borrowBook5(isbn);
            }

            else if (choice1 == 6)
            {
                printf("반납할 도서의 제목을 입력하세요\n");
                printf("> ");
                scanf("%s", title);
                returnBook(title);
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