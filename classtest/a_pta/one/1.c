// 6-2 找最大值和次大值
// 分数 20
// 作者 曾艳
// 单位 西安邮电大学
// 找出数组A[1..N]中最大值和次大值。（数组中元素个数大于两个且值各不相同）

// 函数接口定义：
// void FindMax(int a[],int n,int *pmax1,int *pmax2);
// 其中 a 和 n 是用户传入的参数。 a为数组名， n为数组中元素的个数，在下标从1到n处存放。利用指针变量 pmax1和pmax2带出运算结果。 pmax1为指向最大值的指针；pmax2为指向次大值的指针。

// 裁判测试程序样例：
// #include <stdio.h>
// void FindMax(int a[],int n,int *pmax1,int *pmax2);
// main()
// {
//     int a[50],n,i;
//     int max1,max2;
//     scanf("%d",&n);
//     for(i=1;i<=n;i++)
//         scanf("%d",&a[i]);
//     FindMax(a,n,&max1,&max2);
//     printf("%d %d\n",max1,max2);
// }

// /* 请在这里填写答案 */
// 输入样例：
// 5
// 32 45 57 8754 33

#include <stdio.h>
void FindMax(int a[],int n,int *pmax1,int *pmax2);
main()
{
    int a[50],n,i;
    int max1,max2;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    FindMax(a,n,&max1,&max2);
    printf("%d %d\n",max1,max2);
}

/* 请在这里填写答案 */
void FindMax(int a[],int n,int *pmax1,int *pmax2){
    for(int i=1;i<=n;i++){
        int max=i;
        for(int j=i+1;j<=n;j++){
            if(a[j]>a[max]){
                max=j;
            }
        }
        if(i!=max){
            int t=a[i];
            a[i]=a[max];
            a[max]=t;
        }
    }
    *pmax1=a[1];
    *pmax2=a[2];
}