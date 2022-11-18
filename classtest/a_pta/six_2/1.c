// 6-1 二叉树中求度为2的结点的个数
// 分数 14
// 作者 曾艳
// 单位 西安邮电大学
// 编写算法，在以二叉链表存储的二叉树中，求度为2的结点的个数。

// 函数接口定义：
// int Degree2(BiTree  bt);
// 其中bt为二叉树的根指针，其类型定义如下：

// typedef char DataType;
// typedef struct Node
// {
//     DataType data;
//     struct Node * Lchild;
//     struct Node * Rchild;
// }BiTNode,*BiTree;
// 函数返回度为2的结点的个数。

// ABD^G^^^CE^H^^F^^
// 输出样例：
// 2


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
int Degree2(BiTree  bt);
main()
{
    BiTree root;
    root=CreatBiTree();
    printf("%d\n",Degree2(root));
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
 int c=0;
int Degree2(BiTree bt){
    
    if(bt==NULL){
        return 0;
    }
    if(bt){
        if(bt->Lchild && bt->Rchild){
            c++;
        }
        Degree2(bt->Lchild);
        Degree2(bt->Rchild);
    }
    return c;
}