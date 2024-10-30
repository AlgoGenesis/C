#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#define max 50
char stack[max][20];
int top;

void PrTI(char prefix[],char infix[])
{
    int i;
    char t,a[max],b[max];
    top=-1;
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
            a[0]='(';
            a[1]='\0';
            strcat(a,stack[top]);
            b[0]=t;
            b[1]='\0';
            strcat(a,b);
            top--;
            strcat(a,stack[top]);
            b[0]=')';
            b[1]='\0';
            strcat(a,b);
            strcpy(stack[top],a);
        }
    }
    strcpy(infix,stack[top]);
    printf("\nprefix to infix expression...\n");
    puts(infix);
}

void main()
{
    char infix[max],postfix[max],prefix[max];
    clrscr();
    printf("\nenter prefix expression_\n");
    gets(prefix);
    PrTI(prefix,infix);
    getch();
}