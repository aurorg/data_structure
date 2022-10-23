#include<stdio.h>
int main()
{
    int array[4]={1,2,3,4};
    int *p1=*(array+1);
    int *p2=((int)array+1);
    printf("p1 = %x\n",p1);
    printf("p2=%x\n",p2);
    printf("array+0=%x aray+1=%x ",array+0,array+1);
}