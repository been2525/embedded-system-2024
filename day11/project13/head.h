#ifndef BOOK_H
#define BOOK_H

typedef struct Book {
    char title[100];
    char author[100];
    int year;
    char isbn[100];
    int price;
    int borrow;
    struct Book* next;
} Book;

void addBook();
void borrowBook1(char* _title);
void borrowBook2(char* _author);
void borrowBook3(int _year);
void borrowBook4(int _price);
void borrowBook5(char* _isbn);
void returnBook(char* _title);
void deleteBook(char* title);
void printBooks();
void menu();

#endif