#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
#define M 2*N-1

typedef struct node{
    int weight;
    int parent,leftChild,rightChild;
    char data;
}HTNode,HuffmanTree[M+1];

typedef char *HuffmanCode[N+1];

void select(HuffmanTree ht,int n,int *s1,int *s2){
    int temp;
    for(int i=1;i<=n;i++){
        if(ht[i].parent==0){
            temp=i;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        if(ht[i].parent==0){
            if(ht[i].weight<ht[temp].weight)
            temp=i;
        }
    }
    *s1=temp;
    for(int i=1;i<=n;i++){
        if(ht[i].parent==0 && i!=*s1){
            temp=i;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        if(ht[i].parent==0 && i!=*s1){
            if(ht[i].weight<ht[temp].weight)
            temp=i;
        }
    }
    *s2=temp;
}
void CrtHuffmanTree(HuffmanTree ht,int w[],int n){
 
}

