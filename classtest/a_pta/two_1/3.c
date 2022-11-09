// 6-3 找出顺序表中的最小值
// 分数 15
// 作者 曾艳
// 单位 西安邮电大学
// 已知长度为n的线性表采用顺序存储结构，请设计一个算法，找出该线性表中值最小的数据元素。
// 顺序表的存储结构如下：

// #define MAXSIZE 100
// typedef int ElemType;
// typedef struct
// {
//     ElemType elem[MAXSIZE]; 
//     int length;
// }SeqList;
// 函数接口定义：
// int FindMin(SeqList *q );
// 其中 q 是用户传入的参数，为指向顺序表的指针。函数返回值最小元素的下标。（注意，下标从0开始）

// 裁判测试程序样例：
// #include<stdio.h>
// #include<stdlib.h>
// #define MAXSIZE 100
// typedef int ElemType;
// typedef struct
// {
//     ElemType elem[MAXSIZE];
//     int length;
// }SeqList;

// SeqList * CreatList();
// int FindMin(SeqList *q );

// main()
// {
//     SeqList *q;
//     q=CreatList();
//     int min=FindMin(q);
//     printf("最小值为第%d个，其值为%d。",min+1,q->elem[min]);
// }

// SeqList * CreatList()
// {
//     SeqList *sq = (SeqList*)malloc(sizeof(SeqList));
//     scanf("%d",&(sq->length));
//     for(int i=0;i<sq->length;i++)
//     {
//         scanf("%d",&(sq->elem[i]));
//     }
//     return sq;
// }


// /* 请在这里填写答案 */
// 输入样例：
// 在这里给出一组输入。例如：

// 5
// 12 45 8 345 67
// 输出样例：
// 在这里给出相应的输出。例如：

// 最小值为第3个，其值为8。

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
