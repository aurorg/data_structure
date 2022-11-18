// 6-4 求树（或森林）的叶子结点数
// 分数 15
// 作者 曾艳
// 单位 西安邮电大学
// 编写算法，在以孩子兄弟二叉链表存储的树（或森林）中，求树（或森林）的叶子结点数。

// 函数接口定义：
// int NumOfLeaf(CSTree  rt);
// 其中，rt为根指针。类型定义如下：

// typedef char DataType;

// typedef struct CSNode
// {
//     DataType data;
//     struct CSNode * FirstChild;
//     struct CSNode * NextSibling;
// }CSNode,*CSTree;
// 返回叶子结点数。

// 输入样例：
// ABE^F^^C^DGJ^^H^I^^^^
// 输出样例：
// 6


#include<stdio.h>
#include<stdlib.h>
typedef char DataType;

typedef struct CSNode
{
    DataType data;
    struct CSNode * FirstChild;
    struct CSNode * NextSibling;
}CSNode,*CSTree;

CSTree CreatCSTree(); //以对应二叉树的扩展先序遍历序列创建树
int NumOfLeaf(CSTree  rt);

main()
{
    CSTree root;
    root=CreatCSTree();
    printf("%d\n",NumOfLeaf(root));
}

CSTree CreatCSTree()//以对应二叉树的扩展先序遍历序列创建树 
{
    CSTree root;
    char ch;
    ch=getchar();
    if(ch=='^')
        return NULL;
    root=(CSTree )malloc(sizeof(CSNode));
    root->data=ch;
    root->FirstChild = CreatCSTree();
    root->NextSibling = CreatCSTree();
    return root;
}


/* 请在这里填写答案 */
int NumOfLeaf(CSTree  rt) {

    if(!rt)
        return 0;

    if(!rt->FirstChild) 
        return NumOfLeaf(rt->NextSibling)+1;

    else 
        return NumOfLeaf(rt->FirstChild)+NumOfLeaf(rt->NextSibling);

}