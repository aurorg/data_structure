// 6-2 判断表达式中括号是否匹配
// 分数 12
// 作者 曾艳
// 单位 西安邮电大学
// 设算术表达式中有圆括号、方括号、花括号，设计一个算法，判断表达式中的各种括号是否配对。

// 说明：

// （1）本题仅判断括号是否配对，对于表达式其它问题不做检测。

// （2）括号只考虑配对问题，不考虑括号间的嵌套准则。例如：(a+(b-[c+d])*{e/f}) 中的括号是匹配的；（a+{b-c)} 中的括号不匹配。

// 函数接口定义：
// int IsBracketMatch(char *str);//判断str中括号是否匹配。
// 其中 str是用户传入的参数，其值为带判断表达式。 若括号匹配则返回1，否则返回0。

// 栈的定义如下：

// #define Stack_Size 50
// typedef char ElemType;
// typedef struct
// {      ElemType  data[Stack_Size]; 
//        int  top; 
// }SeqStack;

// //栈的基本操作函数定义
// SeqStack* InitStack();  //栈初始化
// int IsEmpty(SeqStack *S); //栈判空
// int IsFull(SeqStack *S);  //栈判满
// int Push(SeqStack * S, ElemType x);  //  入栈
// int Pop(SeqStack * S, ElemType *x);  //  出栈
// int GetTop(SeqStack *S, ElemType *x); // 取栈顶元素
// 裁判测试程序样例：
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define TRUE 1
// #define FALSE 0

// #define Stack_Size 50
// typedef char ElemType;
// typedef struct
// {      ElemType  data[Stack_Size]; 
//        int  top; 
// }SeqStack;

// //栈的基本操作函数定义
// SeqStack* InitStack();  //栈初始化
// int IsEmpty(SeqStack *S); //栈判空
// int IsFull(SeqStack *S);  //栈判满
// int Push(SeqStack * S, ElemType x);  //  入栈
// int Pop(SeqStack * S, ElemType *x);  //  出栈
// int GetTop(SeqStack *S, ElemType *x); // 取栈顶元素


// int IsBracketMatch(char *str);//判断str中括号是否匹配。

// main()
// {
//     char s[20];
//     scanf("%s",s);
//     if( IsBracketMatch(s))
//         printf("Match!\n"); 
//     else
//         printf("Not Match!\n");
// }


// SeqStack* InitStack()
// {
//     SeqStack *s;
//     s=(SeqStack *)malloc(sizeof(SeqStack));
//     s->top=-1;
//     return s;
// }
// int IsEmpty(SeqStack *S)     
// {
//       return(S->top==-1?TRUE:FALSE);
// }
// int IsFull(SeqStack *S)
// {
//    return(S->top== Stack_Size-1?TRUE:FALSE);
// }
// int Push(SeqStack * S, ElemType x)
// {
//      if(S->top== Stack_Size-1)  
//          return(FALSE); 
//      S->top++;
//      S->data[S->top]=x;
//      return(TRUE);
// }
// int Pop(SeqStack * S, ElemType *x)
// {     if(S->top==-1)     
//              return(FALSE);
//       *x= S->data[S->top];
//       S->top--;    
//       return(TRUE);
// }
// int GetTop(SeqStack *S, ElemType *x)
// {  
//       if(S->top==-1)
//             return(FALSE);
//       *x = S->data[S->top];
//       return(TRUE);
// }



// /* 请在这里填写答案 */
// 输入样例1：
// 在这里给出一组输入。例如：

// (a+(b-[c*d]-{e/f}))
// 输出样例1：
// 在这里给出相应的输出。例如：

// Match!
// 输入样例2：
// 在这里给出一组输入。例如：

// (a+[b-(c*d]-{e/f}))
// 输出样例2：
// 在这里给出相应的输出。例如：

// Not Match!

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