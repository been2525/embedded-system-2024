#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

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
