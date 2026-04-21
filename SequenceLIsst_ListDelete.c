#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define InitialSize 10

typedef struct
{ // 定义顺序表结构体
    int *data;
    int MaxSize;
    int length;
} SequenceList;

void InitialList(SequenceList *L)
{ // 创建顺序表SequenceList *L表示顺序表的地址
    L->data = (int *)malloc(InitialSize * sizeof(int));
    if (L->data == NULL)
    {
        printf("初始内存分配失败！\n");
        exit(1); // 异常退出程序与正常退出程序的区别在于，异常退出程序是由于程序发生了错误或异常情况而导致的退出，而正常退出程序是指程序按照预期的流程执行完毕后正常结束。异常退出程序通常会返回一个非零的状态码，以表示程序发生了错误，而正常退出程序通常会返回一个零的状态码，表示程序成功执行完毕。在C语言中，可以使用exit()函数来实现异常退出程序，并传递一个非零的状态码来表示错误类型。
    }
    L->MaxSize = InitialSize;
    L->length = 0;
}

bool ListDelete(SequenceList *L, int i, int *e)
{ // 在顺序表L的第i个位置删除元素，并用e返回删除的元素
    if (i < 1 || i > L->length)
    {
        printf("删除位置不合法！\n");
        return false;
    }
    *e = L->data[i - 1];
    for (int j = i; j < L->length; j++)
    {
        L->data[j - 1] = L->data[j]; // 将第i个位置之后的元素向前移动一个位置
    }
    L->length--;
    return true;
}

int main()
{
    SequenceList L;            // 定义顺序表变量L
    InitialList(&L);           // 初始化顺序表L,&L表示顺序表的地址
    int e = -1;                // 定义一个整型变量e，用于存储删除的元素-1表示初始值，表示没有删除任何元素
    if (ListDelete(&L, 2, &e)) // 在顺序表L的第2个位置删除元素，并用e返回删除的元素,&L表示顺序表的地址，&e表示e的地址
    {
        printf("成功删除元素：%d\n", e);
    }
    else
    {
        printf("位序i不合法,删除元素失败!\n");
    }
}