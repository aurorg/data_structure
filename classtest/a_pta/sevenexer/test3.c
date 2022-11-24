#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char VertexType; //顶点类型自己定义
typedef int EdgeType;   //边上的权值类型自己定义
#define MAXVEX 100

typedef struct EdgeNode{  //边表结点
    int agjvex; //邻接点域，存储该顶点对应的下标
    EdgeType weight; //用于存储权值，对于非网图可以不需要
    struct EdgeNode *next; //链域，指向下一个邻接点
}EdgeNode;

typedef struct VertexNode{  //顶点表结点
    VertexType data;  //顶点域，存储顶点信息
    EdgeNode *firstedge; //边表头指针 
}VertexNode,AdjList[MAXVEX];

typedef struct{
    AdjList adjList;
    int numVertexes,numEdges; //图中当前顶点数和边数
}GraphAdjList;

//建立图的邻接表结构

void CreateALGraph(GraphAdjList *G){
    int i,j,k;
    EdgeNode *e;
    printf("输入顶点数和边数：\n");
    scanf("%d,%d",&G->numVertexes,&G->numEdges); //输入顶点数和边数

//输入顶点信息，建立顶点表
    for(i=0;i<G->numVertexes;i++){     
        scanf(&G->adjList[i].data);   //输入顶点信息
        G->adjList[i].firstedge=NULL; //将边表置为空表
    }

//建立边表
    for(k=0;k<G->numEdges;k++){
        printf("输入边（vi,vj）的顶点序号：\n");
        scanf("%d,%d",&i,&j); 

        e=(EdgeNode *)malloc(sizeof(EdgeNode));  //向内存申请空间，生成边表结点

        e->agjvex=j; //邻接序号为j
        e->next=G->adjList[i].firstedge; //将e指针指向当前顶点指向的顶点
        G->adjList[i].firstedge=e;     //将当前顶点的指针指向e


        e=(EdgeNode *)malloc(sizeof(EdgeNode)); 

        e->agjvex=i;
        e->next=G->adjList[j].firstedge;
        G->adjList[j].firstedge=e;

    }
}
