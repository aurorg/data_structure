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
    preOrder(root,1);
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