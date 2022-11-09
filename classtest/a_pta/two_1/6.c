// 6-6 从单链表LA指定位置删除连续n个元素并插入单链表LB的指定位置
// 分数 15
// 作者 曾艳
// 单位 西安邮电大学
// 设指针la和lb分别指向两个无头结点单链表中的首元结点，试编写算法，从表la中删除自第i个元素起共len个元素，并将它们插入表lb的第j个元素之后。

// 函数接口定义：
// void MoveLaToLb(LinkList *pa,int i,int len,LinkList *pb,int j);
// 其中 pa 和 pb 分别为两个单链表的头指针la和lb的指针。 i, j, len的意义与题目描述部分相同。注意：对参数的合法性进行必要的判断，以下几种情况认为参数不合法，不进行移动。
// （1）当la表中不存在第i个元素，或者自第i个元素起后面不足 len个元素。
// （2）当lb表中不存在第j个元素。（特别注意：当j值为0时，为合法参数，则在lb表第1个元素之前进行插入）

// 类型定义如下：

// typedef int DataType;
// typedef struct node 
// {
//     DataType data;
//     struct node *next;
// }LNode,*LinkList;
// 裁判测试程序样例：
// #include <stdio.h>
// #include <stdlib.h>
// typedef int DataType;
// typedef struct node 
// {
//     DataType data;
//     struct node *next;
// }LNode,*LinkList;

// LinkList CreatLinkList();  //创建无头结点单链表,并返回头指针。
// void PrintLinkList(LinkList H);//依次输出无头结点单链表H中各个元素结点，若为空表则输出NONE。
// void MoveLaToLb(LinkList *pa,int i,int len,LinkList *pb,int j);
// main()
// {
//     LinkList la,lb;
//     int i,j,len;
//     la = CreatLinkList();
//     lb = CreatLinkList();
//     scanf("%d %d %d",&i,&j,&len);
//     MoveLaToLb(&la,i,len,&lb,j);
//     PrintLinkList(la);
//     PrintLinkList(lb);
// }

// LinkList CreatLinkList()
// {
//     int n,i;
//     LNode *nw,*rear=NULL,*head=NULL;
//     scanf("%d",&n);//接收结点总数
//     for(i=0;i<n;i++)
//     {
//         nw=(LNode*)malloc(sizeof(LNode));
//         scanf("%d",&nw->data);
//         if(rear==NULL)
//             rear=head=nw;
//         else
//         {
//             rear->next=nw;
//             rear=nw;
//         }
//     }
//     if(rear)
//         rear->next=NULL;
//     return head;
// }

// void PrintLinkList(LinkList H)
// {
//     LNode *p;
//     if(!H)
//     {    
//         printf("NONE\n");
//         return;
//     }
//     for(p=H;p;p=p->next)
//         printf("%d ",p->data);
//     printf("\n");
// }


// /* 请在这里填写答案 */
// 输入样例1：
// 7
// 1 2 3 4 5 6 7
// 6
// 11 22 33 44 55 66
// 3 4 2
// 输出样例1：
// 1 2 5 6 7 
// 11 22 33 44 3 4 55 66 
// 输入样例2：
// 7
// 1 2 3 4 5 6 7
// 6
// 11 22 33 44 55 66
// 1 0 4
// 输出样例2：
// 5 6 7 
// 1 2 3 4 11 22 33 44 55 66 
// 输入样例3：
// 7
// 1 2 3 4 5 6 7
// 6
// 11 22 33 44 55 66
// 6 2 4
// 输出样例3：
// 1 2 3 4 5 6 7 
// 11 22 33 44 55 66 
// 输入样例4：
// 3
// 1 2 3
// 4
// 11 22 33 44
// 1 4 3
// 输出样例4：
// NONE
// 11 22 33 44 1 2 3 

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

