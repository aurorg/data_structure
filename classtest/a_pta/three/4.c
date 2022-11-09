// 7-5 打印杨辉三角形
// 分数 70
// 作者 曾艳
// 单位 西安邮电大学
// 按指定格式输出杨辉三角的前N行。

// 输入格式:
// 输入一个小于30的正整数N。

// 输出格式:
// 输出杨辉三角的前N行，输出时，每个数字之后加一个空格。

// 输入样例:
// 5
// 输出样例:
// 1 
// 1 1 
// 1 2 1 
// 1 3 3 1 
// 1 4 6 4 1 

#include<stdio.h>
int main()
{
	int arr[100][100];
    int n;
	scanf("%d",&n); 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            
            //处理第一个数和最后一个数
            arr[i][1]=1;
            arr[i][i]=1;
            
            //其他数按规律处理
            if(i>=2 &&j>=2){
            	arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
        	}
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("%d",arr[i][j]);
            printf(" ");
        }
        if(i!=n){
        printf("\n");
        }
    }

 
    return 0;
}


 