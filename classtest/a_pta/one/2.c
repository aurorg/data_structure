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