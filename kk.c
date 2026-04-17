#include<stdio.h>
#include<stdlib.h>
#define InitSize 10
typedef struct{
    int *data;
    int MaxSize;
    int length;
}SequenceList;

void InitialList(SequenceList *L){
    L->data=(int*)malloc(InitSize*sizeof(int));
    if(L->data == NULL){
        printf("内存分配失败！\n");
        exit(1);
    }
    L->MaxSize=InitSize;
    L-> length=0;
}

void IncreaseList(SequenceList *L,int length){
    int *p = L->data;
    L->data=(int *)malloc((L->MaxSize+length)*sizeof(int));
    if(L->data == NULL){
        printf("内存分配失败！\n");
        exit(1);
    }
    for(int i=0;i<L->length;i++){                                                                                                                                                                                             
        L->data[i]=p[i];
    }
    L->MaxSize+=length;
    free(p);
}
int main(){
    SequenceList L;
    InitialList(&L);
    IncreaseList(&L,5);
    printf("MaxSize=%d\n",L.MaxSize);
    return 0;
}