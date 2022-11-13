//7-2 给定报文，哈弗曼编码、译码
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct hafutree
{
   char ch;
   int  parent;
   int  weight;
   int  lchild;
   int  rchild;
}hafutree;
float wt[200];
char ch_ch[200];
///初始化哈夫曼树
hafutree **inithafutree(int wet[],char diff_zf[],int n)
{ 
  //printf("初始化哈夫曼树\n");
  //getchar();
  hafutree **head;
  head=(hafutree **)malloc(sizeof(hafutree *)*n*2);
  for(int i=1;i<=n;i++)
  {
    head[i]=(hafutree *)malloc(sizeof(hafutree));
    head[i]->ch=diff_zf[i-1];
    head[i]->weight=wet[i-1];
    head[i]->parent=0;
    head[i]->lchild=0;
    head[i]->rchild=0;
  }
  for(int i=n+1;i<2*n;i++)
  {
    head[i]=(hafutree *)malloc(sizeof(hafutree));
    head[i]->ch='#';
    head[i]->weight=0;
    head[i]->parent=0;
    head[i]->lchild=0;
    head[i]->rchild=0;
  }
  return head;
}
///创建好哈夫曼树
void create_hafutree(hafutree **head,int x)
{  
 
	int m,n;//m第一个最小，n第二个最小
	int k=x;//记录下一次存放位置
	while(k<2*x-1)
   {
      for(int j=1;j<=k;j++)
        {
       if(head[j]->parent==0)
       	{
       	m=j;
       	break;
       	}
       }
    for(int i=1;i<=k;i++)
    { 
      if(head[m]->weight>head[i]->weight&&head[i]->parent==0)
      {
        m=i;
      }
    }
    for(int j=1;j<=k;j++)
      {
      	if(head[j]->parent==0&&m!=j)
      	{
      		n=j;
      		break;
      	}
      }			
    for(int i=1;i<=k;i++)
    { 
      if(i==m)
      {
      	continue;
      }
      if(head[n]->weight>head[i]->weight&&head[i]->parent==0)
      {
        n=i;
      }
    }
    head[++k]->weight=head[m]->weight+head[n]->weight;
    head[k]->lchild=m;
    head[k]->rchild=n;
    head[m]->parent=k;
    head[n]->parent=k;
  }
  
}
//对预处理的权值和信息进行排序
void paixu(int getwt[],char getch[])
{ 
   int a;
   char b;
   for(int i=0;i<strlen(getch)-1;i++)
    {
      for(int j=0;j<strlen(getch)-1-i;j++)
      {
        if(getch[j]>getch[j+1])
      {
           b=getch[j+1];
           getch[j+1]=getch[j];
           getch[j]=b;
           a=getwt[j+1];
           getwt[j+1]=getwt[j];
           getwt[j]=a;
      }
      }
    }
    for(int i=0;i<strlen(getch);i++)
    {
      wt[i]=getwt[i];
    }
}
hafutree **getdifferentchar(char *text,int *number)
{   
  hafutree **head;//返回初始化后的哈弗树
  int m=0;//表示text的总数
  int n=0;//记录不同字符
  //int k=0;
  int flog=0;//用来做判断不同字符条件
  char *getch;//保存不同字符
  int *getwt;//保存不同字符的权值
  for(int i=0;text[i]!='#';i++)
  {
    m++;
  }
  text[m]='\0';
  getch=(char *)malloc(sizeof(char)*m);
  getwt=(int *)malloc(sizeof(int)*m);
    for(int i=0;i<=m;i++)//初始化权值数组
  {
    getwt[i]=0;
  }
    getch[n]=text[n];
    getch[++n]='\0';
    for(int i=0;text[i]!='\0';i++)
    {    
      flog=0;
        for(int j=0;getch[j]!='\0';j++)
        {
          if(text[i]==getch[j])
          {
              getwt[j]++;
              flog=1;
              break;                                                                                                                                        
          }
          else
      {
      continue;
        }
        }
        if(flog==0)
        {
          getch[n]=text[i];
          getwt[n]++;
          getch[++n]='\0';
        }
    }
    //调用初始化函数
    *number=strlen(getch);
    paixu(getwt,getch);
    //strcpy(getch,".ADabcdefghilmnoprstuwxyz");
    //puts(getch);
    head=inithafutree(getwt,getch,strlen(getch));
    return head;
}
//进行哈夫曼编码
char **makecode(hafutree **head,int n)
{
   char a[n];
   int start;
   int p;
   int k;
   char **ch;
   ch=(char **)malloc(sizeof(char *)*n);
   ch[0]=(char *)malloc(sizeof(char)*5);
   for(int i=1;i<=n;i++)
   {
      start=n-1;
      a[start]='\0';
      p=head[i]->parent;
      k=i;
      while(p)
      {
        if(head[p]->lchild==k)
        {
          a[--start]='0';
        }
        else if(head[p]->rchild==k)
        {
        a[--start]='1';
        }
        k=p;
        p=head[p]->parent;
     }

     ch[i]=(char *)malloc(sizeof(char)*(n-start));
     strcpy(ch[i],&a[start]);
   }
   return ch;
}
///进行哈夫曼译码
char *translatecode(hafutree **head,char hafu_number[],int y)
{
  int k=0;//记录边缘后位置 
  int m,x,n;
  char *tr;
  tr=(char *)malloc(sizeof(char)*500);
  x=0;
  for(int i=k;hafu_number[i]!='\0';)
   { 
     m=2*y-1;
     n=i;
     while(head[m]->lchild&&head[m]->rchild)
    {
     if(hafu_number[n]=='0')
     {
        m=head[m]->lchild;
     }
     else if(hafu_number[n]=='1')
     {
        m=head[m]->rchild;
     }
     n++;
     i++; 
   }
   tr[x++]=head[m]->ch;
   tr[x]='\0';
  }
  return tr;
}
int main()
{
  char hafuch[500];//待编译码
  char hafu_number[1000];//待解译码
  char hafuch_num[1000]="";
	hafutree **head;
  char *tr;//保存译码后的信息;
  char **ch;
  int n;//记录不同字符个数
  int j;
  gets(hafuch);
  gets(hafu_number);
  //初始化哈弗树
  head=getdifferentchar(hafuch,&n);
  //创建好哈弗树.
  create_hafutree(head,n);
  //哈弗编码ch[]保存信息
  ch=makecode(head,n); 
  //哈弗译码
  //puts(hafuch);
  for(int i=0;hafuch[i]!='\0';i++)
  { 
    j=1;
    while(j<=n)
    { 
      if(head[j]->ch==hafuch[i])
      { 
        strcat(hafuch_num,ch[j]);
        break;
      }
      j++;
    }
  }
  puts(hafuch_num);
  tr=translatecode(head,hafu_number,n);
  puts(tr);

  float sum=0;
    for(int i=0;i<n;i++)
    {
      sum=sum+wt[i]*strlen(ch[i+1])/strlen(hafuch);
    }
   printf("%0.2f",sum);
} 