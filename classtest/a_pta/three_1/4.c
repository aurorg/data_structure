// 6-4 循环队列的操作集合（只设 rear和quelen）
// 分数 18
// 作者 曾艳
// 单位 西安邮电大学
// 假设循环队列中只设rear和quelen来分别指示队尾元素的位置和队中元素的个数，试编写相应的判满、判空、入队和出队算法。（队中元素均为整数，为了便于测试，数组做大容量设定为4。）

// 程序功能为：初始化一个空队列，然后接收命令并完成相应操作，命令如下：
// ENQUEUE x 将整数x入队。若操作成功则无输出，若操作失败则输出FULL QUEUE!。

// DELQUEUE 出队一个元素。若操作成功则输出该元素，若失败则输EMPTY QUEUE!。

// ISEMPTY 判断队列是否为空。若为空则输出 EMPTY，若非空则输出NOT EMPTY。

// ISFULL 判断队列是否已满。若满则输出 FULL，否则输出NOT FULL。

// END 依次输出队列中所有元素，释放结点空间，并结束程序。

// 函数接口定义：
// int IsEmptyQueue(SeQueue *Q); //队列判空，若为空，则返回1；非空，返回0。

// int IsFullQueue(SeQueue *Q); //队列判满，若为满，则返回1；非满，返回0。

// int EnQueue(SeQueue *Q, ElemType x);  //  元素x入队，若操作成功，则返回1；操作失败，则返回0。

// int DelQueue(SeQueue *Q, ElemType *x);  //  出队一个元素，若操作成功，则返回1；操作失败，则返回0。
// 说明：循环队列类型定义如下：

// #define MAXSIZE 4 //队列的最大容量
// typedef int ElemType;
// typedef struct
// {      ElemType  elem[MAXSIZE];
//        int rear;  //队尾元素的位置
//        int quelen; //队中元素的个数
// }SeQueue;
// 裁判测试程序样例：
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #define MAXSIZE 4 //队列的最大容量
// typedef int ElemType;
// typedef struct
// {      ElemType  elem[MAXSIZE];
//        int rear;  //队尾元素的位置
//        int quelen; //队中元素的个数
// }SeQueue;

// //队列的基本操作函数定义
// SeQueue * InitQueue();  //初始化队列，返回值为指向队列的指针。
// void DestroyQueue(SeQueue *Q); //依次输出队列中元素值，并释放空间。

// int IsEmptyQueue(SeQueue *Q); //队列判空，若为空，则返回1；非空，返回0。
// int IsFullQueue(SeQueue *Q); //队列判满，若为满，则返回1；非满，返回0。
// int EnQueue(SeQueue *Q, ElemType x);  //  元素x入队，若操作成功，则返回1；操作失败，则返回0。
// int DelQueue(SeQueue *Q, ElemType *x);  //  出队一个元素，若操作成功，则返回1；操作失败，则返回0。


// int main(void)
// {
//     char cmd[20];
//     SeQueue *pQueue=InitQueue();
//     ElemType x;
//     scanf("%s", cmd);
//     while (strcmp(cmd, "END") != 0)
//     {
//         if (strcmp(cmd, "ENQUEUE") == 0)
//         {
//             scanf("%d", &x);
//             if (EnQueue(pQueue, x) == 0)
//                  printf("FULL QUEUE!\n");
//         }
//         else if (strcmp(cmd, "DELQUEUE") == 0)
//         {
//             if (DelQueue(pQueue,&x) == 0)
//                   printf("EMPTY QUEUE!\n");
//             else
//                 printf("%d\n",x);
//         }
//         else if (strcmp(cmd, "ISEMPTY") == 0)
//         {
//             if (IsEmptyQueue(pQueue) == 0)
//                  printf("NOT EMPTY\n");
//             else
//                   printf("EMPTY\n");
//         }
//         else if (strcmp(cmd, "ISFULL") == 0)
//         {
//             if (IsFullQueue(pQueue) == 0)
//                  printf("NOT FULL\n");
//             else
//                   printf("FULL\n");
//         }
//         scanf("%s", cmd);
//     }
//     DestroyQueue(pQueue);
//     return 0;
// }


// SeQueue *InitQueue()  //初始化队列，返回值为指向队列的指针。
// {
//     SeQueue *q;
//     q=(SeQueue*)malloc(sizeof(SeQueue));
//     q->quelen=0;
//     q->rear=-1;
//     return q;
// }

// void DestroyQueue(SeQueue *Q)
// {
//     ElemType x;
//     while(!IsEmptyQueue(Q))
//     {
//         DelQueue(Q,&x);
//         printf("%d ",x);
//     }
//     printf("\n");
//     free(Q);
// }
// /* 请在这里填写答案 */
// 输入样例：
// 在这里给出一组输入。例如：

// ENQUEUE 1
// ISEMPTY
// ISFULL
// DELQUEUE
// ISEMPTY
// ISFULL
// DELQUEUE
// ENQUEUE 2
// ENQUEUE 3
// DELQUEUE
// ENQUEUE 4
// ENQUEUE 5
// ENQUEUE 6
// ENQUEUE 7
// ISFULL
// ISEMPTY
// DELQUEUE
// ENQUEUE 8
// END
// 输出样例：
// 在这里给出相应的输出。例如：

// NOT EMPTY
// NOT FULL
// 1
// EMPTY
// NOT FULL
// EMPTY QUEUE!
// 2
// FULL QUEUE!
// FULL
// NOT EMPTY
// 3
// 4 5 6 8 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 4 //队列的最大容量
typedef int ElemType;
typedef struct
{      ElemType  elem[MAXSIZE];
       int rear;  //队尾元素的位置
       int quelen; //队中元素的个数
}SeQueue;

//队列的基本操作函数定义
SeQueue * InitQueue();  //初始化队列，返回值为指向队列的指针。
void DestroyQueue(SeQueue *Q); //依次输出队列中元素值，并释放空间。

int IsEmptyQueue(SeQueue *Q); //队列判空，若为空，则返回1；非空，返回0。
int IsFullQueue(SeQueue *Q); //队列判满，若为满，则返回1；非满，返回0。
int EnQueue(SeQueue *Q, ElemType x);  //  元素x入队，若操作成功，则返回1；操作失败，则返回0。
int DelQueue(SeQueue *Q, ElemType *x);  //  出队一个元素，若操作成功，则返回1；操作失败，则返回0。


int main(void)
{
    char cmd[20];
    SeQueue *pQueue=InitQueue();
    ElemType x;
    scanf("%s", cmd);
    while (strcmp(cmd, "END") != 0)
    {
        if (strcmp(cmd, "ENQUEUE") == 0)
        {
            scanf("%d", &x);
            if (EnQueue(pQueue, x) == 0)
                 printf("FULL QUEUE!\n");
        }
        else if (strcmp(cmd, "DELQUEUE") == 0)
        {
            if (DelQueue(pQueue,&x) == 0)
                  printf("EMPTY QUEUE!\n");
            else
                printf("%d\n",x);
        }
        else if (strcmp(cmd, "ISEMPTY") == 0)
        {
            if (IsEmptyQueue(pQueue) == 0)
                 printf("NOT EMPTY\n");
            else
                  printf("EMPTY\n");
        }
        else if (strcmp(cmd, "ISFULL") == 0)
        {
            if (IsFullQueue(pQueue) == 0)
                 printf("NOT FULL\n");
            else
                  printf("FULL\n");
        }
        scanf("%s", cmd);
    }
    DestroyQueue(pQueue);
    return 0;
}


SeQueue *InitQueue()  //初始化队列，返回值为指向队列的指针。
{
    SeQueue *q;
    q=(SeQueue*)malloc(sizeof(SeQueue));
    q->quelen=0;
    q->rear=-1;
    return q;
}

void DestroyQueue(SeQueue *Q)
{
    ElemType x;
    while(!IsEmptyQueue(Q))
    {
        DelQueue(Q,&x);
        printf("%d ",x);
    }
    printf("\n");
    free(Q);
}
/* 请在这里填写答案 */
