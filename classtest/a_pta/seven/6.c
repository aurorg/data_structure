// 7-3 求解连通分量个数
// 分数 20
// 作者 王燕
// 单位 西安邮电大学
// 从键盘接收图的顶点集，关系集，创建无向图。

// 输入格式:
// 第一行依次输入图的顶点个数n，关系个数k，以空格隔开。顶点个数<=20
// 第二行依次输入顶点值，类型为字符。
// 接下去有k行，每行为两个字符 u 和 v，表示节点u 和 v 连通。格式为【uv】,中间不用空格间隔。

// 输出格式:
// 计算连通分量个数并输出。
// 输出一个整数，表示连通分量个数。

// 输入样例:
// 在这里给出一组输入。例如：

// 6 7
// ABCDEF
// AB
// AE
// BC
// CD
// DA
// DB
// EC
// 输出样例:
// 在这里给出相应的输出。例如：

// 2
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
void test(AdjMatrix *G);
int main()
{
    int n,i;
    Vextype a,b;
    AdjMatrix G;
    Creat_AdjMatrix(&G);
    test(&G);
    return 0;
}
void Creat_AdjMatrix(AdjMatrix *G)
{
    int i,j,k;
    char v1,v2;
    scanf("%d %d",&(G->vexnum),&(G->arcnum));
    char s[100];
    scanf("%s",s);
    //printf("%s",s);
    for(i=1;i<=G->vexnum;i++)
    {
        G->vex[i]=s[i-1];
        for(j=1;j<=G->vexnum;j++)
            G->arcs[i][j]=0;
    }
    for(k=1;k<=G->arcnum;k++)
    {
        char s[2];
        if(k==G->vexnum)
        scanf("%s",s);
        else
            scanf("%s",s);
        v1=s[0];
        v2=s[1];
        //printf("\n|%c %c|",v1,v2);
        i=LocateVex_AdjMatrix(G,v1);
        j=LocateVex_AdjMatrix(G,v2);
        G->arcs[i][j]=1;
        G->arcs[j][i]=1;
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
int print[MAXVEX]={1,1},count=1;
void test(AdjMatrix *G){
    int sign=1,add=1;
    while(sign){
        sign=0;
        for(int i=add;i<=G->vexnum;i++){
            for(int j=1;j<=G->vexnum;j++){
                if(G->arcs[i][j]){
                    if(!print[j])print[j]=count;
                    for(int k=1;k<=G->vexnum;k++){
                        if(G->arcs[j][k]&&G->arcs[j][k]==G->arcs[i][j]){
                            G->arcs[i][k]=count;
                            print[k]= count;
                        }
                    }
                }
            }
        }
        add=0;
        for(int i=1;i<=G->vexnum;i++){
            if(!print[i]){
                sign=1;
                add=i;
                print[i]=++count;
                break;
            }
        }
    }
    printf("%d",count);
}
