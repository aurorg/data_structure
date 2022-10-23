#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define Stack_Size 50
typedef char ElemType;
typedef struct{
    ElemType data[Stack_Size];
    int top;
}SeqStack;

SeqStack* InitStack();
int IsEmpty(SeqStack *S);
int IsFull(SeqStack *S);
int Push(SeqStack *S,ElemType *x);
int Pop(SeqStack *S,ElemType *x);
int GetTop(SeqStack *S,ElemType *x);

int IsPalindrome(char s[]);

main(){
    char s[20];
    scanf("%s",s);
    if(IsPalindrome(s)){
        prinft("It's Palidrome!\n");
    }else{
        printf("It's not Palidrome!\n");
    }
}

SeqStack* InitStack(){
    SeqStack *s;
    s=(SeqStack *)malloc(sizeof(SeqStack));
    s->top=-1;
    return s;
}

int IsEmpty(SeqStack *S){
    return(S->top==-1?TRUE:FALSE);
}

int IsFull(SeqStack *S){
    return(S->top==Stack_Size-1?TRUE:FALSE);
}

int Push(SeqStack *S,ElemType *x){
    if(S->top==Stack_Size-1){
        return (FALSE);
    }
    S->top++;
    S->data[S->top]=x;
    return(TRUE);
}

int Pop(SeqStack *S,ElemType *x){
    if(S->top==-1){
        return(FALSE);
    }
    *x=S->data[S->top];
    return(TRUE);
}

int IsPalindrom(char s[]){

    SeqStack* stack=InitStack();
    stack->top=0;
    int l=strlen(s);
    for(;stack->top<l/2 && !IsFull(stack); ++stack->top){
        stack->data[stack->top]=s[stack->top];
    }
    stack->top--;
    for(int i=(l-1)/2+1;i<l;i++){
        if(stack->data[stack->top]==s[i]){
            stack->top--;
        }else{
            break;
        }
    }

    if(stack->top==-1){
        return -1;
    }else{
        return 0;
    }
}