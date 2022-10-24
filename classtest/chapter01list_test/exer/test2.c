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