#include <stdio.h>
#include <string.h>
int main()
{
     
	char c[20];
	int n=0; 
    int f = 0;
	gets(c);
	int weishu=strlen(c);
	n=weishu-1;
	if (weishu%2==0)
	{
		for (int i=0;i<=n*0.5;i++)
		{
			if (c[i]!=c[n-i])
				f=1;
		}
	}
	else
	{
        for(int i = 0; i <=(n-1)*0.5; i++)
		{
			if (c[i]!=c[n-i])
				f=1;
		}
	}
	if (f){
		printf("不是回文");
    }
	else{
		printf("回文");
    }
	return 0;
}
