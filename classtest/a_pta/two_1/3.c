#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct
{
    ElemType elem[MAXSIZE];
    int length;
}SeqList;

SeqList * CreatList();
int FindMin(SeqList *q );

main()
{
    SeqList *q;
    q=CreatList();
    int min=FindMin(q);
    printf("最小值为第%d个，其值为%d。",min+1,q->elem[min]);
}

SeqList * CreatList()
{
    SeqList *sq = (SeqList*)malloc(sizeof(SeqList));
    scanf("%d",&(sq->length));
    for(int i=0;i<sq->length;i++)
    {
        scanf("%d",&(sq->elem[i]));
    }
    return sq;
}


/* 请在这里填写答案 */
int FindMin(SeqList *q )
{
    int i;
	 int temp=q->elem[i];
	for(int i=0;i<q->length;i++){
        
		if(temp>q->elem[i]){
			temp=q->elem[i];
		}
        
	}
	for(i=0;i<q->length;i++){
		if(temp==q->elem[i]){
			break;
		}
	}
	return i;
}
