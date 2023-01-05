#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20  //存储空间初始分配量

typedef int Status;  //Status 是函数的类型。它的值是函数结果状态代码
typedef int ElemType; //ElemType类型自己根据需求定义、

typedef struct{
    ElemType data[MAXSIZE]; //数组，存储数据元素
    int length; //线性表当前的长度
} SqList;


//打印函数
Status visit(ElemType c){
    printf("%d ", c);
    return OK;
}

//初始化顺序线性表
Status InitList(SqList *L){
    L->length = 0;
    return OK;
}

//判断空表
Status ListEmpty(SqList L){
    if(L.length==0){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

Status ClearList(SqList *L){
    L->length = 0;
    return OK;
}

int Listlength(SqList L){
    return L.length;
}

Status GetElem(SqList L,int i,ElemType *e){
    if(L.length==0 || i<1 || i>L.length){
        return ERROR;
    }
    
}
