#include <stdio.h>
#include <stdlib.h>

typedef struct Tree_Node{
    char data;
    struct treenode *lchild;
    struct treenode* rchild;
}treenode, *BiTree;

void createBiTree(BiTree *bi_tree);
void printftree(char data);
void preOrder(BiTree root);
void inOrder(BiTree root);
void postOrder(BiTree root);

int main(){
    BiTree bi_tree=NULL;
    createBiTree(&bi_tree);
    preOrder(bi_tree);
    inOrder(bi_tree);
    postoRDER(bi_tree);

    return 0;
}

// void createBiTree(BiTree *bi_tree){
//     char c;
//     c=getchar();
//     if(c=='#'){
//         *bi_tree=NULL;
//     }else{
//         *bi_tree=(BiTree)malloc(sizeof(treenode));
//         (*bi_tree)->data=c;
//         createBiTree(&((*bi_tree)->lchild));
//         createBiTree(&((*bi_tree)->rchild));

//     }
// } 

void createBiTree(BiTree *bi_tree){
    char c;
    c=getchar();
    if(c=='#'){
        *bi_tree=NULL;
    }else{
        *bi_tree=(BiTree)malloc(sizeof(treenode));
        (*bi_tree)->data=c;
        createBiTree(&((*bi_tree)->lchild));
        createBiTree(&((*bi_tree)->rchild));
    }
}

void printftree(char data){
    putchar(data);
}

void preOrder(BiTree root){
    if(root!=NULL){
        printftree(root->data);
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
}

void inOrder(BiTree root){
    if(root!=NULL){
        inOrder(root->lchild);
        printftree(root->data);
        inOrder(root->rchild);
    }
}

void postOrder(BiTree root){
    if(root!=NULL){
        postOrder(root->lchild);
        postOrder(root->rchild);
        printftree(root->data);

    }
}