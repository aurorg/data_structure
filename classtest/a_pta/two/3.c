#include <stdio.h>
#include <stdlib.h>
typedef struct List {
    int index;
    struct List *next;

}Node;
Node *CreatList(int n) {
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    head->index = 1;
    Node *s = head;
    for (int i=2;i<=n;i++) {
        Node *p=(Node *)malloc(sizeof(Node));
        p->index=i;
        p->next=NULL;
        s->next=p;
        s=p;
    }
    s->next = head;
    return head;
}
int JosephusList(int temp, int n) {
    int arr[1000];
    int i,m;
    for (i = 0; i < temp; i++)
        scanf("%d", &arr[i]);
    Node *head;
    Node *p;
    Node *q;
    for (m = 1; m <= m; m++) {
        head =CreatList(n);
        p = head;
        q = head;
        while (q->next != head)
            q = q->next;
        int count = 0, c = 1;
        while (p->next != p) {
            for (i = 1; i < m; i++) {
                q = p;
                p = p->next;
            }
            q->next = p->next;
            count++;
            if (count > n - temp) {
                arr[1000 - c] = p->index;
                c++;
            }
            free(p);
            p = q->next;
        }
        arr[1000 - temp] = p->index;
        int f= 0;
        for (i = 0; i < temp; i++) {
            if (arr[i] != arr[1000 - i - 1]) {
                f= 1;
                break;
            }
        }
        if (!f) return m;
        free(p);
    }
}
int main(void) {
    int n,k;
    scanf("%d%d", &n, &k);
    int m=JosephusList(k,n);
    printf("%d",m);
}