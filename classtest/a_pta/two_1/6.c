#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
typedef struct node 
{
    DataType data;
    struct node *next;
}LNode,*LinkList;

LinkList CreatLinkList();  //创建无头结点单链表,并返回头指针。
void PrintLinkList(LinkList H);//依次输出无头结点单链表H中各个元素结点，若为空表则输出NONE。
void MoveLaToLb(LinkList *pa,int i,int len,LinkList *pb,int j);
main()
{
    LinkList la,lb;
    int i,j,len;
    la = CreatLinkList();
    lb = CreatLinkList();
    scanf("%d %d %d",&i,&j,&len);
    MoveLaToLb(&la,i,len,&lb,j);
    PrintLinkList(la);
    PrintLinkList(lb);
}

LinkList CreatLinkList()
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
        rear->next=NULL;
    return head;
}

void PrintLinkList(LinkList H)
{
    LNode *p;
    if(!H)
    {    
        printf("NONE\n");
        return;
    }
    for(p=H;p;p=p->next)
        printf("%d ",p->data);
    printf("\n");
}


/* 请在这里填写答案 */
int number(LinkList h){
        LinkList p0;
		int n=0;
		p0=h;
		while(p0){
			n++;
			p0=p0->next;
		}
		return n;
	}

void MoveLaToLb(LinkList *pa,int i,int len,LinkList *pb,int j){
    
    
	int n1;
    int n2;
    n1=number(*pa);
	n2=number(*pb);
    
	int temp=1;
	LinkList p1,p2,p3,p4,p5;
 
    
	if(n1<i || n2<j  || n1<i+len-1 ){
	
        return;
    }
    
	else{
        
		p1=*pa;
		while(temp<i-1){
			p1=p1->next;
			temp++;
		}
		 
		p2=*pb;
        temp=1;
		while(temp<j){
			p2=p2->next;
			temp++;
		}
        
		temp=1;
		p3=*pa;
        
        //将p1,p2,p3移动位置
		while(temp<i+len-1){
			p3=p3->next;
			temp++;
		} 
        
		if(n1==i+len-1){
			p4=p2->next;
			p2->next=p1;
			p3->next=p4;
			*pa=NULL;
		} 
        
		else if(j){
			p4=p2->next;//移动的头 
            
			p5=p3->next;//重连的头 
			if(i==1){
				p2->next=p1;
				p3->next=p4;
				*pa=p5;
			}
			else{
				p2->next=p1->next;
				p3->next=p4;
				p1->next=p5; 
			}
		}
        
		else if(!j){
            
			p5=p3->next;
			p3->next=*pb;
            
			if(i==1){
				*pb=p1;
				*pa=p5;
			}
            
			else{
				*pb=p1->next;
				p1->next=p5;
			}
		}
	}
	
}

