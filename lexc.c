#include<string.h>
#include<stdio.h>
#include<ctype.h>
int isKeyword(char buffer[]){
	char keywords[32][10] = {"auto","break","case","char","const","continue","default",
	                         "do","double","else","enum","extern","float","for","goto",
                                 "if","int","long","register","return","short","signed",
                                 "sizeof","static","struct","switch","typedef","union",
 			         "unsigned","void","volatile","while"};
	int i, f = 0;
	for(i = 0; i < 32; ++i){
		if(strcmp(keywords[i], buffer) == 0){
		f = 1;
	break;
	}
	}
	return f;
	}

int isOperator(char ch)
{
int f=0;
switch(ch)
{
case '+': 
case '-':
case '*':
case '/':
case '=':f=1;break;
default: f=0;break;
}
return(f);
}
int main()
{
FILE *f1;
f1=fopen("input.txt","r");
char ch,buffer[20];
while((ch=fgetc(f1))!=EOF)
{
int i=0;

if((isOperator(ch))==1)
     printf("%c is operator\n",ch);
else if(isalpha(ch))
    {
    while(isdigit(ch)||isalpha(ch)||ch=='_'||ch=='$')
	{
	buffer[i++]=ch;
	ch=getc(f1);
	}
    buffer[i++]='\0';
    if((isKeyword(buffer))==1)
    	printf("%s is keyword\n",buffer);
    else
    	printf("%s is identifier\n",buffer);
    }
else 
continue;
}
fclose(f1);
}
