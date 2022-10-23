#include <stdio.h>
#include <stdlib.h>
typedef struct Node *list;

struct Node{
    char data[100];
    int length; 
};

void push(list s,char ch){
    (s->length)++;
    s->data[s->length]=ch;
}

char pop(list s){
    if(s->length==-1){
        return '0';
    }
    (s->length)--;
    return (s->data[s->length+1]);
}

int main(){
    char str[101];
    char ch;
    int loc;
    gets(str);
    list p=(list)malloc(sizeof(struct Node));

    p->length=-1;
    while(str[loc]!='#'){
        ch=str[loc];

        if(ch>='97' && ch<='122'){
            printf("%c",ch);
            loc++;
            ch=str[loc];
            
        }
    }
}