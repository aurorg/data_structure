// 7-4 一元多项式运算器——建立与输出
// 分数 40
// 作者 王燕
// 单位 西安邮电大学
// 通过键盘接收一组多项式的系数和指数，建立多项式（要求各项按指数升序排列），并按指定格式输出。

// 输入格式:
// 第一行输入一个正整数n，表示非零项个数。
// 第二行输入n对整数，每对形如(7,3)，表示系数为7、指数为3的项。

// 输出格式:
// 按多项式形式输出，各项按指数升序排列，例如6+2X-7X^8

// 输入样例:
// 在这里给出一组输入。例如：

// 4
// (6,0)(2,1)(-8,70)(4,150) 
// 输出样例:
// 在这里给出相应的输出。例如：

// 6+2X-8X^70+4X^150

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct List {
    int id;
    int index;
    struct List *next;
}Node,*LinkList;
Node *CreatList(int n);
void PrintList(Node *head);
int main(void) {
    int n;
    scanf("%d",&n);
    getchar();
    Node *h=CreatList(n);
    PrintList(h);
}
Node *CreatList(int n) {
    Node *head=(Node *)malloc(sizeof(Node));
    head->next=NULL;
    Node *pre=head;
    Node *pnew;
    int i=0,id,index;
    char a,b;
    while(i<n) {
        pnew=(Node *)malloc(sizeof(Node));
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
            if(s->index==0) printf("%d",s->id);
            else if(s->index==1) printf("%dX",s->id);
            else printf("%dX^%d",s->id,s->index);
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