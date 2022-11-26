// 6-1 有向图邻接矩阵转换为邻接表
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
// 依照顶点顺序输出各个顶点的邻接表，每个顶点一行。

// 每行先输出顶点序号，顶点信息，然后依次输出各个邻接点的编号（注意：各邻接点按顶点序号升序排列），详见输出样例。

// 函数接口定义：
// void AdjMatrixToAdjList(AdjMatrix *M,AdjList *L);//邻接矩阵转换为邻接表

// 参数M为指向接矩阵转换的指针，参数L为指向转换所得的邻接表的指针。
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


// void Creat_AdjMatrix(AdjMatrix *G);  //创建邻接矩阵
// int LocateVex_AdjMatrix(AdjMatrix *G,Vextype v);  

// void Print_AdjList(AdjList *G);  //输出邻接表

// void AdjMatrixToAdjList(AdjMatrix *M,AdjList *L);  //邻接矩阵转换为邻接表

// main()
// {
//     AdjMatrix gM;
//     AdjList gL;
//     Creat_AdjMatrix(&gM);
//     AdjMatrixToAdjList(&gM,&gL);
//     Print_AdjList(&gL);
// }

// void Creat_AdjMatrix(AdjMatrix *G)//创建邻接矩阵
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

// int LocateVex_AdjMatrix(AdjMatrix *G,Vextype v)//输出邻接表
// {
//     int i;
//     for(i=1;i<=G->vexnum;i++)
//         if(G->vex[i]==v) 
//             return i;
//     return 0;
// }


// void Print_AdjList(AdjList *G)
// {
//     int i;
//     ArcNode *p;
//     for(i=1;i<=G->vexnum;i++)
//     { 
//         printf("%d:(%c)",i,G->vertex[i].vexdata);
//         for(p=G->vertex[i].head;p;p=p->next)
//         {
//             printf("->%d",p->adjvex);
//         }
//         printf("\n");
//     }
// }

// /* 请在这里填写答案 */
// 输入样例：
// 5
// abcde
// 7
// <a,b><b,c><c,d><d,a><d,b><a,e><e,c>
// 输出样例：
// 1:(a)->2->5
// 2:(b)->3
// 3:(c)->4
// 4:(d)->1->2
// 5:(e)->3
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



void Creat_AdjMatrix(AdjMatrix *G);  //创建邻接矩阵
int LocateVex_AdjMatrix(AdjMatrix *G,Vextype v);  

void Print_AdjList(AdjList *G);  //输出邻接表

void AdjMatrixToAdjList(AdjMatrix *M,AdjList *L);  //邻接矩阵转换为邻接表

main()
{
    AdjMatrix gM;
    AdjList gL;
    Creat_AdjMatrix(&gM);
    AdjMatrixToAdjList(&gM,&gL);
    Print_AdjList(&gL);
}

void Creat_AdjMatrix(AdjMatrix *G)//创建邻接矩阵
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

int LocateVex_AdjMatrix(AdjMatrix *G,Vextype v)//输出邻接表
{
    int i;
    for(i=1;i<=G->vexnum;i++)
        if(G->vex[i]==v) 
            return i;
    return 0;
}


void Print_AdjList(AdjList *G)
{
    int i;
    ArcNode *p;
    for(i=1;i<=G->vexnum;i++)
    { 
        printf("%d:(%c)",i,G->vertex[i].vexdata);
        for(p=G->vertex[i].head;p;p=p->next)
        {
            printf("->%d",p->adjvex);
        }
        printf("\n");
    }
}

/* 请在这里填写答案 */
void AdjMatrixToAdjList(AdjMatrix *M,AdjList *L){
 //先将临界矩阵与邻接链表的顶点数目与边数目置为相等
 L->vexnum=M->vexnum; 
 L->arcnum=M->arcnum;
    
 int i,j;
 ArcNode *p,*s; //建立指向邻接链表的指针s,p;
 for(i=1;i<=L->vexnum;i++){
  L->vertex[i].vexdata=M->vex[i];
  L->vertex[i].head=NULL;
 }
    //建立双重循环判断邻接矩阵中的arce[i][j]中的是否为1（1是图中没有带权值，且其对应的顶点之间有关系）
    //再将矩阵中对应顶点关系的下标值赋值给邻接矩阵中的s所指的下标值。令p=vertex[i].head;
 for(i=1;i<=M->vexnum;i++){
  for(j=1;j<=M->vexnum;j++){
   if(M->arcs[i][j]==1){
    s=(ArcNode*)malloc(sizeof(ArcNode));
    s->adjvex=j;
    s->next=NULL;
    p=L->vertex[i].head;
       
   //判断p是否为空，如果为空的话讲s赋值给p，若不为空将s中的值插到p的后面。  
    if(p==NULL) 
    {
     L->vertex[i].head=s;
    }
    else{
     while(p->next)
      p=p->next;
     s->next=p->next;
     p->next=s;
    }
   }
  }
 }
} 