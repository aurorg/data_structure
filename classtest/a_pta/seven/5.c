// 7-2 图的创建和遍历
// 分数 20
// 作者 王燕
// 单位 西安邮电大学
// 从键盘接收图的顶点集，关系集，创建有向图。计算结点的出度和入度，并输出。

// 输入格式:
// 第一行依次输入图的顶点个数n，关系个数k，以空格隔开。顶点个数<=20
// 第二行依次输入顶点值，类型为字符。
// 接下去有k行，每行为两个字符 u 和 v，表示节点u 和 v 连通。格式为【uv】,中间不用空格间隔。

// 输出格式:
// 格式为【顶点w 出度值 入度值】，三者用空格间隔。
// 接下去的一行，从A顶点出发，进行深度优先遍历，并输出，结点不间隔。
// 最后一行，从A顶点出发，进行广度优先遍历，并输出，结点不间隔。
// 若以邻接表存储，则某顶点的邻接点中，序号小的在前，序号大的在后。

// 输入样例:
// 在这里给出一组输入。例如：

// 5 7
// ABCDE
// AB
// AE
// BC
// CD
// DA
// DB
// EC
// 输出样例:
// 在这里给出相应的输出。例如：

// A 2 1
// B 1 2
// C 1 2
// D 2 1
// E 1 1
// ABCDE
// ABECD
#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 20
typedef char Vextype;
typedef struct {
    int arcs[MAXVEX + 1][MAXVEX + 1];
    Vextype vex[MAXVEX + 1];
    int vexnum;
    int arcnum;
} AdjMatrix;

typedef struct ArcNode {
    int adjvex;
    struct ArcNode *next;
} ArcNode;
typedef struct {
    Vextype vexdata;
    ArcNode *head;
} VertexNode;
typedef struct {
    VertexNode vertex[MAXVEX];
    int vexnum;
    int arcnum;
} AdjList;

void Creat_AdjMatrix(AdjMatrix *G); //创建邻接矩阵
int LocateVex_AdjMatrix(AdjMatrix *G, Vextype v);
void Print_AdjList(AdjList *G); //输出邻接表
void AdjMatrixToAdjList(AdjMatrix *M, AdjList *L); //邻接矩阵转换为邻接表
void test(AdjMatrix M);

int main() {
    AdjMatrix gM;
    AdjList gL;
    Creat_AdjMatrix(&gM);
    test(gM);
    return 0;
}
void Creat_AdjMatrix(AdjMatrix *G) //创建邻接矩阵
{
    int i, j, k;
    char v1, v2;
    scanf("%d %d", &(G->vexnum), &(G->arcnum));
    char s[100];
    scanf("%s", s);
    for (i = 1; i <= G->vexnum; i++) {
        G->vex[i] = s[i - 1];
        for (j = 1; j <= G->vexnum; j++)
            G->arcs[i][j] = 0;
    }
    for (k = 1; k <= G->arcnum; k++) {
        char s1[2];
        scanf("%s", s);
        v1 = s[0];
        v2 = s[1];
        i = LocateVex_AdjMatrix(G, v1);
        j = LocateVex_AdjMatrix(G, v2);
        G->arcs[i][j] = 1;
    }
}
int LocateVex_AdjMatrix(AdjMatrix *G, Vextype v) //输出邻接表
{
    int i;
    for (i = 1; i <= G->vexnum; i++)
        if (G->vex[i] == v)
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
int print[MAXVEX] = {1, 1};
void dfs(int last,AdjMatrix M){
    for (int i = 1; i <= M.vexnum; i++){
        if (M.arcs[last][i]) {
            if (print[i] == 0){
                printf("%c", M.vex[i]);
                print[i]=1;
                dfs(i,M);
            }
        }
    }
}
void test(AdjMatrix M) {
    int in[MAXVEX] = {0}, out[MAXVEX] = {0};
    for (int i = 1; i <= M.vexnum; i++) {
        for (int j = 1; j <= M.vexnum; j++) {
            if (M.arcs[i][j]) {
                in[j]++;
                out[i]++;
            }
        }
    }
    for (int i = 1; i <= M.vexnum; i++) {
        printf("%c %d %d\n", M.vex[i], out[i], in[i]);
    }
    int print[MAXVEX] = {1, 1};
    printf("A");
    dfs(1,M);
    printf("\nA");
    int print1[MAXVEX] = {1,1};
    int fifo[2*MAXVEX]={1},start=0,end=1,count=0;
    while(start<end&&count<M.vexnum){
        for (int i = 1; i <= M.vexnum; i++){
            if(M.arcs[fifo[start]][i]&&(print1[i]==0)){
                printf("%c",M.vex[i]);
                fifo[end++]=i;
                print1[i]=1;
                count++;
            }
        }
        start++;
    }
}