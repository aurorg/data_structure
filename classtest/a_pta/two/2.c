// 7-2 约瑟夫（Josephus）排列问题Step1
// 分数 15
// 作者 王燕
// 单位 西安邮电大学
// 编号为1，2，…，n的n个人按顺时针方向围坐在一张圆桌周围。给定一个正整数m≤n，从第一个人开始按顺时针方向自1开始报数，每报到m时就让其出列，从
// 他顺时针方向的下一个人开始重新从1报数，数到m的那个人又出列。如此下去，直至圆桌周围的人全部出列为止。每个人的出列次序定义了整数1，2，3，…，n的一个排列。这个
// 排列称为一个（n,m）Josephus排列。例如：（7，3）Josephus排列为3，6，2，7，5，1，4。

// 输入格式:
// 输入两个整数，人数n和密码m，以空格间隔。

// 输出格式:
// 按出列次序输出每个人的编号，以空格间隔。

// 输入样例:
// 在这里给出一组输入。例如：

// 7 3 
// 输出样例:
// 在这里给出相应的输出。例如：

// 3 6 2 7 5 1 4 

#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode {
    int index;
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
    head->index=1;
    Node *s=head;
    int i=1;
    while(i<n) {
        Node *p=(Node *)malloc(sizeof(Node));
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
    while (p->next != p) {
        for (int i = 1; i < m; i++) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        printf("%d ", p->index);
        free(p);
        p = q->next;
    }
    printf("%d ", p->index);
    free(p);
}