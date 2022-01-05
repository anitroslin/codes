%{
	#include<stdio.h>
}%

identifier [a-zA-Z][a-zA-Z0-9]*

%%
#.*	{printf("\n%s is a Preprocessor Directive",yytext);}

int|float|main|if|else|printf|scanf|for|char|while	{printf("\n%s is a Keyword",yytext);}



