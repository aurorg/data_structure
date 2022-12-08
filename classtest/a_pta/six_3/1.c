// 7-1 有向图的创建、求度、遍历
// 分数 50
// 作者 曾艳
// 单位 西安邮电大学
// 从键盘接收有向图的顶点集，弧集，创建有向图，并完成下列任务：

// （1）计算结点的出度、入度以及度;

// (2) 从第一个顶点出发，求一个深度优先遍历序列;

// (3) 从第一个顶点顶点出发，求一个广度优先遍历序列。

// 注意：以用户输入各个顶点的顺序为顶点的序号。

//       在深度和广度优先遍历中，优先选择序号小的顶点。
// 输入格式:
// 第一行输入两个整数，以空格隔开，分别代表图的顶点数n和弧数e。(顶点个数<=20)
// 第二行依次输入顶点值，类型为字符，中间不用间隔符。
// 接下去有e行，每行为两个字符 uv（中间没有间隔符），表示一条弧<u,v>。

// 输出格式:
// 连续输出n行，依次为各个结点的出度和入度，格式为【顶点w 出度值 入度值 度值】，四者间用空格隔开。
// 接下去的一行，输出深度优先遍历顶点序列（顶点间无间隔符）。

// 最后一行，输出广度优先遍历顶点序列（顶点间无间隔符）。

// 输入样例:
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

// A 2 1 3
// B 1 2 3
// C 1 2 3
// D 2 1 3
// E 1 1 2
// ABCDE
// ABECD

#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 200
#define INFINITY 32767
typedef struct {
    int arcs[MAXVEX][MAXVEX];
    char vex[MAXVEX];
    int vexnum;
    int arcnum;
}AdiMatrix;

typedef struct Queue {
    char array[MAXVEX];
    int rear;
    int front;
}Queue;

void Init(Queue *q) {
    q->front = q->rear = MAXVEX;
}

void EnterQueue(Queue *q, char v0) {
    q->rear = (q->rear + 1) % MAXVEX;
    q->array[q->rear] = v0;
}

int Empty(Queue q) {
    if (q.rear == q.front) {
        return 1;
    } else {
        return 0;
    }
}


void DeleteQueue(Queue *q, char *v) {
    q->front = (q->front + 1) % MAXVEX;
    *v = q->array[q->front];
}


int LocateVex(AdiMatrix *g, char v) {
    for (int i = 1; i <= g->vexnum; i++) {
        if (g->vex[i] == v) {
            return i;
        }
    }
    return 0;
}


void Create(AdiMatrix *g) {
    scanf("%d %d", &g->vexnum, &g->arcnum);
    getchar();
    for (int i = 1; i <= g->vexnum; i++) {
        for (int j = 1; j <= g->vexnum; j++) {
            g->arcs[i][j] = 0;
        }
    }
    for (int i = 1; i <= g->vexnum; i++) {
        scanf("%c", &g->vex[i]);
    }
    for (int k = 1; k <= g->arcnum; k++) {
        char vex1, vex2;
        getchar();
        scanf("%c", &vex1);
        int i = LocateVex(g, vex1);
        scanf("%c", &vex2);
        int j = LocateVex(g, vex2);
        g->arcs[i][j] = 1;
    }
    
}

//输出的格式
void Output(AdiMatrix *g) {
    for (int i = 1; i <= g->vexnum; i++) {
        int count1 = 0, count2 = 0;
        printf("%c ", g->vex[i]);
        for (int j = 1; j <= g->vexnum; j++) {
            if (g->arcs[i][j] == 1) {
                count1++;
            }
        }
        for (int k = 1; k <= g->vexnum; k++) {
            if (g->arcs[k][i] == 1) {
                count2++;
            }
        }
        printf("%d %d %d", count1, count2, count1 + count2);
        printf("\n");
    }
}
int visited[MAXVEX] = {0};
char FirstAdjVex(AdiMatrix *g, char v0) {
    int i;
    for (i = 1; i <= g->vexnum; i++) {
        if (g->vex[i] == v0) {
            break;
        }
    }
    for (int j = 1; j <= g->vexnum; j++) {
        if (g->arcs[i][j] == 1 && visited[g->vex[j]] == 0) {
            return g->vex[j];
        }
    }
    return -1;
}
int NextAdjVex(AdiMatrix *g, char v0, char w) {
    int i;
    for (i = 1; i <= g->vexnum; i++) {
        if (g->vex[i] == v0) {
            break;
        }
    }
    for (int j = 1; j <= g->vexnum; j++) {
        if (g->arcs[i][j] == 1 && g->vex[j] != w  && visited[g->vex[j]] == 0) {
            return g->vex[j];
        }
    }
    return -1;
}
void DFS(AdiMatrix *g, char v0) {
    printf("%c", v0);
    visited[v0] = 1;
    int w = FirstAdjVex(g, v0);
    while (w != -1) {
        if (!visited[w]) {
            DFS(g, w);
            w = NextAdjVex(g, v0, w);
        }
    }
}

void TraverseG(AdiMatrix *g) {
    for (int i = 1; i <= g->vexnum; i++) {
        if (!visited[g->vex[i]]) {
            DFS(g, g->vex[i]);
        }
    }
}

void BFS(AdiMatrix *g, int v0) {
    printf("%c", v0);
    visited[v0] = 1;
    Queue q;
    Init(&q);
    EnterQueue(&q, v0);
    int w;
    while (!Empty(q)) {
        char v;
        DeleteQueue(&q, &v);
        w = FirstAdjVex(g, v);
        while (w != -1) {
            if (!visited[w]) {
                printf("%c", w);
                visited[w] = 1;
                EnterQueue(&q, w);
            }
            w = NextAdjVex(g, v, w);
        }
    }
}

void TraverseG2(AdiMatrix *g) {
    for (int i = 1; i <= g->vexnum; i++) {
        if (!visited[g->vex[i]]) {
            BFS(g, g->vex[i]);
        }
    }
}

int main(int argc, const char * argv[]) {
    AdiMatrix *g;
    g = (AdiMatrix *)malloc(sizeof(AdiMatrix));
    Create(g);
    Output(g);
    TraverseG(g);
    for (int i = 0; i < MAXVEX; i++) {
        visited[i] = 0;
    }
    
    printf("\n");
    
    TraverseG2(g);
    printf("\n");
    return 0;
}