// 6-3 队列的操作集合（带尾指针的循环链表）
// 分数 18
// 作者 曾艳
// 单位 西安邮电大学
// 假设以带头结点的循环链表表示队列，并且只设一个指针指向队尾元素结点，试编写相应的初始化队列、判空队、入队和出队算法。（队中元素均为整数）

// 程序功能为：初始化一个空队列，然后接收命令并完成相应操作，命令如下：

// ENQUEUE x 将整数x入队。若操作成功则无输出，若操作失败则输出FULL!。

// DELQUEUE 出队一个元素。若操作成功则输出该元素，若失败则输EMPTY QUEUE!。

// ISEMPTY 判断队列是否为空。若为空则输出 EMPTY,若非空则输出NOT EMPTY。

// END 依次输出队列中所有元素，释放结点空间，并结束程序。

// 函数接口定义：
// CirLinkQueue InitQueue();  //初始化队列，返回值为队列的尾指针。
// int IsEmptyQueue(CirLinkQueue Q); //队列判空，若为空，则返回1；非空，返回0。
// int EnQueue(CirLinkQueue *Q, DataType x);  //  元素x入队，若操作成功，则返回1；操作失败，则返回0。
// int DelQueue(CirLinkQueue *Q, DataType *x);  //  出队一个元素，若操作成功，则返回1；操作失败，则返回0。
// 说明：队列使用仅带尾指针的循环链表表示，数据类型定义如下：

// typedef int DataType;
// typedef struct node
// {      DataType  data;
//        struct node *next; 
// }LNode,*CirLinkQueue;
// 裁判测试程序样例：
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// typedef int DataType;
// typedef struct node
// {      DataType  data;
//        struct node *next; 
// }LNode,*CirLinkQueue;

// //队列的基本操作函数定义
// CirLinkQueue InitQueue();  //初始化队列，返回值为队列的尾指针。
// int IsEmptyQueue(CirLinkQueue Q); //队列判空，若为空，则返回1；非空，返回0。
// int EnQueue(CirLinkQueue *Q, DataType x);  //  元素x入队，若操作成功，则返回1；操作失败，则返回0。
// int DelQueue(CirLinkQueue *Q, DataType *x);  //  出队一个元素，若操作成功，则返回1；操作失败，则返回0。
// void DestroyQueue(CirLinkQueue Q);

// int main(void)
// {
//     char cmd[20];
//     CirLinkQueue pQueue = InitQueue();
//     DataType x;
//     scanf("%s", cmd);
//     while (strcmp(cmd, "END") != 0)
//     {
//         if (strcmp(cmd, "ENQUEUE") == 0)
//         {
//             scanf("%d", &x);
//             if (EnQueue(&pQueue, x) == 0)
//                  printf("FULL QUEUE!\n");
//         }
//         else if (strcmp(cmd, "DELQUEUE") == 0)
//         {
//             if (DelQueue(&pQueue,&x) == 0)
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
//         scanf("%s", cmd);
//     }
//     DestroyQueue(pQueue);
//     return 0;
// }

// void DestroyQueue(CirLinkQueue Q)
// {
//     LNode *p,*t;
//     p=Q;Q=Q->next;
//     p->next=NULL;
//     p=Q->next;
//     while(p)
//     {
//         printf("%d ",p->data);
//         t=p->next;
//         free(p);
//         p=t;
//     }
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

typedef int DataType;
typedef struct node
{      DataType  data;
       struct node *next; 
}LNode,*CirLinkQueue;

//队列的基本操作函数定义
CirLinkQueue InitQueue();  //初始化队列，返回值为队列的尾指针。
int IsEmptyQueue(CirLinkQueue Q); //队列判空，若为空，则返回1；非空，返回0。
int EnQueue(CirLinkQueue *Q, DataType x);  //  元素x入队，若操作成功，则返回1；操作失败，则返回0。
int DelQueue(CirLinkQueue *Q, DataType *x);  //  出队一个元素，若操作成功，则返回1；操作失败，则返回0。
void DestroyQueue(CirLinkQueue Q);

int main(void)
{
    char cmd[20];
    CirLinkQueue pQueue = InitQueue();
    DataType x;
    scanf("%s", cmd);
    while (strcmp(cmd, "END") != 0)
    {
        if (strcmp(cmd, "ENQUEUE") == 0)
        {
            scanf("%d", &x);
            if (EnQueue(&pQueue, x) == 0)
                 printf("FULL QUEUE!\n");
        }
        else if (strcmp(cmd, "DELQUEUE") == 0)
        {
            if (DelQueue(&pQueue,&x) == 0)
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
        scanf("%s", cmd);
    }
    DestroyQueue(pQueue);
    return 0;
}

void DestroyQueue(CirLinkQueue Q)
{
    LNode *p,*t;
    p=Q;Q=Q->next;
    p->next=NULL;
    p=Q->next;
    while(p)
    {
        printf("%d ",p->data);
        t=p->next;
        free(p);
        p=t;
    }
    free(Q);
}

/* 请在这里填写答案 */

CirLinkQueue InitQueue(){
 CirLinkQueue Q;
 Q=(CirLinkQueue)malloc(sizeof(LNode));
 Q->next=Q;
 return Q;
}

int IsEmptyQueue(CirLinkQueue Q){
 if(Q->next==Q){
     return 1;
 }
 else{
     return 0;
 }
}

int EnQueue(CirLinkQueue *Q, DataType x){
 LNode *p1;
 p1=(LNode *)malloc(sizeof(LNode));
 if(p1==NULL)
 {
     return 0;
 }

 p1->data=x;
 p1->next=(*Q)->next;
 (*Q)->next=p1;
 (*Q)=p1; 
    
 return 1;
    
}
int DelQueue(CirLinkQueue *Q, DataType *x){
 if(IsEmptyQueue(*Q))
 {
     return 0;
 }
    
 CirLinkQueue r=*Q,p2;
 p2=r->next->next;
 if(p2==r)
 {     
  *Q=r->next;
  *x=p2->data;
  r->next->next=p2->next;
 }
else{
  *x=p2->data;
  r->next->next=p2->next;
 }
    return 1;
}