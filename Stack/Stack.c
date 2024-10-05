#include<stdio.h>
#define max 10
int top=-1;
int s[max];
void push()
{
	int item;
	printf("enter item:");
	scanf("%d",&item);
	if(top==max-1)
	{
		printf("overflow\n");
		return;
	}
	top++;
	s[top]=item;
}
void pop()
{
	if(top==-1)
	{
		printf("underflow\n");
		return;
	}
	printf("%d is popped\n",s[top]);
	top--;
}
void display()
{
	int i;
	if(top==-1)
	{
		printf("underflow\n");
		return;
	}
	printf("stack:\n");
	for(i=top;i>=0;i--)
	{
		printf("%d\n",s[i]);
	}
}
void main()
{
	int option,n=1;
	while(n==1)
	{
		printf("options:\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\nEnter your option:");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				n=0;
				break;
			default:
				printf("enter a valid option\n");
				break;
		}
	}
}