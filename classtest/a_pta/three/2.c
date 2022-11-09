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
