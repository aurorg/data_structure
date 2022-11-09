#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct List {
    int id;
    int index;
    struct List *next;
}Node,*LinkList;
void PrintList(Node *head);
Node *AddList(Node *h1,Node *h2);
Node *CreatList(int n);
 
int main(void) {
    int n1,n2;
    scanf("%d",&n1);
    getchar();
    Node *h1=CreatList(n1);
    scanf("%d",&n2);
    getchar();
    Node *h2=CreatList(n2);
    Node *head=AddList(h1,h2);
    PrintList(head);
}
Node *CreatList(int n) {
    Node *head=(Node *)malloc(sizeof(Node));
    head->next=NULL;
    Node *pre=head;
    Node *pnew;
    int i=0,id,index;
    char a,b;
    while(i<n) {
        pnew=(Node *)malloc(sizeof(Node));//
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
            
            if(s->index==0) 
                printf("%d",s->id);
            else if(s->index==1) 
                printf("%dX",s->id);
            else 
                printf("%dX^%d",s->id,s->index);
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
Node *AddList(Node *h1,Node *h2) {
    Node *head=(Node *)malloc(sizeof(Node));
    head->next=NULL;
    Node *s=head;
    
    Node *p1=h1->next;
    Node *p2=h2->next;
    Node *h;
    while(p1!=NULL && p2!=NULL) {
        
        h=(Node *)malloc(sizeof(Node));
        
        if(p1->index<p2->index) {
            
            h->id=p1->id;
            h->index=p1->index;
            p1=p1->next;
            s->next=h;
            s=h;
        }else if(p1->index>p2->index) {
            
            h->id=p2->id;
            h->index=p2->index;
            p2=p2->next;
            s->next=h;
            s=h;
            
        }
        
        
        else {
            
            h->index=p1->index;
            h->id=p1->id+p2->id;
            if(h->id==0) free(h);
            else {
                
                s->next=h;
                s=h;
                
            }
            p1=p1->next;
            p2=p2->next;
        }
    }
    while(p1==NULL && p2) {
        h=(Node *)malloc(sizeof(Node));
        
        h->id=p2->id;
        h->index=p2->index;
        p2=p2->next;
        s->next=h;
        s=h;
    }
    while(p2==NULL && p1) {
        
        h=(Node *)malloc(sizeof(Node));
        
        h->id=p1->id;
        h->index=p1->index;
        
        p1=p1->next;
        s->next=h;
        s=h;
    }
    return head;
}