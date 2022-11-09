// 6-1 数组中按值找元素
// 分数 20
// 作者 曾艳
// 单位 西安邮电大学
// 在数组A[1..N]中查找值为k的元素，若找到输出其位置i(1<=i<=n)，否则输出0作为标志。

// 函数接口定义：
// Search(int a[],int n,int k);
// 其中 a 、 n、k 都是用户传入的参数。a 为数组名，期中存了n个整数，下标为1到n；k 为待查数据元素；若找到了，返回其下标；否则，返回0。

// 裁判测试程序样例：
// #include <stdio.h>
// Search(int a[],int n,int k);
// main()
// {
//     int a[50],n,i,k;
//     scanf("%d",&n);  //接收数组元素个数
//     for(i=1;i<=n;i++)   //依次接收各个元素的值
//         scanf("%d",&a[i]);
//     scanf("%d",&k);      // 接收待查元素值k
//     int x=Search(a,n,k);  
//     if(x==0)
//         printf("NONE\n");
//     else
//         printf("%d\n",x);

// }

// /* 请在这里填写答案 */
// 输入样例1：
// 5
// 67 48 90 34 25
// 34
// 输出样例1：
// 4
// 输入样例2：
// 6
// 45 67 89 9 7 5 56
// 34
// 输出样例2：
// NONE


#include <stdio.h>
Search(int a[],int n,int k);
main()
{
    int a[50],n,i,k;
    scanf("%d",&n);  //接收数组元素个数
    for(i=1;i<=n;i++)   //依次接收各个元素的值
        scanf("%d",&a[i]);
    scanf("%d",&k);      // 接收待查元素值k
    int x=Search(a,n,k);  
    if(x==0)
        printf("NONE\n");
    else
        printf("%d\n",x);

}

/* 请在这里填写答案 */
Search(int a[],int n,int k){
    for(int i=1;i<=n;i++){
        if(a[i]==k){
            return i;
        }
        else if(i==n){
            return 0;
        }
    }
    
}