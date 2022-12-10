// 7-2 实现求最小生成树的克鲁斯卡尔算法(Kruskal) 
// 分数 50
// 作者 曾艳
// 单位 西安邮电大学
// 已知有权无向图G，利用克鲁斯卡尔算法求出该图的最小生成树。

// 输入格式:
// 第一行输入两个正整数n和m（空格间隔）， 分别表示图G的顶点总数和边的总数。
// 第二行连续输入n个字母，分别表示n个顶点的信息。

// 第三行连续输入m条边的信息，每条边的输入格式为(v1,v2,w)，表示一条关联顶点v1和v2的边，其权值为w。

// 输出格式:
// 按边上权值由小到大的顺序依次输出各个边。

// 输出边的时，若该边被选中，则在该边信息之后输出1，否则输出0。

// 例如：

// (v1,v2,w,1) 表示与顶点v1和v2相关联的边，权值为w，被选中。

// (v1,v2,w,0) 表示与顶点v1和v2相关联的边，权值为w，未被选中。

// 输入样例:
// 6 10
// ABCDEF
// (A,B,3)(A,D,4)(A,F,10)(B,C,15)(B,D,1)(B,F,8)(C,D,17)(D,E,6)(D,F,13)(E,F,2)
// 输出样例:
// (B,D,1,1)(E,F,2,1)(A,B,3,1)(A,D,4,0)(D,E,6,1)(B,F,8,0)(A,F,10,0)(D,F,13,0)(B,C,15,1)(C,D,17,0)
#include<stdio.h>
#include<malloc.h>
#define MAX 32767

typedef struct Matrix 
{
 int arcs[20][20];
 int poinum; 
 int edenum; 
 char vex[20];
}Matrix;

typedef struct edge
{
 int begin; 
 int end;
 int weight;
 int isfind;
}Edge;

Edge edge[20];

int Location(Matrix *M,char a) 
{
 for(int i=0;i<M->poinum;i++){
  if(M->vex[i] == a)
   return i;
  
 }
 return 0;
}

int find(int *parent, int v)
{
    while (parent[v] > 0)
    {
        v = parent[v];
    }
    return v;
}


void Sort(Matrix *M,int k)
{
 Edge tmp;
 int i,j;
 for(i=0;i<k-1;i++)
 {
  for(j=i+1;j<k;j++)
  {
   if(edge[i].weight>edge[j].weight)
   {
    tmp = edge[i];
    edge[i] = edge[j];
    edge[j] = tmp;
   }
  }
 }
}


void kruskal(Matrix *M)
{
 int num;
 int parent[100] = {0};
 int i,j,k=0;
 int v1,v2;
 //将邻接矩阵转换为边集数组 
 for(i=0;i<M->poinum-1;i++)
 {
  for(j=i+1;j<M->poinum;j++)
  {
   if(M->arcs[i][j]!=MAX)
   {
    edge[k].begin = i; 
    edge[k].end = j;
    edge[k].weight = M->arcs[i][j];
    edge[k].isfind = 0;
    k++;
   }
  }
 }
 Sort(M,k); 
 
 for(i=0;i<M->edenum;i++)
 {
  v1 = find(parent,edge[i].begin);
  v2 = find(parent,edge[i].end);
  
  if(v1!=v2)
  {
   parent[v1] = v2;
   edge[i].isfind = 1;
   num++;
  }
  printf("(%c,%c,%d,%d)",M->vex[edge[i].begin],
         M->vex[edge[i].end], edge[i].weight, edge[i].isfind);
  if(num==M->poinum-1)return;
 }
}


int main()
{
 int i,j,k,weight;
 Matrix *M = (Matrix*)malloc(sizeof(Matrix));//申请邻接矩阵空间 
 char vex1,vex2;
 scanf("%d%d",&M->poinum,&M->edenum);
 getchar();
 for(i=0;i<M->poinum;i++){
  for(j=0;j<M->poinum;j++){
   M->arcs[i][j] = MAX;
  }
 } 
 for(i=0;i<M->poinum;i++)
 {
  scanf("%c",&M->vex[i]);
 }
 getchar();
 
 for(i=0;i<M->edenum;i++)
 {
  scanf("(%c,%c,%d)",&vex1,&vex2,&weight);
  j = Location(M,vex1);
  k = Location(M,vex2); 
  M->arcs[j][k] = weight;
  M->arcs[k][j] = M->arcs[j][k];
 } 
 
 kruskal(M); 
}



