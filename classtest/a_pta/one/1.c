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