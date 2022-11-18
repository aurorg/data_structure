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
            break;
        }
    }
    for(int i=1;i<=n;i++){
        if(ht[i].parent==0 && i!=*s1){
            if(ht[i].weight<ht[temp].weight){
                temp=i;
            }
        }
        *s2=temp;
    }
}

void CrtHuffmanTree(HuffmanTree ht,int w[],int n){
    int m=2*n-1;
    for(int i=1;i<=n;i++){
        ht[i].weight=w[i];
        ht[i].data='A'+i-1;
        ht[i].parent=0;
        ht[i].leftChild=0;
        ht[i].rightChild=0;
    }
    for(int i=n+1;i<=m,i++){
        ht[i].weight=0;
        ht[i].parent=0;
        ht[i].leftChild=0;
        ht[i].rightChild=0;
    }
    for(int i=n+1;i<=m;i++){
        int s1,s2;
        select(ht,i-1,&s1,&s2);
        ht[i].weight=ht[s1].weight+ht[s2].weight;
        ht[i].leftChild=s1;
        ht[i].rightChild=s2;
        ht[s1].parent=i;
        ht[s2].parent=i;
    }
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
            }else{
                cd[start]='1';
            }
            c=p;p=ht[p].parent;
        }
        hc[i]=(char*)malloc((n-start)*sizeof(char));
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
            m=11;
        }
    }
}

int main(){
    HuffmanTree HFMTree;
    int a[7];
    for(int i=1;i<=6;i++){
        scanf("%d",&a[i]);
    }
    char ch[10];
    char ch1[100];
    scanf("%s",ch);
    scanf("%s",ch1);
    CrtHuffmanTree(HFMTree,a,6);
    HuffmanCode HFMCode;
    CrtHuffmanCode(HFMTree,HFMCode,6);
    for(int i=1;i<=6;i++){
        printf("%c:%s\n",'A'+i-1,HFMCode[i]);
    }

    for(int i=0;i<strlen(ch);i++){
        printf("%s",HFMCode);
    }
}