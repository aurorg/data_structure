// 6-2 有向图邻接表转换为邻接矩阵
// 分数 10
// 作者 曾艳
// 单位 西安邮电大学
// 编写算法实现将有向图的邻接矩阵转换为邻接表

// 输入说明：
// 第一行，输入顶点总数n

// 第二行，连续输入n个字符，无间隔，依次为各个顶点的信息

// 第三行，输入弧总数e

// 第四行，连续输入e条弧，例如：<A,B>

// 输出说明：
// 输出邻接矩阵，详见输出样例。

// 函数接口定义：
// void AdjListToAdjMartix(AdjList *L,AdjMatrix *M);//邻接表转换为邻接矩阵

// 参数L为指向邻接表的指针，参数M为指向转换所得的邻接矩阵的指针。
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

// typedef struct ArcNode
// {
//     int adjvex;
//     struct ArcNode *next;
// }ArcNode;
// typedef struct 
// {
//     Vextype vexdata;
//     ArcNode *head;
// }VertexNode;
// typedef struct
// {
//     VertexNode vertex[MAXVEX];
//     int vexnum;
//     int arcnum;
// }AdjList;
// 裁判测试程序样例：
// #include<stdio.h> 
// #include<stdlib.h> 

// void Creat_AdjList(AdjList *G);
// int LocateVex_AdjList(AdjList *G,Vextype v);

// void Print_AdjMatrix(AdjMatrix *G);

// void AdjListToAdjMartix(AdjList *L,AdjMatrix *M);

// main()
// {
//     AdjList gL;
//     AdjMatrix gM;
//     Creat_AdjList(&gL);
//     AdjListToAdjMartix(&gL,&gM);
//     Print_AdjMatrix(&gM);
// }

// void Creat_AdjList(AdjList *G)
// {
//     int i,j,k;
//     char v1,v2;
//     scanf("%d\n",&(G->vexnum));
//     for(i=1;i<=G->vexnum;i++)
//     { 
//         scanf("%c",&(G->vertex[i].vexdata));
//         G->vertex[i].head=NULL;
//     }
//     scanf("%d\n",&(G->arcnum));
//     for(k=1;k<=G->arcnum;k++)
//     {
//         ArcNode *p;
//         scanf("<%c,%c>",&v1,&v2);
//         i=LocateVex_AdjList(G,v1);
//         j=LocateVex_AdjList(G,v2);
//         p=(ArcNode *)malloc(sizeof(ArcNode));
//         p->adjvex=j;
//         p->next=G->vertex[i].head;
//         G->vertex[i].head=p;
//     }
// }

// int LocateVex_AdjList(AdjList *G,Vextype v)
// {
//     int i;
//     for(i=1;i<=G->vexnum;i++)
//         if(G->vertex[i].vexdata==v) 
//             return i;
//     return 0;
// }

// void Print_AdjMatrix(AdjMatrix *G)
// {
//     int i,j;
//     printf("  ");
//     for(i=1;i<=G->vexnum;i++)
//         printf("%c ",G->vex[i]);
//     printf("\n");
//     for(i=1;i<=G->vexnum;i++)
//     { 
//         printf("%c ",G->vex[i]);
//         for(j=1;j<=G->vexnum;j++)
//         {
//             printf("%d ",G->arcs[i][j]);
//         }
//         printf("\n");
//     }
// }

// /* 请在这里填写答案 */
// 输入样例：
// 在这里给出一组输入。例如：

// 4
// ABCD
// 5
// <A,B><A,C><B,C><B,D><C,D>
// 输出样例：
// 在这里给出相应的输出。例如：

//   A B C D 
// A 0 1 1 0 
// B 0 0 1 1 
// C 0 0 0 1 
// D 0 0 0 0 

#include<stdio.h> 
#include<stdlib.h> 

#define MAXVEX 20
typedef char Vextype;
typedef struct
{
    int arcs[MAXVEX+1][MAXVEX+1];
    Vextype vex[MAXVEX+1];
    int vexnum;
    int arcnum;
}AdjMatrix;

typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *next;
}ArcNode;
typedef struct 
{
    Vextype vexdata;
    ArcNode *head;
}VertexNode;
typedef struct
{
    VertexNode vertex[MAXVEX];
    int vexnum;
    int arcnum;
}AdjList;


void Creat_AdjList(AdjList *G);
int LocateVex_AdjList(AdjList *G,Vextype v);

void Print_AdjMatrix(AdjMatrix *G);

void AdjListToAdjMartix(AdjList *L,AdjMatrix *M);

main()
{
    AdjList gL;
    AdjMatrix gM;
    Creat_AdjList(&gL);
    AdjListToAdjMartix(&gL,&gM);
    Print_AdjMatrix(&gM);
}

void Creat_AdjList(AdjList *G)
{
    int i,j,k;
    char v1,v2;
    scanf("%d\n",&(G->vexnum));
    for(i=1;i<=G->vexnum;i++)
    { 
        scanf("%c",&(G->vertex[i].vexdata));
        G->vertex[i].head=NULL;
    }
    scanf("%d\n",&(G->arcnum));
    for(k=1;k<=G->arcnum;k++)
    {
        ArcNode *p;
        scanf("<%c,%c>",&v1,&v2);
        i=LocateVex_AdjList(G,v1);
        j=LocateVex_AdjList(G,v2);
        p=(ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex=j;
        p->next=G->vertex[i].head;
        G->vertex[i].head=p;
    }
}

int LocateVex_AdjList(AdjList *G,Vextype v)
{
    int i;
    for(i=1;i<=G->vexnum;i++)
        if(G->vertex[i].vexdata==v) 
            return i;
    return 0;
}

void Print_AdjMatrix(AdjMatrix *G)
{
    int i,j;
    printf("  ");
    for(i=1;i<=G->vexnum;i++)
        printf("%c ",G->vex[i]);
    printf("\n");
    for(i=1;i<=G->vexnum;i++)
    { 
        printf("%c ",G->vex[i]);
        for(j=1;j<=G->vexnum;j++)
        {
            printf("%d ",G->arcs[i][j]);
        }
        printf("\n");
    }
}

/* 请在这里填写答案 */
void AdjListToAdjMartix(AdjList *L,AdjMatrix *M){
    M->vexnum=L->vexnum;
    M->arcnum=L->arcnum;
    
    for(int i=1;i<=L->vexnum;i++){
        M->vex[i]=L->vertex[i].vexdata;
    }
    
    for(int i=1;i<=L->vexnum;i++){
        for(int j=1;j<=L->vexnum;j++){
            M->arcs[i][j]=0;
        }
    }
    
    for(int i=1;i<=L->vexnum;i++){
        ArcNode *p=L->vertex[i].head;
        for(int j=1;j<=L->vexnum;j++){
            
            if(p){
                M->arcs[i][p->adjvex]=1;
                p=p->next;
            }else{
                break;
            }
        }
    }
    
}