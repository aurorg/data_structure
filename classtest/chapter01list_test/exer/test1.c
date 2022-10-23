#include <stdio.h>
#define ElemType int
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status; //Status是函数的类型，其值是函数结果状态代码

int main(void){


return 0;
}

typedef struct Node{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *LinkList;  //定义LinkList


//单链表的读取
//初始条件：顺序线性表L已经存在，1<=i<=ListLength(L)
//操作结果：用e返回L中第i个数据元素的值
Status GetElem(LinkList L,int i,ElemType *e){
    int j;
    LinkList p; //声明一指针p
    p=L->next;  //让p指向链表的L的第一个结点
    j=1;        //j为计数器
    while(p && j<i){ //p不为空并且计数器j还没有等于i时，循环继续
        p=p->next; //p指向下一个结点
        ++j;

    }
    if(!p || j>i){
        return ERROR; //第i个结点不存在
    }

    *e=p->data;  //取第i个结点的数据
    return OK;
}


//单链表的插入
//在L中第i个结点位置之前插入新的数据元素e，L的长度加1
Status ListInsert(LinkList *L,int i,ElemType e){
    int j;
    LinkList p,s;
    p=*L;
    j=1;
    while(p && j<i){   //寻找第i-1个结点
        p=p->next;
        ++j;
    }
    if(!p || j>i){
        return ERROR;  //第i个结点不存在
    }

    s=(LinkList)malloc(sizeof(Node));//生成新的结点
    s->data=e;
    s->next=p->next;//将p的后继结点赋值给s的后继
    p->next=s;//将s赋值给p的后继
    return OK;
}


//单链表的删除
//删除L的第i个结点，并且e返回其值，L的长度减1
Status ListDelete(LinkList *L,int i,ElemType *e){
    int  j;
    LinkList p,q;
    p=*L;
    j=1;
    while(p->next && j<i){
        p=p->next;
        ++j;
    }
    if(!(p->next) || j>i){
        return ERROR;
    }
    q=p->next;
    p->next =q->next;
    *e=q->data;
    free(q);
    return OK;
}

