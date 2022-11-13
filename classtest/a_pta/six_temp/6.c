#include <stdio.h>
#include <stdlib.h>

typedef struct BiTree_Node{
    char data;
    struct BiTree_Node *lchild;
    struct BiTree_Node*rchild;
}*treenode;

treenode createBiTree();
void preOrder(treenode root,int depth);
