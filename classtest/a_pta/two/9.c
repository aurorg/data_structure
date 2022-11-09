#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node {
    int coef;
    int expn;
    struct node *next;
}Node, *List;

List Creat(int i) {
    List head;
    head = (List)malloc(sizeof(Node));
    List pre, p;
    pre = head;
    char a,b;
    for(int k = 0; k <= i; k++) {
        p = (List)malloc(sizeof(Node));
        scanf("%c%d,%d%c", &a, &p->coef, &p->expn, &b);
        pre -> next = p;
        pre = p;
    }
    return head;
}

void Print(List head) {
    List q = head->next->next;
    int flag = 1;
    if(!q) {
        putchar('0');
        printf("\n");
        return;
    }
    while(q) {
        if(q->coef > 0 && flag != 1) {
            putchar('+');
        }
        if(q->coef != 1 && q->coef != -1) {
            printf("%d", q->coef);
            if(q->expn == 1) {
                putchar('X');
            } else if (q->expn) {
                printf("X^%d", q->expn);
            }
        } else {
            if(q->coef == 1) {
                if(!q->expn) {
                    putchar('1');
                } else if (q->expn == 1) {
                    putchar('X');
                } else {
                    printf("X^%d", q->expn);
                }
            }
            if(q->coef == -1) {
                if(!q->expn) {
                    printf("-1");
                } else if(q->expn == 1) {
                    printf("-X");
                } else {
                    printf("-X^%d", q->expn);
                }
            }
        }
        q = q->next;
        flag++;
    }
}

void Process(List head) {
    List pre = head->next;
    while (pre->next) {
        if (pre->next && pre->next->expn == 0) {
            pre->next = pre->next->next;
        }
        pre = pre->next;
        pre->coef *= pre->expn;
        pre->expn--;
    }
}

int main() {
    int i;
    scanf("%d", &i);
    List head;
    head = Creat(i);
    Process(head);
    Print(head);
}