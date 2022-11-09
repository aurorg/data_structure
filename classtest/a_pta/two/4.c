#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct List {
    int id;
    int index;
    struct List *next;
}Node,*LinkList;
Node *CreatList(int n);
void PrintList(Node *head);
int main(void) {
    int n;
    scanf("%d",&n);
    getchar();
    Node *h=CreatList(n);
    PrintList(h);
}
Node *CreatList(int n) {
    Node *head=(Node *)malloc(sizeof(Node));
    head->next=NULL;
    Node *pre=head;
    Node *pnew;
    int i=0,id,index;
    char a,b;
    while(i<n) {
        pnew=(Node *)malloc(sizeof(Node));
        scanf("%c%d,%d%c",&a,&id,&index,&b);
        pnew->id=id;pnew->index=index;
        pre->next=pnew;
        pre=pnew;
        i++;
    }
    return head;
}
void PrintList(Node *head) {
    Node *s=head->next;
    while(s) {
        if(s->id!=1 && s->id!=-1) {
            if(s->index==0) printf("%d",s->id);
            else if(s->index==1) printf("%dX",s->id);
            else printf("%dX^%d",s->id,s->index);
        }
        else {
            if(s->index==0) printf("%d",s->id);
            else {
                if(s->id==-1) printf("-");
                printf("X^%d",s->index);
            }
        }
        s=s->next;
        if(s!=NULL && s->id>0) printf("+");
    }
}