// 7-4 网络寻路
// 分数 20
// 作者 王燕
// 单位 西安邮电大学
// X 国的一个网络使用若干条线路连接若干个节点。节点间的通信是双向的。某重要数据包，为了安全起见，必须恰好被转发两次到达目的地。该包可能在任意一个节点产生，我们需要知道该网络中一共有多少种不同的转发路径。
// 源地址和目标地址可以相同，但中间节点必须不同。

// 如下图所示的网络。
// 1 -> 2 -> 3 -> 1 是允许的
// 1 -> 2 -> 1 -> 2 或者 1 -> 2 -> 3 -> 2 都是非法的。

// 输入格式:
// 输入数据的第一行为两个整数N M，分别表示结点个数和连接线路的条数(1<=N<=100; 0<=M<=100)。
// 接下去有M行，每行为两个整数 u 和 v，表示节点u 和 v 连通(1<=u,v<=N , u!=v)。
// 输入数据保证任意两点最多只有一条边连接，并且没有自己连自己的边，即不存在重边和自环。

// 输出格式:
// 输出一个整数，表示满足要求的路径条数。

// 输入样例:
// 输出一个整数，表示满足要求的路径条数。

// 3 3
// 1 2
// 2 3
// 1 3
// 输出样例:
// 在这里给出相应的输出。例如：

// 6
#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 20
typedef int Vextype;
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
    Vextype v1, v2;
    scanf("%d %d", &(G->vexnum), &(G->arcnum));
    char s[100];
    for (i = 1; i <= G->vexnum; i++) {
        for (j = 1; j <= G->vexnum; j++)
            G->arcs[i][j] = 0;
    }
    for (k = 1; k <= G->arcnum; k++) {
        scanf("%d %d", &v1, &v2);
        G->arcs[v1][v2] = 1;
        G->arcs[v2][v1] = 1;
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
void test(AdjMatrix M) {
    int out[MAXVEX] = {0};
    for (int i = 1; i <= M.vexnum; i++) {
        for (int j = 1; j <= M.vexnum; j++) {
            if (M.arcs[i][j]) {
                out[i]++;
            }
        }
    }
    int ans=0;
    for (int i = 1; i <= M.vexnum; i++) {
        for (int j = 1; j < i; j++) {
            if(M.arcs[i][j]){
                ans+=(out[i]-1)*(out[j]-1)*2;
            }
        }
    }
    printf("%d",ans);
}
