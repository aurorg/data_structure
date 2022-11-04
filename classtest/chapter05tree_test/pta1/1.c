#include <stdio.h>
#include<stdlib.h>

typedef struct Tree_Node{
    char data;
    struct treenode* lchild;
    struct treenode* rchild;
}treenode,* BiTree;

void createBiTree(BiTree *bi_tree);//创建二叉树
void printftree(char data);//打印结点
void preOrder(BiTree root);//先序遍历
void inOrder(BiTree root);//中序遍历
void postOrder(BiTree root);//后序遍历

int main(){
    BiTree bi_tree=NULL;
    createBiTree(&bi_tree);
    preOrder(bi_tree);
    printf("\n");
    inOrder(bi_tree);
    printf("\n");
    postOrder(bi_tree);

    return 0;
}

void createBiTree(BiTree *bi_tree){
    char c;
    c=getchar();
    if(c=='#'){
        *bi_tree=NULL;
    }
    else{
        *bi_tree=(BiTree)malloc(sizeof(treenode));
        (*bi_tree)->data=c;//数据
        createBiTree(&((*bi_tree)->lchild));
        createBiTree(&((*bi_tree)->rchild));
    }
}

void printftree(char data){
    putchar(data);
}

void preOrder(BiTree root){ //先序遍历，根左右
    if(root!=NULL){
        printftree(root->data);
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
}

void inOrder(BiTree root){ //中序遍历，左根右
    if(root!=NULL){
        inOrder(root->lchild);
        printftree(root->data);
        inOrder(root->rchild);
    }
}

void postOrder(BiTree root){ //后序遍历，左右根

    if(root!=NULL){
        postOrder(root->lchild);
        postOrder(root->rchild);
        printftree(root->data);
    }
}