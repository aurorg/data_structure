#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void fun(char *p)
{
	p=(char *) malloc(100);
	strcpy(p,"hello freshman");
}
int main( )
{
	char *s=NULL;
	fun(s);
	printf("%s\n",s);
	free(s);
	return 0;
}  