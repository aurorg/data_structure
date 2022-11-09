// 7-8 一元多项式运算器——求值
// 分数 10
// 作者 王燕
// 单位 西安邮电大学
// 对于给定的X值，求出多项式的值。

// 输入格式:
// 第一、二行按2.3.1的格式，输入一个多项式；
// 第三行输入X的值。

// 输出格式:
// 输出多项式的值

// 输入样例:
// 在这里给出一组输入。例如：

// 4 
// (6,0)(2,3)(8,5)(7,10) 
// 2 
// 输出样例:
// 在这里给出相应的输出。例如：

// 7446

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct List {
    int ident; 
    int index; 
    struct List *next;
}Node,*LinkList;
Node *CreatList(int n);
int GetResult(Node *head,int x);
int main(void) {
    int n;
    scanf("%d",&n);
    getchar();
    Node *h=CreatList(n);
    int x;
    scanf("%d",&x);
    int result=GetResult(h,x);
    printf("%d",result);
}
Node *CreatList(int n) {
    Node *head=(Node *)malloc(sizeof(Node));
    head->next=NULL;
    Node *pre=head;
    Node *pnew;
    int i=0,ident,index;
    char a,b;
    while(i<n) {
        pnew=(Node *)malloc(sizeof(Node));
        scanf("%c%d,%d%c",&a,&ident,&index,&b);
        pnew->ident=ident;pnew->index=index;
        pre->next=pnew;
        pnew->next=NULL;
        pre=pnew;
        i++;
    }
    return head;
}
int GetResult(Node *head,int x) {
    int sum=0;
    Node *p=head->next;
    while(p!=NULL) {
        sum+=p->ident*pow(x,p->index);
        p=p->next;
    }
    return sum;
}