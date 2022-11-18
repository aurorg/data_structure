// 6-3 二叉树中先序输出各结点及其层次
// 分数 15
// 作者 曾艳
// 单位 西安邮电大学
// 编写算法，在以二叉链表存储的二叉树中，按先序次序输出各结点的内容及相应的层次数，要求以二元组的形式输出。（输出格式参见样例）

// 函数接口定义：
// 在这里描述函数接口。例如：
// void  PreOrderLayer (BiTree bt, int lay);
// 其中，bt为二叉树的根指针，类型定义如下：

// typedef char DataType;
// typedef struct Node
// {
//     DataType data;
//     struct Node * Lchild;
//     struct Node * Rchild;
// }BiTNode,*BiTree;
// lay为bt所在的层次数。
// 无返回值。

// 输入样例：
// AB^DG^^^CE^^FH^^^
// 输出样例：
// (A,1)(B,2)(D,3)(G,4)(C,2)(E,3)(F,3)(H,4)

#include<stdio.h>
#include<stdlib.h>
typedef char DataType;

typedef struct Node
{
    DataType data;
    struct Node * Lchild;
    struct Node * Rchild;
}BiTNode,*BiTree;

BiTree CreatBiTree();//用扩展先序遍历序列创建二叉链表
void  PreOrderLayer (BiTree bt, int lay);
main()
{
    BiTree root;
    root=CreatBiTree();
    PreOrderLayer(root,1);
}

BiTree CreatBiTree()//用扩展先序遍历序列创建二叉链表
{
    BiTree bt;
    char ch;
    ch=getchar();
    if(ch=='^')
        return NULL;
    bt=(BiTree )malloc(sizeof(BiTNode));
    bt->data=ch;
    bt->Lchild = CreatBiTree();
    bt->Rchild = CreatBiTree();
    return bt;
}


/* 请在这里填写答案 */
 void  PreOrderLayer (BiTree bt, int lay){
     if(bt){
         printf("(%c,%d)",bt->data,lay);
         PreOrderLayer(bt->Lchild,lay+1);
         PreOrderLayer(bt->Rchild,lay+1);
     }
 }
