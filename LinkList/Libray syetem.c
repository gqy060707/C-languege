#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
typedef struct Book
{
    int id;
    char name[100];
    char author[100];
    struct Book *next;
} Book, *BookList;

// 初始化链表
bool InitialList(BookList *L)
{
    *L = NULL;
    return true;
}

// 添加图书
void AddBook(BookList *L, int id, const char *name, const char *author)
{
    Book *newBook = (Book *)malloc(sizeof(Book));
    newBook->id = id;
    snprintf(newBook->name, sizeof(newBook->name), "%s", name);
    snprintf(newBook->author, sizeof(newBook->author), "%s", author);
    newBook->next = *L;
    *L = newBook;
}

// 删除图书
bool DeleteBook(BookList *L, int id)
{
    Book *p = *L, *prev = NULL;
    while (p)
    {
        if (p->id == id)
        {
            if (prev)
                prev->next = p->next;
            else
                *L = p->next;
            free(p);
            return true;
        }
        prev = p;
        p = p->next;
    }
    return false;
}

// 查找图书
Book *FindBook(BookList L, int id)
{
    while (L)
    {
        if (L->id == id)
            return L;
        L = L->next;
    }
    return NULL;
}

// 显示所有图书
void ShowBooks(BookList L)
{
    printf("\n图书列表：\n");
    while (L)
    {
        printf("编号: %d, 书名: %s, 作者: %s\n", L->id, L->name, L->author);
        L = L->next;
    }
}

int main()
{
    BookList L;
    InitialList(&L);
    int choice, id;
    char name[100], author[100];
    Book *book; // 提前声明，避免 case 作用域问题
    while (1)
    {
        printf("\n1. 添加图书\n2. 删除图书\n3. 查找图书\n4. 显示所有图书\n0. 退出\n请选择: ");
        if (scanf("%d", &choice) != 1) {
            while(getchar() != '\n'); // 清空输入缓冲区
            continue;
        }
        getchar(); // 读取回车符，防止后续 gets/fgets 读到
        if (choice == 0)
            break;
        switch (choice)
        {
        case 1:
            printf("输入编号: ");
            scanf("%d", &id);
            getchar();
            printf("输入书名: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0; // 去除换行符
            printf("输入作者: ");
            fgets(author, sizeof(author), stdin);
            author[strcspn(author, "\n")] = 0;
            AddBook(&L, id, name, author);
            printf("添加成功!\n");
            break;
        case 2:
            printf("输入要删除的图书编号: ");
            scanf("%d", &id);
            getchar();
            if (DeleteBook(&L, id))
                printf("删除成功!\n");
            else
                printf("未找到该编号图书!\n");
            break;
        case 3:
            printf("输入要查找的图书编号: ");
            scanf("%d", &id);
            getchar();
            book = FindBook(L, id);
            if (book)
                printf("编号: %d, 书名: %s, 作者: %s\n", book->id, book->name, book->author);
            else
                printf("未找到该编号图书!\n");
            break;
        case 4:
            ShowBooks(L);
            break;
        default:
            printf("无效选择!\n");
        }
    }
    // 释放内存
    while (L)
    {
        Book *tmp = L;
        L = L->next;
        free(tmp);
    }
    return 0;
}