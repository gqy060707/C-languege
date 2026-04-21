#include <stdio.h>
#include <stdlib.h>

typedef struct
{ // 定义顺序表结构体
    int *data;
    int MaxSize;
    int length;
} SequenceList;

void InitialList(SequenceList *L)
{ // 创建顺序表SequenceList *L表示顺序表的地址
    printf("请输入顺序表可容纳的数据数量:\n");
    scanf("%d", &L->MaxSize);

    L->data = (int *)malloc(L->MaxSize * sizeof(int));
    if (L->data == NULL)
    {
        printf("初始内存分配失败！\n");
        exit(1); // 异常退出程序与正常退出程序的区别在于，异常退出程序是由于程序发生了错误或异常情况而导致的退出，而正常退出程序是指程序按照预期的流程执行完毕后正常结束。异常退出程序通常会返回一个非零的状态码，以表示程序发生了错误，而正常退出程序通常会返回一个零的状态码，表示程序成功执行完毕。在C语言中，可以使用exit()函数来实现异常退出程序，并传递一个非零的状态码来表示错误类型。
    }

    printf("初始内存分配成功！\n");
    printf("请输入%d个数据:\n", L->MaxSize);

    for (int i = 0; i < L->MaxSize; i++)
    {
        scanf("%d", &L->data[i]);
    }

    L->length = L->MaxSize;
}

void IncreaseList(SequenceList *L, int AddSize) // 增加顺序表的长度
{
    int *olddata = L->data;

    L->data = (int *)malloc((L->MaxSize + AddSize) * sizeof(int));
    if (L->data == NULL)
    {
        printf("增加内存分配失败！\n");
        exit(1);}

        for (int i = 0; i < L->length; i++)
        { // 将原来顺序表中的元素复制到新的顺序表中
            L->data[i] = olddata[i];
        }
        L->MaxSize += AddSize;
      
        free(olddata);         // 释放原来顺序表的内存空间
        printf("增加内存分配成功！\n");
    
}

void PrintList(SequenceList *L)
{
    printf("顺序表中的元素为:\n");
    for (int i = 0; i < L->length; i++)
    {
        printf("%d ", L->data[i]);
    }
    printf("\n长度为:%d\n最大容量为:%d\n", L->length, L->MaxSize);
}

int main()
{
    SequenceList L;  // 定义顺序表变量L
    InitialList(&L); // 初始化顺序表L,&L表示顺序表的地址
    printf("初始顺序表完成！\n");
    PrintList(&L); // 打印顺序表中的元素

    int AddSize;
    printf("\n请输入要增加的长度:");
    scanf("%d", &AddSize);

    IncreaseList(&L, AddSize); // 增加顺序表L的长度 ,&L表示顺序表的地址
    printf("增加顺序表长度完成！\n");
    PrintList(&L); // 打印顺序表中的元素
    free(L.data); // 释放顺序表的内存空间
    return 0;
}