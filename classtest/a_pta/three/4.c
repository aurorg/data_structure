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


 