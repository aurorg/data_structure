// 6-1 顺序表逆置
// 分数 10
// 作者 曾艳
// 单位 西安邮电大学
// 设有一线性表e={e1,e2,...,en-1,en)，其逆线性表定义为e'={en,en-1,...,e2,e1}。请设计一个算法，将线性表逆置，要求逆线性表仍占用原线性表的空间，并且用顺序表来表示，写出逆置函数。

// 函数接口定义：
// void reverse(SeqList *q );
// 其中 q 是用户传入的参数，为指向顺序表的指针。其中类型定义如下：

// #define MAXSIZE 100
// typedef int ElemType;
// typedef struct
// {
//     ElemType elem[MAXSIZE];
//     int length;
// }SeqList;
// 裁判测试程序样例：
// #include<stdio.h>
// #include<stdlib.h>
// #define MAXSIZE 100
// typedef int ElemType;
// typedef struct
// {
//     ElemType elem[MAXSIZE];
//     int length;
// }SeqList;

// SeqList * CreatList();
// void PrintList(SeqList *q);
// void reverse(SeqList *q );

// main()
// {
//     SeqList *q;
//     q=CreatList();
//     reverse(q);
//     PrintList(q);
// }

// SeqList * CreatList()
// {
//     SeqList *sq = (SeqList*)malloc(sizeof(SeqList));
//     scanf("%d",&(sq->length));
//     for(int i=0;i<sq->length;i++)
//     {
//         scanf("%d",&(sq->elem[i]));
//     }
//     return sq;
// }
// void PrintList(SeqList *sq)
// {
//     for(int i=0;i<sq->length;i++)
//         printf("%d ",sq->elem[i]);
// }

// /* 请在这里填写答案 */
// 输入样例：
// 在这里给出一组输入。例如：

// 6
// 1 2 3 4 5 6
// 输出样例：
// 在这里给出相应的输出。例如：

// 6 5 4 3 2 1 

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
