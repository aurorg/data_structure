// 6-5 循环队列的操作集合（增设tag）
// 分数 18
// 作者 曾艳
// 单位 西安邮电大学
// 在循环队列中，可以设置一个标志域tag，以区分当尾指针和头指针相等时，队列的状态是“空”还是“满”。编写此结构相应的队列初始化、入队、出队算法以及判空、判满算法。（队中元素均为整数，为了便于测试，数组做大容量设定为4。）

// 程序功能为：初始化一个空队列，然后接收命令并完成相应操作，命令如下：
// ENQUEUE x 将整数x入队。若操作成功则无输出，若操作失败则输出FULL QUEUE!。

// DELQUEUE 出队一个元素。若操作成功则输出该元素，若失败则输EMPTY QUEUE!。

// ISEMPTY 判断队列是否为空。若为空则输出 EMPTY，若非空则输出NOT EMPTY。

// ISFULL 判断队列是否已满。若满则输出 FULL，否则输出NOT FULL。

// END 依次输出队列中所有元素，释放结点空间，并结束程序。

// 函数接口定义：
// SeqQueue * InitQueue();  //初始化队列，返回值为指向队列的指针。
// int IsEmptyQueue(SeqQueue *Q); //队列判空，若为空，则返回1；非空，返回0。
// int IsFullQueue(SeqQueue *Q); //队列判满，若为满，则返回1；非满，返回0。
// int EnQueue(SeqQueue *Q, ElemType x);  //  元素x入队，若操作成功，则返回1；操作失败，则返回0。
// int DelQueue(SeqQueue *Q, ElemType *x);  //  出队一个元素，若操作成功，则返回1；操作失败，则返回0。
// 说明：循环队列类型定义如下：

// #define MAXSIZE 4 //队列的最大容量
// typedef int ElemType;
// typedef struct
// {      
//     ElemType  elem[MAXSIZE];
//     int rear;  //队尾元素的位置
//     int front; //对头元素的前一个位置
//     int tag;//标志最近一次队列操作是入队还是出队。入队设为1，出队设为0。
// }SeqQueue;
// 裁判测试程序样例：
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #define MAXSIZE 4 //队列的最大容量
// typedef int ElemType;
// typedef struct
// {      
//     ElemType  elem[MAXSIZE];
//     int rear;  //队尾元素的位置
//     int front; //对头元素的前一个位置
//     int tag;//标志最近一次队列操作是入队还是出队。入队设为1，出队设为0。
// }SeqQueue;

// //队列的基本操作函数定义
// SeqQueue * InitQueue();  //初始化队列，返回值为指向队列的指针。
// void DestroyQueue(SeqQueue *Q); //依次输出队列中元素值，并释放空间。

// int IsEmptyQueue(SeqQueue *Q); //队列判空，若为空，则返回1；非空，返回0。
// int IsFullQueue(SeqQueue *Q); //队列判满，若为满，则返回1；非满，返回0。
// int EnQueue(SeqQueue *Q, ElemType x);  //  元素x入队，若操作成功，则返回1；操作失败，则返回0。
// int DelQueue(SeqQueue *Q, ElemType *x);  //  出队一个元素，若操作成功，则返回1；操作失败，则返回0。


// int main(void)
// {
//     char cmd[20];
//     SeqQueue *pQueue=InitQueue();
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

// void DestroyQueue(SeqQueue *Q)
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

// ISEMPTY
// ENQUEUE 1
// ENQUEUE 2
// DELQUEUE
// DELQUEUE
// DELQUEUE
// ENQUEUE 3
// ISEMPTY
// ENQUEUE 4
// ENQUEUE 5
// DELQUEUE
// END
// 输出样例：
// 在这里给出相应的输出。例如：

// EMPTY
// 1
// 2
// EMPTY QUEUE!
// NOT EMPTY
// 3
// 4 5 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 4 //队列的最大容量
typedef int ElemType;
typedef struct
{      
    ElemType  elem[MAXSIZE];
    int rear;  //队尾元素的位置
    int front; //对头元素的前一个位置
    int tag;//标志最近一次队列操作是入队还是出队。入队设为1，出队设为0。
}SeqQueue;

//队列的基本操作函数定义
SeqQueue * InitQueue();  //初始化队列，返回值为指向队列的指针。
void DestroyQueue(SeqQueue *Q); //依次输出队列中元素值，并释放空间。

int IsEmptyQueue(SeqQueue *Q); //队列判空，若为空，则返回1；非空，返回0。
int IsFullQueue(SeqQueue *Q); //队列判满，若为满，则返回1；非满，返回0。
int EnQueue(SeqQueue *Q, ElemType x);  //  元素x入队，若操作成功，则返回1；操作失败，则返回0。
int DelQueue(SeqQueue *Q, ElemType *x);  //  出队一个元素，若操作成功，则返回1；操作失败，则返回0。


int main(void)
{
    char cmd[20];
    SeqQueue *pQueue=InitQueue();
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

void DestroyQueue(SeqQueue *Q)
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
//初始化队列，返回值为指向队列的指针。
SeqQueue * InitQueue(){
 
    SeqQueue *Q;
 Q=(SeqQueue *)malloc(sizeof(SeqQueue));
 Q->front=Q->rear=-1;
    
 return Q;
}

//队列判空，若为空，则返回1；非空，返回0。
int IsEmptyQueue(SeqQueue *Q){
 if(Q->tag==0&&Q->rear==Q->front){
     return 1;
 }
    else{
 return 0;
    }
}

//队列判满，若为满，则返回1；非满，返回0。
int IsFullQueue(SeqQueue *Q){
 if(Q->tag==1&&Q->rear==Q->front)
 {
     return 1;
 }
    else{
 return 0;
    }
}

 //  元素x入队，若操作成功，则返回1；操作失败，则返回0。
int EnQueue(SeqQueue *Q, ElemType x){
 if(IsFullQueue(Q))
 {
     return 0;
 }
 Q->rear=(Q->rear+1)%MAXSIZE;
 Q->elem[Q->rear]=x;
 Q->tag=1;
 return 1;
}

//  出队一个元素，若操作成功，则返回1；操作失败，则返回0。
int DelQueue(SeqQueue *Q, ElemType *x){
 if(IsEmptyQueue(Q)){
     return 0;
 }
 Q->front=(Q->front+1)%MAXSIZE;
 *x=Q->elem[Q->front];
 Q->tag=0;
 return 1;
}