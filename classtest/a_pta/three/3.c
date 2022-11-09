// 7-4 中缀表达式转后缀表达式问题
// 分数 80
// 作者 曾艳
// 单位 西安邮电大学
// 假定运算符集合为{ +、-、*、/、（、）}，利用栈将输入的中缀表达式转换成等价的后缀表达式，并输出。

// 输入格式:
// 输入一个字符串表示的中缀表达式（以“#”结束），其中每个操作数用一个小写字母表示。

// 输出格式:
// 将对应的后缀表达式输出。

// 输入样例:
// a+b-a*((c+d)/e-f)+g#
// 输出样例:
// ab+acd+e/f-*-g+
#include <stdio.h>
#include <string.h>
#include <stdio.h>

int  jisuan(char str) {
    if (str == '#') {
        return 0;
    } else if (str == '+' || str == '-') {
        return 1;
    } else if (str == '*' || str == '/') {
        return 2;
    } else if (str == '(' || str == ')') {
        return 0;
    }
    else {
        return -1;
    }
}
int main (void) {
    char str1[100];
    int l1 = -1;
    
    int str2[100];
    int l2 = -1;
    
    char str[100];
    
    scanf("%s", str);
    int length = (int)strlen(str);
    
    for (int i = 0; i < length; ) {
        if (jisuan(str[i]) == -1) {
            str1[++l1] = str[i++];
            
        } else if (str[i] == '(') {
            str2[++l2] = str[i++];
            
        } else if (str[i] == ')') {
            
            while (jisuan(str2[l2]) != 0) {
                str1[++l1] = str2[l2--];
            }
            
            l2--;
            i++;
        } else {
            if (l2 == -1 || jisuan(str2[l2]) < jisuan(str[i])) {
                str2[++l2] = str[i++];
            } else {
                str1[++l1] = str2[l2--];
            }
            if (str[i] == '#') {
                break;
            }
        }
    }

    for (int i = 0; i <= l1; i++) {
        printf("%c", str1[i]);
    }
    
    
}