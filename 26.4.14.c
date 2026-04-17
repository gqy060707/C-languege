#include <stdio.h>
#include <stdlib.h>
#define InitSize 10
typedef struct {
    int *data;
    int length;
    int MaxSize;

}SeqList;

void InitList( SeqList *L){//创建顺序表
	L->data = (int *)malloc(InitSize*sizeof(int));//分配内存空间
	L->length = 0;//初始长度为0
	L->MaxSize = InitSize;//初始最大长度为InitSize 10
} 

void IncreaseSize(SeqList *L,int len){//增加顺序表的长度
	int *p = L->data;//保存原来顺序表的地址
	L->data=(int *)malloc((L->MaxSize+len)*sizeof(int));//重新分配内存空间
	for(int i=0 ; i< L->length; i++){//将原来顺序表中的元素复制到新的顺序表中
		L->data[i]=p[i];
	}
	L->MaxSize=L->MaxSize+len;//更新顺序表的最大长度
	free(p);//释放原来顺序表的内存空间
}

void ListInsert(SeqList *L,int i,int e){
	for(int j=L->length;j>=i;j--){
		
	}
	
}
int main(){
	SeqList L;
	InitList(&L);
	IncreaseSize(&L,5);
	printf("MaxSize=%d\n",L.MaxSize);
	return 0;
}
