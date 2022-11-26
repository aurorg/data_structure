#include <stdio.h>
#include <stdlib.h>

typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 100
#define INFINITY 65536

typedef struct {
    VertexType vexs[MAXVEX]; //顶点表
    EdgeType arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
} MGraph;

void CreateMGraph(MGraph *G){
    int i, j, k, w;
    printf("请输入顶点数和边数：\n");
    scanf("%d,%d", &G->numVertexes, &G->numEdges);
    
}