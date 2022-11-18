// 6-5 求树（或森林）的高度
// 分数 15
// 作者 曾艳
// 单位 西安邮电大学
// 编写算法，在以孩子兄弟二叉链表存储的树（或森林）中，求树（或森林）的高度。

// 函数接口定义：
// int GetHeight (CSTree rt);
// 其中，rt为根指针。类型定义如下：

// typedef char DataType;

// typedef struct CSNode
// {
//     DataType data;
//     struct CSNode * FirstChild;
//     struct CSNode * NextSibling;
// }CSNode,*CSTree;
// 返回树（或森林）的高度。

// 输入样例：
// ABE^F^^C^DGJ^^H^I^^^^
// 输出样例：
// 4

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
int GetHeight (CSTree rt);

main()
{
    CSTree root;
    root=CreatCSTree();
    printf("%d\n",GetHeight(root));
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
int GetHeight (CSTree rt) {

    int l,r;

    if(rt) {

        l=GetHeight(rt->FirstChild)+1;

        r=GetHeight(rt->NextSibling);

        return l>r?l:r;

    }

    else
        return 0;

}
