// 6-2 交换二叉树的左右子树
// 分数 15
// 作者 曾艳
// 单位 西安邮电大学
// 编写算法，在以二叉链表存储的二叉树中，交换二叉树各结点的左右子树。

// 函数接口定义：
// void SwapLR(BiTree bt)；
// 其中，bt为二叉树的根指针，类型定义如下：

// typedef char DataType;
// typedef struct Node
// {
//     DataType data;
//     struct Node * Lchild;
//     struct Node * Rchild;
// }BiTNode,*BiTree;
// 无返回值。

// 输入样例：
// 在这里给出一组输入。例如：

// ABD^G^^^CE^H^^F^^
// 输出样例：
// 在这里给出相应的输出。例如：

//     D
//       G
//   B
// A
//     E
//       H
//   C
//     F

#include<stdio.h>
#include<stdlib.h>
typedef char DataType;
typedef struct Node
{
    DataType data;
    struct Node * Lchild;
    struct Node * Rchild;
}BiTNode,*BiTree;

BiTree CreatBiTree(); //用扩展先序遍历序列创建二叉链表
void SwapLR(BiTree bt);
void PrintTree(BiTree bt,int h); //按树状打印二叉树（课本P168算法6-16

main()
{
    BiTree root;
    root=CreatBiTree();
    SwapLR(root);
    PrintTree(root,0);
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

void PrintTree(BiTree bt,int h)
{
    if(bt == NULL)
        return ;
    PrintTree(bt->Rchild,h+1);
    for(int i=0;i<h;i++)
        printf("  ");
    printf("%c\n",bt->data);
    PrintTree(bt->Lchild,h+1);
}

/* 请在这里填写答案 */
void SwapLR(BiTree bt){
    if(bt){
        BiTree temp=bt->Lchild;
        bt->Lchild=bt->Rchild;
        bt->Rchild=temp;
        SwapLR(bt->Lchild);
        SwapLR(bt->Rchild);
    }
    
}
