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
void PrintList(SeqList *sq);
void DeleteX(SeqList *q,ElemType x);


main()
{
    SeqList *q;
    ElemType x;
    q=CreatList();
    scanf("%d",&x);
    DeleteX(q,x);
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
void DeleteX(SeqList *q,ElemType x){
    int t=0;
    for(int i=0;i<q->length;i++){
        if(q->elem[i]!=x){
            q->elem[t]=q->elem[i];
            t++;
        }
    }
    q->length=t;
    
}