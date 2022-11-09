// 7-6 一元多项式运算器——减法
// 分数 30
// 作者 王燕
// 单位 西安邮电大学
// 实现两个一元多项式相减运算。

// 输入格式:
// 按2.3.1的格式，第一、二行输入被减数；第三、四行输入减数。

// 输出格式:
// 按2.3.1的格式，输出差多项式。

// 输入样例:
// 在这里给出一组输入。例如：

// 4 
// (6,0)(2,6)(8,7)(4,15) 
// 5 
// (7,1)(2,6)(-8,7)(10,20)(16,30)
// 输出样例:
// 在这里给出相应的输出。例如：

// 6-7X+16X^7+4X^15-10X^20-16X^30

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
            p->coef = p->coef - q->coef;
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
//            printf("4\n");
        } else if (p->expn > q->expn) {//多项式1的项的指数大于多项式2的项时
            q->coef = -q->coef;
            qre->next = q->next;
            q->next = p;
            pre->next = q;
            pre = q;
            q = qre->next;
//            printf("3\n");
        } else if (q->expn > p->expn && p->next &&q->expn < (p->next)->expn) {//多项式2的项指数大小在多项式1的项与下一项中间时
            q->coef = -q->coef;
//            printf("1\n");
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
    if (q) { 
        pre->next = q;
        List qq = q;
        while(qq) {
            qq->coef = - qq->coef;
            qq = qq->next;
        }
    }
    return head1;
}

int main() {
    int n1, n2;
    List head1, head2;
    scanf(" %d", &n1);
    head1 = Creat(n1);
    scanf("%d", &n2);
    head2 = Creat(n2);
    List head = Plus(head1, head2);
    Print(head);
}