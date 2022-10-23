#include<stdio.h>
#include<stdlib.h>

typedef struct Node *list;
struct Node{
	char data[1001];
	int top;//设置为从0~top;top为最后元素下标
	
};


//入栈;
void push(list s,char ch){
	(s->top)++;
	s->data[s->top]=ch;
	
}
//出栈;
char pop(list s){
	if(s->top==-1)
		return '0';
	(s->top)--;
	return (s->data[s->top+1]);
}


int main(){
	char str[1002];
	char ch;
	int loc=0;
	gets(str);
	list ps=(list)malloc(sizeof(struct Node));//存待处理的字符串
	ps->top=-1;
	while(str[loc]!='\0'){//字符串结尾跳出
		ch=str[loc];
		//遇到数字打印数字
		if(ch>='0'&&ch<='9'){
			while(ch!=' '){
				printf("%c",ch);
				loc++;
				ch=str[loc];
				//如果结尾为数字
				if(str[loc]=='\0')break;
			}
			printf(" ");
			if(str[loc]=='\0')break;
			loc++;
			ch=str[loc];
			
		}
		//处理运算符
		if(ch=='('){
			push(ps,ch);
		}else if(ch=='+' || ch == '-'){
			//如果ps栈为空，或遇到（跳出
			while(ps->top!=-1 && ps->data[ps->top]!='('){
				printf("%c ",pop(ps));
			}
			push(ps,ch);
		}else if(ch == '*'  || ch == '/'){
			while(ps->top!=-1 && ps->data[ps->top]!='(' && ps->data[ps->top]!='+' && ps->data[ps->top]!='-'){
				printf("%c ",pop(ps));
			}
			push(ps,ch);
		}else if(ch==')'){
			while(ps->data[ps->top]!='('){
				printf("%c ",pop(ps));
			}
			pop(ps);
		}
		loc++;
		if((str[loc])=='\n')
			break;
	}
	while(ps->top!=-1){
		//设置打印格式
		if(ps->top==0){
			printf("%c",pop(ps));}
		else{
			printf("%c ",pop(ps));
		}
	}
	return 0;
}
