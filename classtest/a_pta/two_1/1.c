#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct
{
    ElemType elem[MAXSIZE];
    int length;
}SeqList;

SeqList * CreatList();
void PrintList(SeqList *q);
void reverse(SeqList *q );

main()
{
    SeqList *q;
    q=CreatList();
    reverse(q);
    PrintList(q);
}

SeqList * CreatList()
{
    SeqList *sq = (SeqList*)malloc(sizeof(SeqList));
    scanf("%d",&(sq->length));
    for(int i=0;i<sq->length;i++)
    {
        scanf("%d",&(sq->elem[i]));
    }
    return sq;
}
void PrintList(SeqList *sq)
{
    for(int i=0;i<sq->length;i++)
        printf("%d ",sq->elem[i]);
}

/* 请在这里填写答案 */
void reverse(SeqList *q ){
    int l=q->length-1;
    ElemType t;
    for(int i=0;i<(q->length)/2;i++,l--){
        t=q->elem[i];
        q ->elem[i]=q->elem[l];
        q->elem[l]=t;
    }
}
