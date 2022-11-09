#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node {
    int coef;
    int expn;
    struct node *next;
}Node, *List;
//声明
List CreatList(int i);
 
List Plus(List head1, List head2);
List Multiply (List head1, List head2);

void Print(List head);
List CopyList (List head);

int main() {
    int ner1,nert2;
    List head1, head2;
    scanf(" %d", &ner1);
    head1 = CreatList(ner1);
    scanf("%d", &nert2);
    head2 = CreatList(nert2);
    List head = Multiply(head1, head2);
    Print(head);
}
List CreatList(int i) {
    List head;
    head = (List)malloc(sizeof(Node));
    List pre, pnew;
    pre = head;
    char a,b;
    for(int j = 0; j <= i; j++) {
        pnew = (List)malloc(sizeof(Node));
        scanf("%c%d,%d%c", &a, &pnew->coef, &pnew->expn, &b);
        pre -> next = pnew;
        pre = pnew;
    }
    return head;
}
void Print(List head) {
    Node *s=head->next->next;
    while(s) {
        if(s->coef!=1 && s->coef!=-1) {
            if(s->expn==0) printf("%d",s->coef);
            else if(s->expn==1) printf("%dX",s->coef);
            else printf("%dX^%d",s->coef,s->expn);
        }
        else {
            if(s->expn==0) printf("%d",s->coef);
            else {
                if(s->coef==-1) printf("-");
                printf("X^%d",s->expn);
            }
        }
        s=s->next;
        if(s!=NULL && s->coef>0) printf("+");
    }
}
List CopyList (List head) {
    List newHead = (List)malloc(sizeof(Node));
    newHead->next = NULL;
    List p = head->next;
    List p2 = newHead;
    while (p) {
        List new = (List)malloc(sizeof(Node));
        new->coef = p->coef;
        new->expn = p->expn;
        p2->next = new;
        p2 = new;
        p = p->next;
    }
    p2->next = NULL;
    return newHead;
}
List Plus(List head1, List head2) {
    List pre = NULL, p = NULL, qre = NULL, q = NULL;
    pre = head1->next;
    p = head1->next->next;
    qre = head2->next;
    q = head2->next->next;
    int index = 1;
    
    while (p != NULL) {
        if (q == NULL) {
            return head1;
        }
        if (p->expn == q->expn) {
            p->coef = p->coef + q->coef;
            if (p->coef == 0) {
                pre->next = p->next;
                free(p);
                if (pre) {
                    p = pre->next;
                } else {
                    p = NULL;
                }
                qre->next = q->next;
                free(q);
                if (qre) {
                    q = qre->next;
                } else {
                    q = NULL;
                }
            } else {
                pre = p;
                p = p->next;
                qre->next = q->next;
                free(q);
                if (qre) {
                    q = qre->next;
                } else {
                    q = NULL;
                }
            }
        } else if (p->expn > q->expn) {
            qre->next = q->next;
            q->next = p;
            pre->next = q;
            pre = q;
            q = qre->next;
        } else if (q->expn > p->expn && p->next &&q->expn < (p->next)->expn) {
            qre->next = q->next;
            pre = p;
            p = p->next;
            q->next = p;
            pre->next = q;
            pre = q;
            q = qre->next;
        } else if (q->expn > p->expn && p->next && q->expn >= (p->next)->expn) {
            pre = p;
            p = p->next;
        } else {
            pre = p;
            break;
        }
        index ++;
    }
    if (q) pre->next = q;
    return head1;
}
List Multiply (List head1, List head2) {
    
    List p2 = head2->next->next;
    
    List newHead = (List)malloc(sizeof(Node));
    List pp = (List)malloc(sizeof(Node));
    newHead->next = pp;
    
    pp->next = NULL;
    List p1;
    List head1Pre = CopyList(head1);
    List res = NULL;
    while (p2) {
        p1 = head1->next->next;
        while (p1) {
            
            p1->coef *= p2->coef;
            p1->expn += p2->expn;
            p1 = p1->next;
        }
        
        p2 = p2->next;
        res = Plus(head1, newHead);
        newHead = CopyList(head1);
        head1 = CopyList(head1Pre);
    }
    return res;
}
    