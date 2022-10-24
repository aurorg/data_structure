#include <stdio.h>
//课本
#define DataType int
typedef struct node{
    DataType data;
    struct node * next;
}LNode,*LinkList;

//头插法建立单链表
LinkList Creat_LinkList1(){
    LinkList H =(LinkList)malloc(sizeof(LNode));
    H->next=NULL;
    LNode *s;
    int x;
    scanf("%d",&x);
    while(x!=-1){
        s=(LinkList)malloc(sizeof(LNode));
        s->data=x;
        s->next=H->next;
        H->next=s;
        scanf("%d",&x);
    }
    return H;
}

//尾插法建立单链表
LinkList creat_LinkList2(){
    LinkList H =(LinkList)malloc(sizeof(LNode));
    H ->next=NULL;
    LNode *s,*r=H;
    int x;
    scanf("%d",&x);
    while(x!=-1){
        s=(LinkList)malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;
        scanf("%d",&x);
    }
    r->next=NULL;
    return H;
}

//求单链表的表长
int Length_LinkList(LinkList H){
    LNode *p=H;
    int j=0;
    while(p->next !=NULL){
        p=p->next;
        j++;
    }
    return j;
}

//单链表按照序号查找
LinkList Get_LinkList(LinkList H,int k){
    LNode *p=H;
    int j=0;
    while(p->next!=NULL && j<k){
        p=p->next;
        j++;
    }
    if(j==k){
        return p;
    }else{
        return NULL;
    }
}

//单链表中按值查找
LNode *Locate(LinkList H,DataType x){
    LNode *p=H->next;
    while(p!=NULL && p->data!=x){
        p=p->next;
    }
    return p;
}

//单链表插入结点
int Insert_LinkList(LinkList H,int i,DataType x){
    LNode *p,*s;
    p=Get_LinkList(H,i-1);
    if(p==NULL){
        printf("插入位置i错");
        return 0;
    }
    else{
        s=(LinkList)malloc(sizeof(LNode));
        s->data=x;
        s->next=p->next;
        p->next=s;
        return 1;
    }
}

//单链表删除结点
int Del_LinkList(LinkList H,int i){
    LinkList p,q;
    p=Get_LinkList(H,i-1);
    if(p==NULL){
        printf("第i个结点不存在");
        return 0;
    }else{
        if(p->next==NULL){
            printf("第i个结点不存在");
            return 0;
        }else{
            q=p->next;
            p->next=q->next;
            free(q);
            return 1;
        }
    }
}

//单链表的逆置
void Reverse(LinkList H){
    LNode *p,*q;
    p=H->next;//p指向第一个数据结点
    H->next=NULL;//将原链表置为空表H
    while(p){
        q=p;
        p=q->next;
        q->next=H->next;//将当前结点插到头结点的后面
        H->next=q;
    }
}