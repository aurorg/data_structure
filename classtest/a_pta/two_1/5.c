#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
typedef struct node 
{
    DataType data;
    struct node *next;
}LNode,*LinkList;

LinkList Creat_CircularList();  //创建无头结点循环单链表,并返回头指针。
LNode * SetPointerS(LinkList H,int x);//返回指向第x个结点的指针。
void PrintCircularList(LNode *S);//从指针S所指结点开始，依次输出各个结点的值。
void DelPrior(LNode *S);
main()
{
    LNode *s;
    LinkList H;
    int x;
    H = Creat_CircularList();
    scanf("%d",&x);
    s=SetPointerS(H,x);
    DelPrior(s);
    PrintCircularList(s);
}

LinkList Creat_CircularList()
{
    int n,i;
    LNode *nw,*rear=NULL,*head=NULL;
    scanf("%d",&n);//接收结点总数
    for(i=0;i<n;i++)
    {
        nw=(LNode*)malloc(sizeof(LNode));
        scanf("%d",&nw->data);
        if(rear==NULL)
            rear=head=nw;
        else
        {
            rear->next=nw;
            rear=nw;
        }
    }
    if(rear)
        rear->next=head;
    return head;
}

void PrintCircularList(LinkList s)
{
    LNode *p;
    for(p=s;p->next!=s;p=p->next)
        printf("%d ",p->data);
    printf("%d",p->data);
}

LNode * SetPointerS(LinkList H,int x)
{
    int i;
    LNode *s=H;
    for(i=1;i<x;i++)
        s=s->next;
    return s;
 }


/* 请在这里填写答案 */
void DelPrior(LNode *s){
	int temp;
	LNode *p;//p为q的前驱结点 
    LNode *t;//t为要删除结点s的前驱； 
	p=t=s;
    
	while(t->next!=s)
    {
		t=t->next;
	}
	while(p->next!=t)
        
	p=p->next;
	temp=t->data;
	p->next=s;
    
	free(t);
    
}