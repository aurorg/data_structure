// 7-2 求解马鞍点问题
// 分数 100
// 作者 曾艳
// 单位 西安邮电大学
// 若矩阵Anm中某个元素A[i][j]是矩阵第i行中值最小的元素，同时又是第j列中值最大的元素，则称元素A[i][j]是矩阵中的一个马鞍点。

// 设以二维数组存储矩阵，编写算法求矩阵A中的所有马鞍点，算法的时间复杂度要尽量的低。

// 注意当最大值（最小值）并列相等时，会出现多鞍点的情况。

// 输入格式:
// 第一行输入矩阵的总行数M和总列数N，以空格间隔。

// 之后的M行，依次输入矩阵的各行数据，以空格间隔。

// 输出格式:
// 若有马鞍点，则以行序为主序，依次输出各个马鞍点。

// 每个马鞍点以（row,col,val）的形式输出，其中row 代表马鞍点的行号，col代表马鞍点的列号，val代表马鞍点的值。

// 若无马鞍点，则输出“NONE”。

// 输入样例:
// 4 6
// 45 67 87 34 56 26
// 93 75 85 75 92 75
// 94 85 96 75 78 75
// 23 17 75 28 98 61
// 输出样例:
// (2,4,75)(2,6,75)(3,4,75)(3,6,75)

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int m = 0;
    int n = 0;
 
    int i = 0;
    int j = 0;
 
    int flag = 0;
    int num = 0;
 
    int* min = (int *)malloc(n * sizeof(int));
    int* max = (int *)malloc(m * sizeof(int));
 
    scanf("%d%d", &m, &n);
    int **arr = (int**)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
 
    for (i = 0; i < m; i++)
    {
        min[i] = arr[i][0];
        for (j = 1; j < n; j++)
        {
            if (arr[i][j] < min[i])
            {
                min[i] = arr[i][j];
            }
        }
    }
 
    for (j = 0; j < n; j++)
    {
        max[j] = arr[0][j];
        for (i = 1; i < m; i++)
        {
            if (arr[i][j] > max[j])
            {
                max[j] = arr[i][j];
            }
        }
    }
 
    for (i = 0; i < m; i++)
    {
        if (flag == 1 && min[i] != num)
            continue;
        for (j = 0; j < n; j++)
        {
            if (min[i] == arr[i][j] && max[j] == arr[i][j])
            {
                if (flag == 0)
                { 
                    flag = 1;
                    num = arr[i][j];
                }
                printf("(%d,%d,%d)", i + 1, j + 1, arr[i][j]);
            }
        }
    }
 
    if (flag == 0)
    {
        printf("NONE");
    }
    return 0;
}