#include <stdio.h>
#define ElemType int
#define OK 1
#define ERROR 0
#define  RUE 1
#define FALSE 0
typedef int Status;

int main(void){

return 0;
}

typedef struct Node{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *LinkList;


//单链表的读取

Status GetElem(LinkList L,int i,ElemType *e){
    int j;
    LinkList p;
    p=L->next;
    j=1;
    while(p && j<i){
        p=p->next;
        ++j;
    }
    if(!p || j>i){
        return ERROR;
    }

    *e=p->data;
    return OK;

}

Status ListInsert(LinkList *L,int i,ElemType e){
    int j;
    LinkList p,s;
    p=*L;
    j=1;
    while(p && j<i){

    }
}

    
