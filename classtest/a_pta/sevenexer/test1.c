#include <stdio.h>

#define MaxInt 32767 //表示极大值，无穷大
#define MVNum 100  //最大顶点数
typedef char VerTexType; //设顶点的数据类型为字符型
typedef int ArcType; //假设边的权值类型是整形

typedef struct{
    VerTexType vexs[MVNum];  //顶点表
    ArcType arcs[MVNum][MVNum];//邻接矩阵
    int vexnum,arcnum; //图的当前点数和边数
}AMGraph;

//采用邻接矩阵表示法创建无向网
/*1.输入总的定点数和总的边数
  2.依次输入点的信息存入顶点表中
  3.初始化邻接矩阵，使每个权值初始化为极大值
  4.构造邻接矩阵
*/
 

