#include <stdio.h>

#include <stdlib.h>

#define MAX 0

typedef struct GRAPHMATRIX_STRU

{

    int size;

    int **graph;

}GraphMatrix;



GraphMatrix* InitGraph(int num)

{

    int i,j;

    GraphMatrix *graphMatrix=(GraphMatrix*)malloc(sizeof(GraphMatrix));

    graphMatrix->size=num;

    graphMatrix->graph=(int**)malloc(sizeof(int*)*graphMatrix->size);

    for(i=0;i<graphMatrix->size;i++)

        graphMatrix->graph[i]=(int*)malloc(sizeof(int)*graphMatrix->size);

    for(i=0;i<graphMatrix->size;i++)

    {

        for(j=0;j<graphMatrix->size;j++)

        graphMatrix->graph[i][j]=MAX;



    }

    return graphMatrix;

}

void ReadMatrix(GraphMatrix*graphMatrix)

{

    int vex1,vex2;

    scanf("%d%d",&vex1,&vex2);

    while(vex1!=0||vex2!=0)

    {

        graphMatrix->graph[vex1][vex2]=1;

        scanf("%d%d",&vex1,&vex2);

    }



}

void IsOrNot(GraphMatrix *graphMatrix,int *visited,int source)

{

    int j;

    visited[source]=1;//若i节点被访问到，visited[i]=1

    for(j=0;j<graphMatrix->size;j++)

    {

        if(graphMatrix->graph[source][j]!=MAX&&!visited[j])

            IsOrNot(graphMatrix,visited,j);

    }

}



/*void DFS(GraphMatrix*graphMatrix,int* visited,int source)

{

    int j;

    visited[source]=1;

    printf("%d",source)

    for(j=0;j<graphMatrix;j++)

    {

        if(graphMatrix->graph[soure][j]!=MAX&&!visited[j])

            DFS(graphMatrix,visited,j);

    }

}*/

int main()

{

    int num=7;//节点个数可以自己定义，可以改为输入的方式

    int *visited=(int*)malloc(sizeof(int)*num);

   int head,tail;

   GraphMatrix *graphMatrix;

   graphMatrix=InitGraph(num);

   ReadMatrix(graphMatrix);

   scanf("%d%d",&head,&tail);//判断head节点和tail节点是否来连通

   IsOrNot(graphMatrix,visited,head);

   if(visited[tail]==1)//若head节点和tail节点连通，则输出1，否则输出0；

    printf("1");

   else

    printf("0");

   return 0;

}
