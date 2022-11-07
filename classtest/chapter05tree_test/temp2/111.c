#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
#define M 2*N-1

typedef struct node{
    int weight;
    int parent,leftChild,rightChild;
    char data;
}HFMNode; HuffmanTree[M+1];

