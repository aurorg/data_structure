// 7-9 一元多项式运算器——求导
// 分数 10
// 作者 王燕
// 单位 西安邮电大学
// 实现多项式的求导运算

// 输入格式:
// 第一、二行按2.3.1的格式，输入一个多项式；

// 输出格式:
// 按2.3.1的格式，输出其导数多项式。

// 输入样例:
// 在这里给出一组输入。例如：

// 4 
// (6,0)(2,1)(8,7)(4,15) 
// 输出样例:
// 在这里给出相应的输出。例如：

// 2+56X^6+60X^14


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