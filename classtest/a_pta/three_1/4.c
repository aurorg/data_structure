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
