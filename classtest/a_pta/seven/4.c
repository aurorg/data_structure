// 7-1 社交网络图中结点的“重要性”计算
// 分数 30
// 作者 DS课程组
// 单位 浙江大学
// 在社交网络中，个人或单位（结点）之间通过某些关系（边）联系起来。他们受到这些关系的影响，这种影响可以理解为网络中相互连接的结点之间蔓延的一种相互作用，可以增强也可以减弱。而结点根据其所处的位置不同，其在网络中体现的重要性也不尽相同。

// “紧密度中心性”是用来衡量一个结点到达其它结点的“快慢”的指标，即一个有较高中心性的结点比有较低中心性的结点能够更快地（平均意义下）到达网络中的其它结点，因而在该网络的传播过程中有更重要的价值。在有N个结点的网络中，结点v 
// i
// ​
//  的“紧密度中心性”Cc(v 
// i
// ​
//  )数学上定义为v 
// i
// ​
//  到其余所有结点v 
// j
// ​
//   (j
// 
// =i) 的最短距离d(v 
// i
// ​
//  ,v 
// j
// ​
//  )的平均值的倒数：



// 对于非连通图，所有结点的紧密度中心性都是0。

// 给定一个无权的无向图以及其中的一组结点，计算这组结点中每个结点的紧密度中心性。

// 输入格式:
// 输入第一行给出两个正整数N和M，其中N（≤10 
// 4
//  ）是图中结点个数，顺便假设结点从1到N编号；M（≤10 
// 5
//  ）是边的条数。随后的M行中，每行给出一条边的信息，即该边连接的两个结点编号，中间用空格分隔。最后一行给出需要计算紧密度中心性的这组结点的个数K（≤100）以及K个结点编号，用空格分隔。

// 输出格式:
// 按照Cc(i)=x.xx的格式输出K个给定结点的紧密度中心性，每个输出占一行，结果保留到小数点后2位。

// 输入样例:
// 9 14
// 1 2
// 1 3
// 1 4
// 2 3
// 3 4
// 4 5
// 4 6
// 5 6
// 5 7
// 5 8
// 6 7
// 6 8
// 7 8
// 7 9
// 3 3 4 9
// 输出样例:
// Cc(3)=0.47
// Cc(4)=0.62
// Cc(9)=0.35

#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 10001
typedef int Vextype;
typedef struct {
    int**arcs;
    Vextype vex[MAXVEX + 1];
    int vexnum;
    int arcnum;
} AdjMatrix;

void Creat_AdjMatrix(AdjMatrix *G); //创建邻接矩阵
int LocateVex_AdjMatrix(AdjMatrix *G, Vextype v);
void test(AdjMatrix M);

int main() {
    AdjMatrix gM;
    Creat_AdjMatrix(&gM);
    test(gM);
    return 0;
}

void Creat_AdjMatrix(AdjMatrix *G) //创建邻接矩阵
{
    int i, j, k;
    Vextype v1, v2;
    scanf("%d %d", &(G->vexnum), &(G->arcnum));
    G->arcs=(int**)malloc(sizeof(int*)*(G->vexnum+1));
    if(G->vexnum>=1500)while(1);
    for (i = 1; i <= G->vexnum; i++) {
        G->arcs[i]=(int*)malloc(sizeof(int)*(G->vexnum+1));
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
/* 请在这里填写答案 */
int min(int a,int b){
    return a>b?b:a;
}
void test(AdjMatrix G) {
    int n=0;
    scanf("%d",&n);
    int*num=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
        //printf("%d ",num[i]);
    }//printf("\n");
    for(int i=1;i<=G.vexnum;i++){
        for(int j=1;j<=G.vexnum;j++){
            if(G.arcs[i][j]){
                for(int k=1;k<=G.vexnum;k++){
                    if(G.arcs[j][k]){
                        if(G.arcs[i][k]==0){
                            G.arcs[k][i]=G.arcs[i][k]=G.arcs[i][j]+G.arcs[j][k];
                        } else
                            G.arcs[k][i]=G.arcs[i][k]=min(G.arcs[i][k],G.arcs[i][j]+G.arcs[j][k]);
                    }
                        
                }
            }
        }
    }
//         for(int i=1;i<=G.vexnum;i++){
//         for(int j=1;j<=G.vexnum;j++)printf("%d ",G.arcs[i][j]);
//         printf("\n");
//     }
    int sign=0;//sign==1时，非连通
    for(int i=1;i<=G.vexnum;i++){
        for(int j=1;j<=G.vexnum;j++){
            if(!G.arcs[i][j]){
                sign=1;
                goto here;
            }
        }
    }
    here:
    for(int i=0;i<n;i++){
        double sum=0;
        for(int j=1;j<=G.vexnum;j++){
            sum+=G.arcs[num[i]][j];
        }
        sum=(G.vexnum-1)/(sum-G.arcs[num[i]][num[i]]);
        if(sign)sum=0;
        printf("Cc(%d)=%.2lf\n",num[i],sum);
    }
}
