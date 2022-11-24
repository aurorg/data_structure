#include <stdio.h>
#include <stdlib.h>

typedef char VertexType; //顶点类型自己定义
typedef int EdgeType;    //边上的权值类型自己定义
#define MAXVEX 100       //最大的顶点数
#define INFINITY 65536   //表示无穷大

typedef struct{
    VertexType vexs[MAXVEX];  //顶点表
    EdgeType arc[MAXVEX][MAXVEX]; //邻接矩阵
    int numVertexes,numEdges; //图中当前顶点数和边数
}MGraph; 

//建立无向网图的邻接矩阵表示

void CreateMGraph(MGraph *G){
    int i,j,k,w;
    printf("请输入顶点数和边数：\n");
    scanf("%d,%d",&G->numVertexes,&G->numEdges);
    for(i=0;i<G->numVertexes;i++){ //读入顶点信息，建立顶点表
        scanf(&G->vexs[i]);
    }
    for(i=0;i<G->numVertexes;i++){
        for(j=0;j<G->numVertexes;j++){
            G->arc[i][j]=INFINITY; //邻接矩阵初始化
        }
    }
    for(k=0;k<G->numEdges;k++){  //读入numEdges条边，建立邻接矩阵
        printf("输入边（vi,vj）的下标i,下标j，和权值w");
        scanf("%d,%d,%d",&i,&j,&w);
        G->arc[i][j]=w;
        G->arc[i][j]=G->arc[i][j]; //因为是无向图，所以矩阵是对称的
    }
}
//时间复杂度：n+n*n+e;
