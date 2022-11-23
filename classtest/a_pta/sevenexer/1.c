// /**
//  * 邻接矩阵与邻接表之间的转换
//  * ①邻接表转邻接矩阵
//  * ②邻接矩阵转邻接表
//  *
//  * ①算法思想
//  *
//  * ②算法设计
//  */
 
// #include <stdio.h>
// #define MaxSize 20
// #define INF 999999
 
// //邻接表
// struct ArcNode{
//     int adjvex;//顶点的下标
//     struct ArcNode *next;
//     int weight;
// };
// struct VNode{
//     char value;//顶点的数据
//     struct ArcNode *first;
// };
// struct AdGraph{
//     VNode vertices[MaxSize];
//     int vexnum,arcnum;
// };
// //邻接矩阵（有向图、无向图）
// struct MGraph{
//     char Vex[MaxSize];//顶点的数据
//     int Edge[MaxSize][MaxSize];
//     int VexNum,ArcNum;
// };
// //带权图（网）
// struct MGraphW{
//     char Vex[MaxSize];//保存每个节点的权值，很多时候是用string
//     int Weight[MaxSize][MaxSize];//保存边上权值
//     int VexNum,ArcNum;//储存顶点个数和边的个数
// };
 
// //①邻接表 -> 邻接矩阵
// MGraph AdToM(AdGraph G){
//     MGraph g;//如果是带权图：MGraphW g;
//     g.VexNum = G.vexnum;
//     g.ArcNum = G.arcnum;
//     //初始化一下
//     for (int i = 0; i < g.VexNum; ++i) {
//         for (int j = 0; j < g.VexNum; ++j) {
//             g.Edge[i][j] = 0;
//         }
//     }
//     ArcNode *p;
//     for (int i = 0; i < G.vexnum; ++i) {
//         g.Vex[i] = G.vertices[i].value;
//         p = G.vertices[i].first;
//         while(p){
//             g.Edge[i][p -> adjvex] = 1;
//             //如果是带权图：g.Weight[i][p -> adjvex] = p -> weight;
//             p = p -> next;
//         }
//     }
//     return g;
// }
 
// //②邻接矩阵 -> 邻接表
// AdGraph MToAd(MGraph G){
//     AdGraph g;
//     g.vexnum = G.VexNum;
//     g.arcnum = G.ArcNum;
//     ArcNode *p,*q;
//     for (int i = 0; i < G.VexNum; ++i) {
//         g.vertices[i].value = G.Vex[i];
//         g.vertices[i].first = NULL;
//         for (int j = 0; j < G.VexNum; ++j) {
//             if(G.Edge[i][j] == 1){
//                 q = (ArcNode*)malloc(sizeof(ArcNode));
//                 q -> adjvex = j;
//                 //如果是带权图：q -> weight = G.Weight[i][j];
//                 if(g.vertices[i].first == NULL){
//                     g.vertices[i].first = q;
//                     p = q;
//                 }else{
//                     p -> next = q;
//                     p = q;
//                 }
//             }
//         }
//         p -> next = NULL;
//     }
//     return g;
// }