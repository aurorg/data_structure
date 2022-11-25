// 7-6 二叉树的高度
// 分数 15
// 作者 曾艳
// 单位 西安邮电大学
// 从键盘接收扩展先序序列，以二叉链表作为存储结构，建立二叉树。计算二叉树的高度，并输出。

// 输入格式:
// 输入扩展先序序列。二叉树结点的data是字符类型数据, 其中#表示空格字符。

// 输出格式:
// 输出一个整数。

// 输入样例:
// ABC##DE#G##F###
// 输出样例:
// 5

#include <stdio.h>
#include <stdlib.h>
typedef struct BiTree_Node{
    char data;
    struct BiTree_Node*lchild;
    struct BiTree_Node*rchild;
} *treenode;

treenode createBiTree();
void preOrder(treenode root,int depth);
int max=0;

int main(){
    treenode root;
    root=createBiTree();
    preOrder(root,1); //开始让depth的值为1，从第一层开始
    printf("%d",max);
}
 
treenode createBiTree(){
    treenode root=(treenode)malloc(sizeof(struct BiTree_Node));
    char c;
    scanf("%c",&c);
    if(c !='#'){
        root->data=c;
        root->lchild=createBiTree();
        root->rchild=createBiTree();
    }
    else{
        root=NULL;
    }

    return root;
}

void preOrder(treenode root,int depth){//先序遍历
    if(root==NULL){
        return;
    }
    else if(depth>max){
        max=depth;
    }
    preOrder(root->lchild,depth+1);
    preOrder(root->rchild,depth+1);
}