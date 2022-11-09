// 6-4 删除顺序表中指定值元素
// 分数 15
// 作者 曾艳
// 单位 西安邮电大学
// 删除给定顺序表中值为x的元素。

// 其中顺序表定义如下：

// #define MAXSIZE 100
// typedef int ElemType;
// typedef struct
// {
//     ElemType elem[MAXSIZE];
//     int length;
// }SeqList;
// 函数接口定义：
// void DeleteX(SeqList *q,ElemType x);
// 其中 q 和 x 都是用户传入的参数。 q 为指向顺序表的指针； x为待删除元素。

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
// void PrintList(SeqList *sq);
// void DeleteX(SeqList *q,ElemType x);


// main()
// {
//     SeqList *q;
//     ElemType x;
//     q=CreatList();
//     scanf("%d",&x);
//     DeleteX(q,x);
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

// 8
// 2 4 6 2 7 2 2 8
// 2
// 输出样例：
// 在这里给出相应的输出。例如：

// 4 6 7 8 

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