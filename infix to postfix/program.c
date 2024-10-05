#include<stdio.h>
void push(char);
char pop();
int priority(char);
int op(char);
char Q[100],P[100],S[100];
int top=-1;
int main()
{
	int i,j,k;
	printf("enter the infix expression:");
	scanf("%s",Q);
	for(i=0;Q[i]!='\0';i++);
	Q[i]=')';
	top++;
	S[top]='(';
	i=0,j=0;
	while(top!=-1)
	{
		if(op(Q[i])==1)
		{
			P[j]=Q[i];
			j++;
		}
		else if(op(Q[i])==2)
		{
			push(Q[i]);
		}
		else if(op(Q[i])==3)
		{
			while(op(S[top])==3&&(priority(S[top])>=priority(Q[i])))
			{
				P[j]=pop();
				j++;
			}
			push(Q[i]);
		}
		else if(op(Q[i])==4)
		{
			while(op(S[top])!=2)
			{
				P[j]=pop();
				j++;
			}
			top--;
		}
		i++;
		P[j]='\0';
		printf("\n\t%c\t",Q[i-1]);
		for(k=0;k<=top;k++)
		{
			printf("%c",S[k]);
		}
		printf("\t%s",P);
	}
	return 0;
}
void push(char x)
{
	top++;
	S[top]=x;
}
char pop()
{
	char ch;
	ch=S[top];
	top--;
	return ch;
}
int priority(char x)
{
	if(x=='+'||x=='-')
	{
		return 1;
	}
	else if(x=='*'||x=='/'||x=='%')
	{
		return 2;
	}
	else if(x=='^')
	{
		return 3;
	}
}
int op(char x)
{
	if(x=='(')
	{
		return 2;
	}
	else if(x=='*'||x=='/'||x=='%'||x=='^'||x=='+'||x=='-')
	{
		return 3;
	}
	else if(x==')')
	{
		return 4;
	}
	else 
	{
		return 1;
	}
}