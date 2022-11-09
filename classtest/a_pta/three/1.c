#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int x, y;
}Node;

typedef struct
{
    
    Node list[64];
    int top;
    
}SStack;

void instack(SStack *s)
{
    s->top = -1;
}

int pushstack(SStack *s, Node n)
{
    if (s->top == 63)
        return 0;
    else
    {
        s->top++;
        s->list[s->top] = n;
        return 1;
    }
}
int popstack(SStack *s)
{
    if (s->top == -1){
        
        return 0;
        
    }
    else
    {
        s->top--;
        return 1;
    }
}

int iskong(SStack *s)
{
    if (s->top == -1)
        return 1;
    return 0;
}

Node gettopelem(SStack *s)      
{
        Node x;
        x = s->list[s->top];
        return x;
}
SStack s;
int arry1[8][8],  arry2[8][8]; 
//arry1输出位置, arry2 为标记数组

int arry3[8][2] = {-2, 1, -1, 2, 1, 2, 2, 1, 2, -1, 1, -2, -1, -2, -2, -1};
int f = 0;//标记
 
void path(int x, int y, int temp)
{
     if(temp == 64)
    {   f = 1;
        int Count = 0;
        while (!iskong(&s)){
            Node n = gettopelem(&s);
            popstack(&s);
            arry1[n.x][n.y] = 64-(Count++);
        }
        for (int i = 0; i < 8; i++){
            for (int j = 0; j < 8; j++){
                printf("%2d ", arry1[i][j]);
            }
            printf("\n");
        }
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        int x1 = x+arry3[i][0];
        int y1 = y+arry3[i][1];
        if (x1 < 0 || y1 < 0 || x1 > 7 || y1 > 7 || arry2[x1][y1] == 1)
            
        {
            continue;
        }
        
        if(arry2[x1][y1] == 0)
        {
            arry2[x1][y1] = 1;
            Node p;
            p.x = x1;
            p.y = y1;
            pushstack(&s, p);
            path(x1, y1, temp+1);
            if (f)
                return;
            
            arry2[x1][y1] = 0;
            popstack(&s);
        }
    }
    return;
}

int main(void)
{
    instack(&s);
    
    memset(arry2, 0, sizeof(arry2));
    
    int x, y;
    scanf("%d%d", &x, &y);
    arry1[x-1][y-1] = 1;
    arry2[x-1][y-1] = 1;
    path(x-1, y-1, 1);
    return 0;
}
