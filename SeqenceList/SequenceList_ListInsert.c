#include <stdio.h>
#include<stdlib.h>
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

bool ListInsert(SequenceList *L, int i, int e)//在顺序表L的第i个位置插入元素e
{
    // 其中i表示插入位置(从1开始)，e表示要插入的元素，length表示顺序表的当前长度（从1开始），MaxSize表示顺序表的最大长度（从1开始）。
    if (i < 1 || i > L->length + 1)
    {
        printf("插入位置不合法！\n");
        return false;
    }
    if (L->length >= L->MaxSize)
    {printf("顺序表已满，无法插入！\n");
        return false;
    }
    for (int j = L->length; j >= i; j--) // int j = L->length;表示从顺序表的最后一个元素开始，j >= i;表示当j大于等于i时继续循环，j--表示每次循环将j的值减1，即向前移动一个位置
    {
        L->data[j] = L->data[j - 1];
        L->data[i - 1] = e;
        L->length++;
    }
}

int main()
{
    SequenceList L;      // 定义顺序表变量L
    InitialList(&L);     // 初始化顺序表L,&L表示顺序表的地址
    ListInsert(&L, 2, 10); //在顺序表L的第2个位置插入元素10,&L表示顺序表的地址
}