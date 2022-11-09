// 6-2 单链表逆置
// 分数 10
// 作者 曾艳
// 单位 西安邮电大学
// 设有一线性表e={e1,e2,...,en-1,en)，其逆线性表定义为e'={en,en-1,...,e2,e1}。请设计一个算法，将线性表逆置，要求逆线性表仍占用原线性表的空间，并且用单链表来表示，写出逆置函数。

// 函数接口定义：
// void Reverse( LinkList head );
// q 是用户传入的参数，为单链表的头指针。其中类型定义如下：

// typedef int DataType;
// typedef struct node
// {
//     DataType data;
//     struct node *next;
// }LNode,*LinkList;
// 裁判测试程序样例：

// #include<stdio.h>
// #include<stdlib.h>
// typedef int DataType;
// typedef struct node
// {
//     DataType data;
//     struct node *next;
// }LNode,*LinkList;

// LinkList CreatList(); 
// void PrintList(LinkList head );
// void Reverse( LinkList head );

// main()
// {
//     LinkList q;
//     q=CreatList();
//     Reverse(q);
//     PrintList(q);
// }


// LinkList  CreatList()
// {
//     LinkList h = (LinkList)malloc(sizeof(LNode));
//     LNode *p,*tail= h;
//     int n;
//     scanf("%d",&n);
//     for(int i=0;i<n;i++)
//     {   
//         p=(LNode*)malloc(sizeof(LNode));
//         scanf("%d",&(p->data));
//         tail->next = p;
//         tail = p;
//     }
//     tail->next=NULL;
//     return h;
// }
// void PrintList(LinkList head )
// {
//      LNode *p = head->next;
//      while (p) 
//      {
//          printf("%d ", p->data);
//          p = p->next;
//      }
// }


// /* 请在这里填写答案 */
// 输入样例：
// 在这里给出一组输入。例如：

// 5
// 1 2 3 4 5
// 输出样例：
// 在这里给出相应的输出。例如：

// 5 4 3 2 1 


#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
typedef struct node
{
    DataType data;
    struct node *next;
}LNode,*LinkList;

LinkList CreatList(); 
void PrintList(LinkList head );
void Reverse( LinkList head );

main()
{
    LinkList q;
    q=CreatList();
    Reverse(q);
    PrintList(q);
}


LinkList  CreatList()
{
    LinkList h = (LinkList)malloc(sizeof(LNode));
    LNode *p,*tail= h;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {   
        p=(LNode*)malloc(sizeof(LNode));
        scanf("%d",&(p->data));
        tail->next = p;
        tail = p;
    }
    tail->next=NULL;
    return h;
}
void PrintList(LinkList head )
{
     LNode *p = head->next;
     while (p) 
     {
         printf("%d ", p->data);
         p = p->next;
     }
}


/* 请在这里填写答案 */
void Reverse( LinkList head ){
	LinkList q;
    LinkList  p;
	q=head->next;
	head->next=NULL;
	while(q)
    {
		p=q;
		q=q->next;
		p->next=head->next;
		head->next=p;
	}
    
}