#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

bool InitialList(LinkList *L)
{
    *L= (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
    {
        return false;
    }
    (*L)->next = NULL;
    return true;
}

void main()
{
    LinkList L;
    InitialList(&L);
}