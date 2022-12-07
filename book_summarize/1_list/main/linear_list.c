#include <stdio.h>
#include <stdlib.h>

//线性表顺序存储
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 //存储空间初始分配量

typedef int Status;  //Status是函数的类型，它的值是函数结果状态代码，比如ok
typedef int ElemType;  //ElemType类型自己根据需求定义，这里是int

typedef struct{
    ElemType data[MAXSIZE];  //数组，存储数据元素
    int length; //线性表当前的长度
} SqList;


//打印函数
Status visit(ElemType c)
{
    printf("%d ", c);
    return OK;
}

//初始化顺序线性表
Status InitList(SqList *L){
    L->length = 0;
    return OK;
}

//判断空表
/* 初始条件：顺序线性表L已经存在
   操作结果：若L是空表，返回TRUE；否则返回FALSE。
*/
Status ListEmpty(SqList L){
    if(L.length==0){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

//返回元素个数
//初始条件：顺序线性表L已经存在，操作结果：返回L中元素的个数
int ListLength(SqList L){
    return L.length;
}

//返回元素的值
//初始条件：L存在
//操作结果：用e返回L中第i个元素的值，！！i指的是位置，第一个位置上的数组是从0开始的
Status GetElem(SqList L,int i,ElemType *e){
    if(L.length==0 || i<1 || i>L.length){
        return ERROR;
    }
    *e = L.data[i - 1];

    return OK;
}

//返回元素的位置
//操作结果：返回L中某个元素e的位置
int LocateElem(SqList L,ElemType e){
    int i;
    if(L.length==0){
        return 0;
    }
    if(i>=L.length){
        return 0;
    }
    for (i = 0; i < L.length;i++){
        if(L.data[i]==e){
            break;
        }
    }
    return i + 1;
}

//插入数据
//操作结果：在L中第i个位置之前插入新的数据元素e；L的长度增加1

Status ListInsert(SqList *L, int i,ElemType e){
    int j;
    if(L->length==MAXSIZE){
        return ERROR;
    }
    if(i<1 || i>L->length+1){
        return ERROR;
    }
    if(i<=L->length){
        for (j = L->length - 1; j>=i;j--){ //将要插入位置之后的元素向后移动一位
            L->data[j + 1] = L->data[j];
        }
    }
    L->data[i - 1] = e; //将新元素插入
    L->length++;

    return OK;
}
