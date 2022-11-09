#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define Stack_Size 50
typedef char ElemType;
typedef struct
{      ElemType  data[Stack_Size]; 
       int  top; 
}SeqStack;

//栈的基本操作函数定义
SeqStack* InitStack();  //栈初始化
int IsEmpty(SeqStack *S); //栈判空
int IsFull(SeqStack *S);  //栈判满
int Push(SeqStack * S, ElemType x);  //  入栈
int Pop(SeqStack * S, ElemType *x);  //  出栈
int GetTop(SeqStack *S, ElemType *x); // 取栈顶元素


int IsBracketMatch(char *str);//判断str中括号是否匹配。

main()
{
    char s[20];
    scanf("%s",s);
    if( IsBracketMatch(s))
        printf("Match!\n"); 
    else
        printf("Not Match!\n");
}


SeqStack* InitStack()
{
    SeqStack *s;
    s=(SeqStack *)malloc(sizeof(SeqStack));
    s->top=-1;
    return s;
}
int IsEmpty(SeqStack *S)     
{
      return(S->top==-1?TRUE:FALSE);
}
int IsFull(SeqStack *S)
{
   return(S->top== Stack_Size-1?TRUE:FALSE);
}
int Push(SeqStack * S, ElemType x)
{
     if(S->top== Stack_Size-1)  
         return(FALSE); 
     S->top++;
     S->data[S->top]=x;
     return(TRUE);
}
int Pop(SeqStack * S, ElemType *x)
{     if(S->top==-1)     
             return(FALSE);
      *x= S->data[S->top];
      S->top--;    
      return(TRUE);
}
int GetTop(SeqStack *S, ElemType *x)
{  
      if(S->top==-1)
            return(FALSE);
      *x = S->data[S->top];
      return(TRUE);
}



/* 请在这里填写答案 */
int IsBracketMatch(char *str) {
    SeqStack *stack = InitStack();
    ElemType temp = ' ';
    int l =strlen(str);
    for (int i = 0; i < l; ++i) {
        if ((!IsFull(stack))  && (str[i] == '(' || str[i] == '[' || str[i] == '{')) {
            Push(stack, str[i]);
        } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            switch (str[i]) {
                case ')':
                    if (GetTop(stack, &temp) && temp == '(') {
                        Pop(stack, &temp);
                    } else {
                        return 0;
                    }
                    break;
                case ']':
                    if (GetTop(stack, &temp) && temp == '[') {
                        Pop(stack, &temp);
                    } else {
                        return 0;
                    }
                    break;
                case '}':
                    if (GetTop(stack, &temp) && temp == '{') {
                        Pop(stack, &temp);
                    } else {
                        return 0;
                    }
                    break;
                default :
                    break;
            }
        }
    }
    if (IsEmpty(stack)) {
        return 1;
    }else{
        return 0;
    }
}