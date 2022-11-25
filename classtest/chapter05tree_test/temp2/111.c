#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
#define M 2*N-1

typedef struct node{
    int weight;
    int parent,leftChild,rightChild;
    char data;
}HFMNode, HuffmanTree[M+1];

//编码的结构
typedef char *HuffmanCode[N+1];

//
void select(HuffmanTree hfm,int n,int *s1,int *s2){
    int temp;
    for(int i=1;i<=n;i++){
        if(hfm[i].parent==0){
            temp=i;
            break;
        }
    }

    for(int i=1;i<=n;i++){
        if(hfm[i].parent==0){
            temp=i;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        if(hfm[i].parent==0 && i!= *s1){
            temp =i;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        if(hfm[i].parent==0 && i!= *s1){
            if(hfm[i].weight <hfm[temp].weight){
                temp=i;
            }
        }
        *s2=temp;
    }
}

