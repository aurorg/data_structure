// 7-1 三元组表矩阵的运算
// 分数 100
// 作者 曾艳
// 单位 西安邮电大学
// 已知两个稀疏矩阵A和B以三元组顺序表进行存储，编写算法实现A+B、A-B，算法的时间复杂度要尽量的低。

// 输入格式:
// 第一行输入三个正整数（空格间隔），依次代表矩阵A的总行数m、总列数n和非零元个数len。

// 第二行按行序为主序，依次输入矩阵A的各个非零元。每个非零元以三元组形式输入，如：（row,col,val），其中row 代表非零元的行号，col代表非零元的列号，val代表非零元的值。

// 第三行输入三个正整数（空格间隔），依次代表矩阵B的总行数m、总列数n和非零元个数len。

// 第四行按行序为主序，依次输入矩阵B的各个非零元。每个非零元以三元组形式输入，如：（row,col,val），其中row 代表非零元的行号，col代表非零元的列号，val代表非零元的值。

// 输出格式:
// 第一、二行输出和；第三、四行输出差。

// 第一行输出三个正整数（空格间隔），依次代表A+B的总行数m、总列数n和非零元个数len。

// 第二行按行序为主序，依次输出A+B的各个非零元。每个非零元以三元组形式输出，如：（row,col,val），其中row 代表非零元的行号，col代表非零元的列号，val代表非零元的值。

// 注意：若没有非零元，则第二行是空行。

// 第三行输出三个正整数（空格间隔），依次代表A-B的总行数m、总列数n和非零元个数len。

// 第四行按行序为主序，依次输出A-B的各个非零元。每个非零元以三元组形式输出，如：（row,col,val），其中row 代表非零元的行号，col代表非零元的列号，val代表非零元的值。

// 注意：若没有非零元，则第四行是空行。

// 输入样例:
// 9 8 5
// (1,2,14)(1,5,-5)(4,2,-7)(5,1,36)(6,6,15)
// 9 8 7
// (1,2,14)(2,8,9)(4,2,7)(4,4,45)(6,6,15)(7,3,10)(9,8,8)
// 输出样例:
// 9 8 8
// (1,2,28)(1,5,-5)(2,8,9)(4,4,45)(5,1,36)(6,6,30)(7,3,10)(9,8,8)
// 9 8 7
// (1,5,-5)(2,8,-9)(4,2,-14)(4,4,-45)(5,1,36)(7,3,-10)(9,8,-8)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int get(char **s1) {
  char *s = *s1;
  int ans = 0, sign = 0;
  while ((*s <= '9' && *s >= '0') || *s == '-') {
    if (*s == '-') {
      sign = 1;
    } else {
      ans = ans * 10 + *s - '0';
    }
    s++;
    (*s1)++;
  }
  (*s1)++;
  if (sign)
    ans *= -1;
  return ans;
}
int main(void) {
  int row, col, sum;
  scanf("%d %d %d", &row, &col, &sum);
  int **A = (int **)calloc(sizeof(int *), sum);
  for (int i = 0; i < sum; i++) {
    A[i] = (int *)calloc(sizeof(int), 3);
  }
  char *s1 = (char *)malloc(100), *s2 = (char *)malloc(100);
  if (sum)
    scanf("%s", s1);
  int row1, col1, sum1, c1 = 0, d1 = 0;
  scanf("%d %d %d", &row1, &col1, &sum1);
  int **B = (int **)calloc(sizeof(int *), sum1);

  for (int i = 0; i < sum1; i++) {
    B[i] = (int *)calloc(sizeof(int), 3);
  }
  if (sum1)
    scanf("%s", s2);

  if (!sum && !sum1) {
    printf("%d %d %d\n", row, col, 0);
    printf("%d %d %d\n", row, col, 0);
  }
  for (int i = 0; i < sum && *s1; i++) {
    while (*s1 && (*s1 == '(' || *s1 == ')'))
      s1++;
    if (!*s1)
      break;
    A[i][0] = get(&s1);
    A[i][1] = get(&s1);
    A[i][2] = get(&s1);
  }

  for (int i = 0; i < sum1 && *s2; i++) {
    while (*s2 && (*s2 == '(' || *s2 == ')'))
      s2++;
    if (!*s2)
      break;
    B[i][0] = get(&s2);
    B[i][1] = get(&s2);
    B[i][2] = get(&s2);
  }
    int **C = (int **)calloc(sizeof(int *), sum + sum1);
  for (int i = 0; i < sum + sum1; i++) {
    C[i] = (int *)calloc(sizeof(int), 3);
  }
  int **D = (int **)calloc(sizeof(int *), sum + sum1);
  for (int i = 0; i < sum + sum1; i++) {
    D[i] = (int *)calloc(sizeof(int), 3);
  }
  //双指针，按顺序一个一个找
  int i = 0, j = 0;
  for (; i < sum && j < sum1;) {
    if (A[i][0] == B[j][0] && A[i][1] == B[j][1]) {
      D[d1][0] = C[c1][0] = A[i][0];
      D[d1][1] = C[c1][1] = A[i][1];
      C[c1++][2] = A[i][2] + B[j][2];
      D[d1++][2] = A[i][2] - B[j][2];
      if (A[i][2] + B[j][2] == 0)
        c1--;
      if (A[i][2] - B[j][2] == 0)
        d1--;
      i++;
      j++;
    } else if ((A[i][0] == B[j][0] && A[i][1] < B[j][1]) ||
               (A[i][0] < B[j][0])) { // A小
      D[d1][0] = C[c1][0] = A[i][0];
      D[d1][1] = C[c1][1] = A[i][1];
      C[c1++][2] = A[i][2];
      D[d1++][2] = A[i][2];
      // printf("2>A[i][2]= %d , B[j][2]= %d\n", A[i][2], B[j][2]);
      i++;
    } else {
      D[d1][0] = C[c1][0] = B[j][0];
      D[d1][1] = C[c1][1] = B[j][1];
      C[c1++][2] = B[j][2];
      D[d1++][2] = -B[j][2];
      // printf("3>A[i][2]= %d , B[j][2]= %d\n", A[i][2], B[j][2]);
      j++;
    }
  }
  while (i < sum) {
    // printf("4>A[i][2]= %d \n", A[i][2]);
    D[d1][0] = C[c1][0] = A[i][0];
    D[d1][1] = C[c1][1] = A[i][1];
    C[c1++][2] = A[i][2];
    D[d1++][2] = A[i][2];
    i++;
  }
  while (j < sum1) {
    // printf("5> B[j][2]= %d\n", B[j][2]);
    D[d1][0] = C[c1][0] = B[j][0];
    D[d1][1] = C[c1][1] = B[j][1];
    C[c1++][2] = B[j][2];
    D[d1++][2] = -B[j][2];
    j++;
  }

  printf("%d %d %d\n", row, col, c1);
  for (int i = 0; i < c1; i++) {
    printf("(%d,%d,%d)", C[i][0], C[i][1], C[i][2]);
  }
  printf("\n");
  printf("%d %d %d\n", row, col, d1);
  for (int i = 0; i < d1; i++) {
    printf("(%d,%d,%d)", D[i][0], D[i][1], D[i][2]);
  }
  printf("\n");
  return 0;
}