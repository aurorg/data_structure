// 7-5 大臣的旅费
// 分数 20
// 作者 王燕
// 单位 西安邮电大学
// 很久以前，T王国空前繁荣。为了更好地管理国家，王国修建了大量的快速路，用于连接首都和王国内的各大城市。
// 为节省经费，T国的大臣们经过思考，制定了一套优秀的修建方案，使得任何一个大城市都能从首都直接或者通过其他大城市间接到达。同时，如果不重复经过大城市，从首都到达每个大城市的方案都是唯一的。
// J是T国重要大臣，他巡查于各大城市之间，体察民情。所以，从一个城市马不停蹄地到另一个城市成了J最常做的事情。他有一个钱袋，用于存放往来城市间的路费。
// 聪明的J发现，如果不在某个城市停下来修整，在连续行进过程中，他所花的路费与他已走过的距离有关，在走第x千米到第x+1千米这一千米中（x是整数），他花费的路费是x+10这么多。也就是说走1千米花费11，走2千米要花费23。
// J大臣想知道：他从某一个城市出发，中间不休息，到达另一个城市，所有可能花费的路费中最多是多少呢？

// 输入格式:
// 输入的第一行包含一个整数n，表示包括首都在内的T王国的城市数
// 城市从1开始依次编号，1号城市为首都。
// 接下来n-1行，描述T国的高速路（T国的高速路一定是n-1条）
// 每行三个整数Pi, Qi, Di，表示城市Pi和城市Qi之间有一条高速路，长度为Di千米。

// 输出格式:
// 输出一个整数，表示大臣J最多花费的路费是多少。

// 输入样例:
// 在这里给出一组输入。例如：

// 5
// 1 2 2
// 1 3 1
// 2 4 5
// 2 5 4
// 输出样例:
// 在这里给出相应的输出。例如：

// 135
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
    scanf("%d", &(G->vexnum));
    char s[100];
    for (i = 1; i <= G->vexnum; i++) {
        for (j = 1; j <= G->vexnum; j++)
            G->arcs[i][j] = 0;
    }
    for (k = 1; k < G->vexnum; k++) {
        scanf("%d %d %d", &v1, &v2, &i);
        G->arcs[v1][v2] = i;
        G->arcs[v2][v1] = i;
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

/* 请在这里填写答案 */
int count = 0, max = 0;
int print[MAXVEX]={1};
void dfs(int last, AdjMatrix M,int sum) {
    int sign = 1;
    for (int i = 1; i <= M.vexnum; i++) {
        if (M.arcs[last][i]&&print[i]==0) {
            sign=0;
            print[i]=1;
            dfs(i, M,sum+M.arcs[last][i]);
            print[i]=0;
        }
    }
    if(sign&&sum>max){
        max=sum;
    }
}

void test(AdjMatrix M) {
    for(int i=1;i<=M.vexnum;i++){
        print[i]=1;
        dfs(i,M,0);
        print[i]=0;
    }
    printf("%d",(max+21)*max/2);
}
