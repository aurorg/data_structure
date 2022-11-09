// 7-1 约瑟夫环（Josephus）问题
// 分数 100
// 作者 王燕
// 单位 西安邮电大学
// 编号为1，2，…，n的n个人按顺时针方向围坐在一张圆桌周围，每人持有一个密码（正整数）。一开始任选一个正整数m作为报数上限值，从第一个人开始按顺时针方向自1开始报数，报到m时停止报数，报m的那个人出列，将他的密码作为新的m值，从他顺时针方向的下一个人开始重新从1报数，数到m的那个人又出列；如此下去，直至圆桌周围的人全部出列为止。要求按出列顺序输出n个人的编号。

// 输入格式:
// 第一行输入两个整数，依次表示人数n和初始化密码m，以空格间隔。 第二行依次输入n个整数，分别表示n个人的密码，以空格间隔。

// 输出格式:
// 按出列次序输出每个人的编号，以空格间隔。

// 输入样例:
// 在这里给出一组输入。例如：

// 7 20
// 3 1 7 2 4 8 4 
// 输出样例:
// 在这里给出相应的输出。例如：

// 6 1 4 7 2 3 5 

#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode {
    int index;
    int number;
     
    struct ListNode *next;
} Node;
Node *CreatList(int n);
void JosephusList(Node *head,int m);
int main(void) {
    int n, m;
    scanf("%d%d", &n, &m);
    Node *head = CreatList(n);
    JosephusList(head,m);
}
Node *CreatList(int n) {
    Node *head=(Node *)malloc(sizeof(Node));
    head->next=NULL;
    int x;
    scanf("%d",&x);
    head->number=x;
    head->index=1;
    Node *s=head;
    int i=1,m1;
    while(i<n) {
        Node *p=(Node *)malloc(sizeof(Node));
        scanf("%d",&m1);
        p->number=m1;
        p->index=(++i);
        p->next=NULL;
        s->next=p;
        s=p;
    }
    s->next=head;
    return head;
}
void JosephusList(Node *head, int m) {
    Node *p = head;
    Node *q = head;
    while (q->next != head)
        q = q->next;
    int temp = m;
    while (p->next != p) {
        for (int i = 1; i < temp; i++) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        temp = p->number;
        printf("%d ", p->index);
        free(p);
        p = q->next;
    }
    printf("%d ", p->index);
    free(p);
}