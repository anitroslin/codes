%{
#include<stdio.h>
%}
delim[\t]
ws{delim}+
letter [A-Za-z]*
digit [0-9]
id [a-zA-Z_][a-zA-Z_0-9]*
num {digit}+(\.{digit}+)?(E[+|-]?{digit}+)?

%%
#.* {printf("\n%s is a preprocessor directive",yytext);}
ws {printf("no action");}
int |
float |
char |
double |
while |
for |
struct |
typedef |
do |
if |
break |
continue |
void |
switch |
return |
else | 
goto {printf("%s is a keyword\n",yytext);}
\{  {printf("\n BLOCK BEGINS");}
\}  {printf("BLOCK ENDS ");}
{id}\( {printf("%s) is a Function \n",yytext);}
\) {printf("\n");}
{id}  {printf(" %s is a identifier\n",yytext);}
{num} {printf(" %s is a number\n",yytext);}
\".*\" {printf("\n\t %s is a STRING",yytext);}
\,|;  {printf("\n");}
"=" {printf("%s is assignement operator\n",yytext);}
"<" {printf("%s is relational operator less than\n",yytext);}
"<=" {printf("%s is a relational operator less than or equal\n",yytext);}
">" {printf("%s is relatrional operator greater than\n",yytext);}
">=" {printf("%s is relational operator greater than or equal to\n",yytext);}
"==" {printf("%s is a relational operator equal to\n",yytext);}
"<>" {printf("%s is a relational operator not equal\n",yytext);}
%%

int yywrap(void)
{
return 0;
}

int main()
{
yylex();
return 0;
}