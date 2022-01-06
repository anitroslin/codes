#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char input[100];
int i,l;
void main()
{
printf("\nRecursive descent parsing for the following grammar\n");
printf("\nE->TE'\nE'->+TE'/e\nT->FT'\nT'->*FT'/e\nF->(E)/id\n");
/*
E->TE'
E'->+TE'/e
T->FT'
T'->*FT'/e
F->(E)/id
*/
printf("\nEnter the string to be checked:"); // (a+b)*c
gets(input);
if(E())
{
    if(input[i+1]=='\0')
    printf("\nString is accepted\n");
    else
    printf("\nString is not accepted\n");
}
else
printf("\nString is not accepted\n");
}

E()
{
if(T())
{
    if(EP())
    return(1);
    else
    return(0);
}
else
return(0);
}

EP()
{
    if(input[i]=='+')
    {
        i++;
        if(T())
        {
            if(EP())
            return(1);
            else
            return(0);
        }
        else
        return(0);
    }
    else
    return(1);
}

T()
{
    if(F())
    {
        if(TP())
        return(1);
        else
        return(0);
    }
    else
    return(0);
}

TP()
{
    if(input[i]=='*')
    {
        i++;
        if(F())
        {
            if(TP())
            return(1);
            else
            return(0);
        }
        else
        return(0);
    }
    else
    return(1);
}

F()
{
if(input[i]=='(')
{
    i++;
    if(E())
    {
        if(input[i]==')')
        {
        i++;
        return(1);
        }
        else
        return(0);
    }
    else
    return(0);
}
else if(input[i]>='a'&&input[i]<='z'||input[i]>='A'&&input[i]<='Z')
{
i++;
return(1);
}
else
return(0);
}
