#include <stdio.h>
#define Stack_Size 50
#define StackElementType int
#define ElemType int

void InitStack(SeqStack *S); //栈的初始化
int IsEmpty(SeqStack S); //判断栈是否是空的
int IsFull(SeqStack S); //判断栈是否满了
int Push(SeqStack*S,ElemType x); //入栈
int Pop(SeqStack*S,ElemType x); //出栈



typedef struct{
    StackElementType elem[Stack_Size];
    int top;
}SeqStack;

int main(void){
    SeqStack stack;
    stack.top=0;
}

void InitStack(SeqStack *S){
    S->top=-1;
}

int IsEmpty(SeqStack S){
    if(S.top==-1)
        return 1;
    else
        return 0;
}

int IsFull(SeqStack S){
    if(S.top==Stack_Size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int Push(SeqStack*S,ElemType x){
    if(S->top==Stack_Size-1){
        return 0;
    }
    S->top++;
    S->elem[S->top]=x;
    return 1;
}

int Pop(SeqStack*S,ElemType x){
    if(S->top==-1){
        return 0;
    }
    x=S->elem[S->top];
    S->top--;
    return 1;
}



