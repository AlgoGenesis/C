#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#define max 50
char stack[max][20];
int top;
void PrTPo(char prefix[],char postfix[])
{
    int i;
    top=-1;
    char a[max],b[max],t;
    for(i=(strlen(prefix)-1);i>=0;i--)
    {
        t=prefix[i];
        if(isalnum(t))
        {
            a[0]=t;
            a[1]='\0';
            top++;
            strcpy(stack[top],a);
        }
        else
        {
            strcpy(a,stack[top]);
            top--;
            strcat(a,stack[top]);
            b[0]=t;
            b[1]='\0';
            strcat(a,b);
            strcpy(stack[top],a);
        }
    }
    strcpy(postfix,stack[top]);
    printf("\nprefix to postfix expression is...\n");
    puts(postfix);
}

void main()
{
    char postfix[max],prefix[max];
    clrscr();
    printf("\nenter prefix expression_\n");
    gets(prefix);
    PrTI(prefix,postfix);
    getch();
}