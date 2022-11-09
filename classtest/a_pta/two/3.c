// 7-3 约瑟夫（Josephus）排列问题Step2
// 分数 15
// 作者 王燕
// 单位 西安邮电大学
// 对于给定的1，2，3，…，n中的k个数，Josephus想知道是否存在一个正整数m(m≤n),使得Josephus（n,m）排列的最后k个数恰好为事先指定的k个数。例如当n为7，k为4，指定排列的最后k个数为7,5,1,4时；由于（7,3）Josephus排列为3,6,2,7,5,1,4；所以求得m值为3。

// 输入格式:
// 第一行输入m以及k，
// 第二行依次指定的k个数，以空格间隔。

// 输出格式:
// 如果存在满足条件的正整数m, 则输出m;否则输出0。

// 输入样例:
// 在这里给出一组输入。例如：

// 7 4 
// 7 5 1 4 
// 输出样例:
// 在这里给出相应的输出。例如：

// 3

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