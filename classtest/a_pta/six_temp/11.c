#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
#define M 2*N-1

typedef struct node{
    int weight;
    int parent,leftChild,rughtChild;
    char data;
}HTNode,HuffmanTree[M+1];

typedef char *HuffmanCode[N+1];
