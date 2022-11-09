// 6-7 两个单链表元素交叉合并
// 分数 15
// 作者 曾艳
// 单位 西安邮电大学
// 设带头结点的线性单链表A={a1,a2,...,am}，B={b1,b2,...,bn} 。试编写算法按下列规则合并A、B为线性单链表C，使得

//      C={a1,b1,a2,b2,...am,bm,...,bn} ，  m<=n
//      或者
//      C={b1,a1,b2,a2,...,bn,an,...,am} ,   m>n
// 函数接口定义：
// LinkList CombineList(LinkList La,LinkList Lb);
// 其中 La 和 Lb 都是用户传入的参数，分别为待合并单链表的头指针。函数须返回合并后的单链表的头指针。

// 裁判测试程序样例：
// #include <stdio.h>
// #include <stdlib.h>
// typedef int DataType;
// typedef struct node 
// {
//     DataType data;
//     struct node *next;
// }LNode,*LinkList;

// LinkList CreatLinkList();  //创建带头结点单链表,并返回头指针。
// void PrintLinkList(LinkList H);//依次输出单链表H中各个元素结点，若为空表则输出NONE。
// LinkList CombineList(LinkList La,LinkList Lb);
// main()
// {
//     LinkList la,lb;
//     la = CreatLinkList();
//     lb = CreatLinkList();
//     la=CombineList(la,lb);
//     PrintLinkList(la);
// }

// LinkList CreatLinkList()
// {
//     int n,i;
//     LNode *nw,*rear=NULL,*head=NULL;
//     head=(LNode*)malloc(sizeof(LNode));
//     rear=head;
//     scanf("%d",&n);//接收结点总数
//     for(i=0;i<n;i++)
//     {
//         nw=(LNode*)malloc(sizeof(LNode));
//         scanf("%d",&nw->data);
//         rear->next=nw;
//         rear=nw;
//     }
//     rear->next=NULL;
//     return head;
// }

// void PrintLinkList(LinkList H)
// {
//     LNode *p;
//     if(!(H->next))
//     {    
//         printf("NONE\n");
//         return;
//     }
//     for(p=H->next;p;p=p->next)
//         printf("%d ",p->data);
//     printf("\n");
// }


// /* 请在这里填写答案 */
// 输入样例：
// 在这里给出一组输入。例如：

// 4
// 1 2 3 4
// 6
// 11 22 33 44 55 66
// 输出样例：
// 在这里给出相应的输出。例如：

// 1 11 2 22 3 33 4 44 55 66 

#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
typedef struct node 
{
    DataType data;
    struct node *next;
}LNode,*LinkList;

LinkList CreatLinkList();  //创建带头结点单链表,并返回头指针。
void PrintLinkList(LinkList H);//依次输出单链表H中各个元素结点，若为空表则输出NONE。
LinkList CombineList(LinkList La,LinkList Lb);
main()
{
    LinkList la,lb;
    la = CreatLinkList();
    lb = CreatLinkList();
    la=CombineList(la,lb);
    PrintLinkList(la);
}

LinkList CreatLinkList()
{
    int n,i;
    LNode *nw,*rear=NULL,*head=NULL;
    head=(LNode*)malloc(sizeof(LNode));
    rear=head;
    scanf("%d",&n);//接收结点总数
    for(i=0;i<n;i++)
    {
        nw=(LNode*)malloc(sizeof(LNode));
        scanf("%d",&nw->data);
        rear->next=nw;
        rear=nw;
    }
    rear->next=NULL;
    return head;
}

void PrintLinkList(LinkList H)
{
    LNode *p;
    if(!(H->next))
    {    
        printf("NONE\n");
        return;
    }
    for(p=H->next;p;p=p->next)
        printf("%d ",p->data);
    printf("\n");
}


/* 请在这里填写答案 */
LinkList CombineList(LinkList La,LinkList Lb){
    LinkList q=Lb;
    LinkList p=La;
    LinkList  c=(LinkList)malloc(sizeof(LNode));
    int x=0,y=0;
     c->next=NULL;
    LinkList r= c,t;
     
    
     while(p->next!=NULL){
        p=p->next;
        x++;
    }
    
     while(q->next!=NULL){
        q=q->next;
        y++;
     }

    
    
    if(x<=y){
        
         p=La->next;
         q=Lb->next;
        
    }
    else{
         p=Lb->next;
         q=La->next;
     }
    
    while(p&&q){
         
         if(p){
            t=p;
            p=p->next;
            r->next=t;
            r=r->next;
        }
          if(q){
            t=q;
            q=q->next;
            r->next=t;
            r=r->next;
        }
 
    }
    if(p) r->next=p;
    if(q) r->next=q;
    return c;
    
}