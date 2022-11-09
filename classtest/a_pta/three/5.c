// 7-6 回文判断
// 分数 60
// 作者 曾艳
// 单位 西安邮电大学
// 回文指正反读均相同的字符序列，例如“abba”和”abdba”均是回文，但“good”不是回文，判定给定字符串是否是回文。

// 输入格式:
// 输入一个字符串

// 输出格式:
// 如果是回文，输出“回文”；否则输出“不是回文”

// 输入样例1:
// aabcba
// 输出样例1:
// 不是回文
// 输入样例2:
// abba
// 输出样例2:
// 回文

#include <stdio.h>
#include <string.h>
int main()
{
     
	char c[20];
	int n=0; 
    int f = 0;
	gets(c);
	int weishu=strlen(c);
	n=weishu-1;
	if (weishu%2==0)
	{
		for (int i=0;i<=n*0.5;i++)
		{
			if (c[i]!=c[n-i])
				f=1;
		}
	}
	else
	{
        for(int i = 0; i <=(n-1)*0.5; i++)
		{
			if (c[i]!=c[n-i])
				f=1;
		}
	}
	if (f){
		printf("不是回文");
    }
	else{
		printf("回文");
    }
	return 0;
}
