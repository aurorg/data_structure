#include <stdio.h>


#define MVNum 100  //最大顶点数
typedef char VerTexType; //设顶点的数据类型为字符型
typedef int ArcType; //假设边的权值类型是整形

typedef struct{
    VerTexType vexs[MVNum];  //顶点表
    ArcType arcs[MVNum][MVNum];//邻接矩阵
    int vexnum,arcnum; //图的当前点数和边数
}AMGraph;