#include <stdio.h>'
#include <stdlib.h>
#include <string.h>
#define N 100
#define M 2*N-1

typedef struct node{
    int weight;
    int parent,leftChild,rightChild;
    char data;
}HTNode,HuffmanTree[M+1];

typedef char* HuffmanCode[N+1];

void select(HuffmanTree ht,int n,int *s1,int *s2){
    int temp;
    for(int i=1;i<=n;i++){
        if(ht[i].parent==0){
            temp=i;
            break;
        }
    }

    for(int i=1;i<=n;i++){
        if(ht[i].parent ==0){
            if(ht[i].weight<ht[temp].weight){
                temp=i;
            }
        }
    }

    *s1=temp;
    for(int i=1;i<=n;i++){
        if(ht[i].parent==0 && i!= *s1){
            temp=i;
            break;
        }
    }

    for(int i=1;i<=n;i++){
        if(ht[i].parent==0 && i!=*s1){
            if(ht[i].weight <ht[temp].weight){
                temp=i;
            }
        }
    }
    *s2=temp;
}

void CrtHuffmanCode(HuffmanTree ht,HuffmanCode hc,int n){
    char *cd;
    int start;
    cd=(char*)malloc(n*sizeof(char));
    cd[n-1]='\0';
    for(int i=1;i<=n;i++){
        start=n-1;
        int c=i,p=ht[i].parent;
        while(p){
            --start;
            if(ht[p].leftChild==c){
                cd[start]='0';
            }
            else{
                cd[start]='1';
            }
            c=p;
            p=ht[p].parent;
        }
        hc[i]=(char*)malloc(n-start*sizeof(char));
        strcpy(hc[i],&cd[start]);

    }
    free(cd);
}

void DeCode(HuffmanTree ht,char ch[]){
    int m=11;
    for(int i=0;i<strlen(ch);i++){
        if(ch[i]=='0'){
            m=ht[m].leftChild;
        }else{
            m=ht[m].rightChild;
        }
        if(ht[m].leftChild==0){
            printf("%c",ht[m].data);
            m=1;
        }
    }
}

int main(void){
    HuffmanTree HFMTree;
    int w[7];
    for(int i=1;i<=6;i++){
        scanf("%d",&w[i]);
    }
    char ch[10];
    char ch1[100];
    scanf("%s",ch);
    scanf("%s",ch1);
    CrtHuffmanTree(HFMTree,w,6);
    HuffmanCode HFMCode;
    CrtHuffmanCode(HFMTree,HFMCode,6);
    
}