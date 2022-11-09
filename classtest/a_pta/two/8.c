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