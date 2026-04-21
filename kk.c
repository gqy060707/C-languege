#include <stdio.h>
#include <stdlib.h> //malloc函数需要包含stdlib.h头文件
#define InitSize 10
typedef struct
{                // 定义顺序表结构体
    int *data;   // 顺序表的存储空间基址
    int MaxSize; // 顺序表的最大长度
    int length;  // 顺序表的当前长度
} SequenceList;

void InitialList(SequenceList *L)
{                                                    // 创建顺序表SequenceList *L表示顺序表的地址
    L->data = (int *)malloc(InitSize * sizeof(int)); // 分配内存空间
    if (L->data == NULL)
    {                               // 判断内存分配是否成功，tong过判断指针是否为NULL来判断内存分配是否成功如果内存分配失败，malloc函数会返回NULL指针L->data表示顺序表的存储空间基址，如果内存分配失败，L->data将为NULL指针
        printf("内存分配失败！\n"); // 如果内存分配失败，输出提示信息并退出程序
        exit(1);                    // 退出程序
    }
    L->MaxSize = InitSize; // 初始化顺序表的最大长度为InitSize 10
    L->length = 0;         // 初始化顺序表的当前长度为0
}

void IncreaseList(SequenceList *L, int length)
{                                                                 // 增加顺序表的长度
    int *p = L->data;                                             // 保存原来顺序表的地址
    L->data = (int *)malloc((L->MaxSize + length) * sizeof(int)); // 重新分配内存空间
    if (L->data == NULL)
    {                               // 判断内存分配是否成功
        printf("内存分配失败！\n"); // 如果内存分配失败，输出提示信息并退出程序
        exit(1);
    }
    for (int i = 0; i < L->length; i++)
    { // 将原来顺序表中的元素复制到新的顺序表中
        L->data[i] = p[i];
    }
    L->MaxSize += length; // 更新顺序表的最大长度
    free(p);              // 释放原来顺序表的内存空间
}
int main()
{                        // 主函数
    SequenceList L;      // 定义顺序表变量L
    InitialList(&L);     // 初始化顺序表L
    IncreaseList(&L, 5); // 增加顺序表L的长度为5
    return 0;
}