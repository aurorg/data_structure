#include<stdio.h>
int main()
{
    int a[4]={1,2,3,4};
    int *ptr1=*(a+1);
    int *ptr2=((int)a+1);
    printf("ptr1 = %x\n",ptr1);
    printf("ptr2=%x\n",ptr2);
    printf("a+0=%x a+1=%x ",a+0,a+1);
}
//ptr1 = 2
//ptr2=c217ccd1
//a+0=c217ccd0 a+1=c217ccd4