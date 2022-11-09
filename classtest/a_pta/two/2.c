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