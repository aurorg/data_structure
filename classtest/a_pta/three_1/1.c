// 6-1 使用栈完成回文判断
// 分数 12
// 作者 曾艳
// 单位 西安邮电大学
// 回文是指正读反读均相同的字符序列，如“abba”和“abdba”均是回文，但“good”不是回文。试写一个算法判定给定的字符串是否为回文。

// 函数接口定义：
// int IsPalindrome(char s[]);  //判断字符串s是否回文。
// 其中 s 是用户传入的参数，其值为待判断字符串。如果s 是回文，则返回值为1，否则返回值为0。

// 特别说明：本题要求使用栈的基本操作完成回文的判断。
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


// int IsPalindrome(char s[]);  //判断字符串s是否回文。

// main()
// {
//     char s[20];
//     scanf("%s",s);
//     if(IsPalindrome(s))
//         printf("It's Palidrome!\n"); 
//     else
//         printf("It's not Palidrome!\n");
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
// 输入样例：
// 在这里给出一组输入。例如：

// abba
// 输出样例：
// 在这里给出相应的输出。例如：

// It's Palidrome!

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


int IsPalindrome(char s[]);  //判断字符串s是否回文。

main()
{
    char s[20];
    scanf("%s",s);
    if(IsPalindrome(s))
        printf("It's Palidrome!\n"); 
    else
        printf("It's not Palidrome!\n");
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
int IsPalindrome(char s[]) {
    SeqStack* stack = InitStack();
    stack->top = 0;
    int l = strlen(s);
    for ( ; !IsFull(stack) && stack->top < l / 2; ++stack->top) {
       stack->data[stack->top] = s[stack->top];
    }
    stack->top--;
    for (int i = (l - 1) / 2 + 1; i < l; ++i) {
        if (stack->data[stack->top] == s[i]) {//比较
            stack->top--;
        }
        else {
            break;
        }
    }
    if (stack->top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}
