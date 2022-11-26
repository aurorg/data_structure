// 7-6 城市建设
// 分数 20
// 作者 王燕
// 单位 西安邮电大学
//    栋栋居住在一个繁华的C市中，然而，这个城市的道路大都年久失修。市长准备重新修一些路以方便市民，于是找到了栋栋，希望栋栋能帮助他。
// 　　C市中有n个比较重要的地点，市长希望这些地点重点被考虑。现在可以修一些道路来连接其中的一些地点，每条道路可以连接其中的两个地点。另外由于C市有一条河从中穿过，也可以在其中的一些地点建设码头，所有建了码头的地点可以通过河道连接。
// 　　栋栋拿到了允许建设的道路的信息，包括每条可以建设的道路的花费，以及哪些地点可以建设码头和建设码头的花费。
// 　　市长希望栋栋给出一个方案，使得任意两个地点能只通过新修的路或者河道互达，同时花费尽量小。

// 输入格式:
// 　　输入的第一行包含两个整数n, m，分别表示C市中重要地点的个数和可以建设的道路条数。所有地点从1到n依次编号。
// 　　接下来m行，每行三个整数a, b, c，表示可以建设一条从地点a到地点b的道路，花费为c。若c为正，表示建设是花钱的，如果c为负，则表示建设了道路后还可以赚钱（比如建设收费道路）。
// 　　接下来一行，包含n个整数w_1, w_2, …, w_n。如果w_i为正数，则表示在地点i建设码头的花费，如果w_i为-1，则表示地点i无法建设码头。
// 　　输入保证至少存在一个方法使得任意两个地点能只通过新修的路或者河道互达。

// 输出格式:
//    输出一行，包含一个整数，表示使得所有地点通过新修道路或者码头连接的最小花费。如果满足条件的情况下还能赚钱，那么你应该输出一个负数。
// 输入样例:
// 在这里给出一组输入。例如：

// 5 5
// 1 2 4
// 1 3 -1
// 2 3 3
// 2 4 5
// 4 5 10
// -1 10 10 1 1
// 输出样例:
// 在这里给出相应的输出。例如：

// 9
 
 #include <stdio.h>
#include <stdlib.h>

#define MAXN 10001
#define MAXM 100001//1<=m<=100000。

int n,m;
int parent[MAXN];

typedef struct{
 int u,v;
 int w;
}Road,*road;

Road a[MAXM+MAXN];

int cmp(const void *a,const void *b)
{
 road pa=(road)a;
 road pb=(road)b;
 int num1=pa->w;
 int num2=pb->w;
 return num1-num2;
}

/*并查集初始化操作*/
void init()
{
 int i;
 for(i=0;i<=n;i++)
  parent[i]=i;
} 

/*并查集寻找根节点操作*/
int find(int x)
{
 if(x==parent[x])
  return x;
 else
  return parent[x]=find(parent[x]);
}

/*kruskal算法*/
int kruskal(int m)
{
 int sum=0,i;
 for(i=0;i<m;i++)
 {
  int A=find(a[i].u);
  int B=find(a[i].v);
  if(A!=B||a[i].w<0)//能赚钱的边一定要加入。
  {
   parent[A]=B;
   sum+=a[i].w;
  }
 }
 return sum; 
}

int main()
{
 scanf("%d%d",&n,&m);
 
 int i,j,cost;
 for(i=0;i<m;i++)
     scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
 
 j=m;
 for(i=1;i<=n;i++)
 {
  scanf("%d",&cost);
  if(cost!=-1)
  {
  a[j].u=0;
  a[j].v=i;
  a[j++].w=cost; 
  }
 }
 
 init();
 for(i=0;i<m;i++)
 {
  int A=find(a[i].u);
  int B=find(a[i].v);
  if(A!=B)
   parent[A]=B;
 }
 
 for(i=2;i<=n;i++)
 {
  if(find(1)!=find(i))
   break;
 }
 
 int temp1,temp2;
 if(i==n+1)
 {
   init();
   qsort(a,m,sizeof(a[0]),cmp);
   temp1=kruskal(m);
   init();
   qsort(a,j,sizeof(a[0]),cmp);
   temp2=kruskal(j);
   
   if(temp1<temp2)
    printf("%d",temp1);
   else
    printf("%d",temp2); 
 }
 else
 {
  init();
  qsort(a,j,sizeof(a[0]),cmp);
  printf("%d",kruskal(j));
 } 
 return 0;
} 
