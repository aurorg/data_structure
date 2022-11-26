// 6-3 有向图邻接矩阵中判断有向路径
// 分数 6
// 作者 曾艳
// 单位 西安邮电大学
// 已知有向图采用邻接矩阵作为存储结构，编写算法判断两个指定顶点之间是否存在路径。

// 输入说明：
// 第一行，输入顶点总数n

// 第二行，连续输入n个字符，无间隔，依次为各个顶点的信息

// 第三行，输入弧总数e

// 第四行，连续输入e条弧，例如：<A,B>

// 第五行，待判断路径的总数x

// 第六行，连续输入x条待判断的路径，例如：[A,B]

// 输出说明：
// 依次输出每个路径的判断结果，参考样例。

// 函数接口定义：
// int Path_AdjMatirx(AdjMatrix *G,Vextype v1,Vextype v2);
// G为指向图邻接矩阵的指针。
// v1,v2为待判断的路径的起终点。若存在该路径，则返回1，否则返回0。

// 其中类型定义如下：

// #define MAXVEX 20
// typedef char Vextype;
// typedef struct
// {
//     int arcs[MAXVEX+1][MAXVEX+1];
//     Vextype vex[MAXVEX+1];
//     int vexnum;
//     int arcnum;
// }AdjMatrix;
// 裁判测试程序样例：
// #include<stdio.h> 

// void Creat_AdjMatrix(AdjMatrix *G);
// int LocateVex_AdjMatrix(AdjMatrix *G,Vextype v);
// int Path_AdjMatirx(AdjMatrix *G,Vextype v1,Vextype v2);

// main()
// {
//     int n,i;
//     Vextype a,b;
//     AdjMatrix gM;
//     Creat_AdjMatrix(&gM);
//     scanf("%d\n",&n);
//     for(i=0;i<n;i++)
//     {
//         scanf("[%c,%c]",&a,&b);
//         if(Path_AdjMatirx(&gM,a,b)==1)
//             printf("From %c to %c: YES.\n",a,b);
//         else
//             printf("From %c to %c: NO.\n",a,b);
//     }
// }

// void Creat_AdjMatrix(AdjMatrix *G)
// {
//     int i,j,k;
//     char v1,v2;
//     scanf("%d\n",&(G->vexnum));
//     for(i=1;i<=G->vexnum;i++)
//     { 
//         scanf("%c",&(G->vex[i]));
//         for(j=1;j<=G->vexnum;j++)
//             G->arcs[i][j]=0;
//     }
//     scanf("%d\n",&(G->arcnum));
//     for(k=1;k<=G->arcnum;k++)
//     {
//         scanf("<%c,%c>",&v1,&v2);
//         i=LocateVex_AdjMatrix(G,v1);
//         j=LocateVex_AdjMatrix(G,v2);
//         G->arcs[i][j]=1; 
//     }
// }

// int LocateVex_AdjMatrix(AdjMatrix *G,Vextype v)
// {
//     int i;
//     for(i=1;i<=G->vexnum;i++)
//         if(G->vex[i]==v) 
//             return i;
//     return 0;
// }

// /* 请在这里填写答案 */
// 输入样例：
// 在这里给出一组输入。例如：

// 5
// abcde
// 7
// <a,b><b,d><d,c><a,c><b,c><b,e><e,d>
// 3
// [b,a][a,e][d,b]
// 输出样例：
// 在这里给出相应的输出。例如：

// From b to a: NO.
// From a to e: YES.
// From d to b: NO.

#include<stdio.h> 
#define MAXVEX 20
typedef char Vextype;
typedef struct
{
    int arcs[MAXVEX+1][MAXVEX+1];
    Vextype vex[MAXVEX+1];
    int vexnum;
    int arcnum;
}AdjMatrix;


void Creat_AdjMatrix(AdjMatrix *G);
int LocateVex_AdjMatrix(AdjMatrix *G,Vextype v);
int Path_AdjMatirx(AdjMatrix *G,Vextype v1,Vextype v2);

main()
{
    int n,i;
    Vextype a,b;
    AdjMatrix gM;
    Creat_AdjMatrix(&gM);
    scanf("%d\n",&n);
    for(i=0;i<n;i++)
    {
        scanf("[%c,%c]",&a,&b);
        if(Path_AdjMatirx(&gM,a,b)==1)
            printf("From %c to %c: YES.\n",a,b);
        else
            printf("From %c to %c: NO.\n",a,b);
    }
}

void Creat_AdjMatrix(AdjMatrix *G)
{
    int i,j,k;
    char v1,v2;
    scanf("%d\n",&(G->vexnum));
    for(i=1;i<=G->vexnum;i++)
    { 
        scanf("%c",&(G->vex[i]));
        for(j=1;j<=G->vexnum;j++)
            G->arcs[i][j]=0;
    }
    scanf("%d\n",&(G->arcnum));
    for(k=1;k<=G->arcnum;k++)
    {
        scanf("<%c,%c>",&v1,&v2);
        i=LocateVex_AdjMatrix(G,v1);
        j=LocateVex_AdjMatrix(G,v2);
        G->arcs[i][j]=1; 
    }
}

int LocateVex_AdjMatrix(AdjMatrix *G,Vextype v)
{
    int i;
    for(i=1;i<=G->vexnum;i++)
        if(G->vex[i]==v) 
            return i;
    return 0;
}

/* 请在这里填写答案 */
int Path_AdjMatirx(AdjMatrix *G,Vextype v1,Vextype v2){
    int n1=0,n2=0;
    for(int i=1;i<=G->vexnum;i++){
        if(G->vex[i]==v1)n1=i;
        if(G->vex[i]==v2)n2=i;
        for(int j=1;j<=G->vexnum;j++){
            if(G->arcs[i][j]){
                for(int k=1;k<=G->vexnum;k++){
                    if(G->arcs[j][k])G->arcs[i][k]=1;
                }
            }
        }
    }
    return G->arcs[n1][n2];
}