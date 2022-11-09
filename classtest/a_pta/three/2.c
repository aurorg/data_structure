// 7-3 算术表达式求解
// 分数 85
// 作者 曾艳
// 单位 西安邮电大学
// 完成简单的数学表达式的求值问题。假设表达式仅含“加、减、乘、除”四种运算，所有运算对象均为整数。运算结果也是整数，若出现除法，则必然能整除。

// 输入格式:
// 输入一个算术运算式，以“#”结尾，其中运算数都是整型。

// 输出格式:
// 输出运算结果，运算结果也是一个整数。

// 输入样例:
// 34+75/5-4*2#
// 输出样例:
// 41

#include <stdio.h>
#include <string.h>
// 设置符号优先级
int compareysf(char str) {
    if (str == '#') {
        return 0;
    } else if (str == '+' || str == '-') {
        return 1;
    } else if (str == '*' || str == '/') {
        return 2;
    } else { //其他
        return -1;
    }
}
// 计算函数
int jisuan(int a, char str, int b) {
    int s = 0;
    if (str=='-') {
         s=a-b;
    } else if (str == '+') {
         s = a + b;
    } else if (str == '*') {
         s = a * b;
    } else if (str == '/') {
        s = a / b;
    }
    return  s;
}
int main(){
    //用两个栈，第一个数字栈，第二个符号栈
    int  Stack1 [100];
    int Top1 = -1;
    
    char Stack2 [100];
    int Top2 = 0;
    
    
    char str[100];
    int f = -1;
    
    scanf("%s", str);
    //表达式长度
    int x = 0;
    int length = (int)strlen(str);
    str[length] = '#';
    length = length + 1;
    for (int i = 0; i < length;) {
        if (str[i] >= '0' && str[i] <= '9') {
            x*=10;
            x+=str[i++]-'0';
            f=1;
        } else {
            if(f==1) {
             Stack1[++Top1] = x;
             x = 0;
             f=-1;
            }
            if (compareysf(Stack2[Top2]) < compareysf(str[i])) {
                 Stack2[++Top2] = str[i++];
            } else {
                int b =  Stack1[ Top1--];
                int a =  Stack1[ Top1];
                 Stack1[ Top1] = jisuan(a,Stack2[ Top2], b);
                 Top2--;
                if (str[i] == '#' &&  Top2 == 0) {
                    break;
                }
            }
        }
    }
    printf("%d",  Stack1[ Top1]);
}
