// 7-7 邻接矩阵实现拓扑排序
// 分数 10
// 作者 曾艳
// 单位 西安邮电大学
// 已知有向无权图G，求出其拓扑有序序列。(要求：用邻接矩阵存储图，用栈存储度为0的结点。)

// 输入格式:
// 第一行输入两个正整数n和m（空格间隔）， 分别表示图G的顶点总数和弧的总数。
// 第二行连续输入n个字母，分别表示n个顶点的信息。

// 第三行连续输入m条弧的信息，每条弧的输入格式为<v1,v2>，表示一条从顶点v1到v2的弧。

// 输出格式:
// 依拓扑序列输出各个顶点（各顶点间无间隔符号）。

// 输入样例:
// 8 10
// ABCDEFGH
// <A,C><A,G><B,G><B,H><C,D><G,D><G,F><H,F><D,E><F,E>
// 输出样例:
// BHAGFCDE
#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 20
typedef char Vextype;

typedef struct ArcNode {
    int adjvex;
    struct ArcNode *next;
} ArcNode;

typedef struct {
    int in;//入度
    Vextype vexdata;
    ArcNode *head;
} VertexNode;
typedef struct {
    VertexNode vertex[MAXVEX];
    int vexnum;
    int arcnum;
} AdjList;
void Creat_AdjList(AdjList *G);
int LocateVex_AdjList(AdjList *G, Vextype v);
void Print_AdjList(AdjList *G); //输出邻接表
void test(AdjList M);

int main() {

    AdjList gL;
    Creat_AdjList(&gL);
    test(gL);
    return 0;
}
void Creat_AdjList(AdjList *G) {
    int i, j, k;
    char v1, v2;
    scanf("%d %d\n", &(G->vexnum), &(G->arcnum));
    char s[100];
    scanf("%s\n", s);
    for (i = 1; i <= G->vexnum; i++) {
        G->vertex[i].in = 0;
        G->vertex[i].vexdata = s[i - 1];
        G->vertex[i].head = NULL;
    }
    for (k = 1; k <= G->arcnum; k++) {
        ArcNode *p;
        scanf("<%c,%c>", &v1, &v2);
        i = LocateVex_AdjList(G, v1);
        j = LocateVex_AdjList(G, v2);
        p = (ArcNode *) malloc(sizeof(ArcNode));
        p->adjvex = j;
        p->next = G->vertex[i].head;
        G->vertex[i].head = p;
        G->vertex[j].in++;
    }
}
int LocateVex_AdjList(AdjList *G, Vextype v) {
    int i;
    for (i = 1; i <= G->vexnum; i++)
        if (G->vertex[i].vexdata == v)
            return i;
    return 0;
}
void Print_AdjList(AdjList *G) {
    int i;
    ArcNode *p;
    for (i = 1; i <= G->vexnum; i++) {
        printf("%d:(%c)", i, G->vertex[i].vexdata);
        for (p = G->vertex[i].head; p; p = p->next) {
            printf("->%d", p->adjvex);
        }
        printf("\n");
    }
}
void test(AdjList M) {
    int top = 0, stack[MAXVEX] = {0},top1=0;
    for (int i = 1; i <= M.vexnum; i++) {
        if (!M.vertex[i].in) {
            stack[top++] = i;
        }
    }
    while (top) {
        int get = stack[--top];
        printf("%c", M.vertex[get].vexdata);
        ArcNode* stack1[MAXVEX];
        ArcNode *p = M.vertex[get].head;
        for (; p; p = p->next) {
            ArcNode *t=p;
            stack1[top1++]=t;
        }
        for(int i=top1-1;i>=0;i--){
            if (!(--M.vertex[stack1[i]->adjvex].in)) {
                stack[top++] = stack1[i]->adjvex;
            }
        }
    top1=0;
    }

}