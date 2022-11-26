#include <stdio.h>
#include <stdlib.h>

//邻接矩阵
#define MAXVEX 20  //最大顶点个数
typedef char Vextype;  //顶点类型
typedef struct{
    int arcs[MAXVEX+1][MAXVEX+1];//边的信息
    Vextype vex[MAXVEX+1];//顶点信息，顶点类型前面定义了
    int vexnum; //顶点数目
    int arcnum; //边的数目
}AdjMatrix;//邻接矩阵

//图的边结构
//对图中的每个顶点建立一条单链表，
//表中存放与该顶点邻接的所有顶点，相当于邻接矩阵中的所有非零元素
typedef struct ArcNode{
    int adjvex; //边的信息
    struct ArcNode *next; 
}ArcNode;

//图的顶点结构
//存放图中每个顶点的信息以及指向该顶点边表的头指针
typedef struct{
    Vextype vexdata;//顶点的信息
    ArcNode *head; //头指针
}VertexNode;

//all
typedef struct{
    VertexNode vertex[MAXVEX];
    int vexnum;//顶点数
    int arcnum;//弧数
}AdjList;



