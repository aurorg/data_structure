#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 100

typedef struct EdgeNode{
    int agjvex;
    EdgeType weight;
    struct EdgeNode *next;
} EdgeNode;

typedef struct VertexNode{
    VertexType data;
    EdgeNode *firstedge;
} VertexNode, AdjList[MAXVEX];

typedef struct{
    AdjList adjList;
    int numVertexes, numEdges;
} GraphAdjList;

void CreateALGraph(GraphAdjList *G){
    int i, j, k;
    EdgeNode *e;
    printf("输入顶点数和边数：\n");
    scanf("%d,%d", &G->numVertexes, &G->numEdges);

    for (i = 0; i < G->numVertexes;i++){
        scanf(&G->adjList[i].data);
        G->adjList[i].firstedge = NULL;
    }

    for (k = 0; k < G->numEdges;k++){
        printf("输入边（vi,vj）的序号顶点：\n");
        scanf("%d,%d", &i, &j);
        e = (EdgeNode *)malloc(sizeof(EdgeNode));

        e->agjvex = j;
        e->next = G->adjList[i].firstedge;
        G->adjList[i].firstedge = e;

        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->agjvex = j;
        e->next = G->adjList[i].firstedge;
        G->adjList[i].firstedge = e;
    }
}