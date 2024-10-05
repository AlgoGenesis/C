#include<stdio.h>
#define max 5
int Q[max];
int front=-1;
int rear=-1;
int insertion()
{
	int item;
	printf("enter the element that is to be inserted:");
	scanf("%d",&item);
	if(rear==max-1)
	{
		printf("OVERFLOW!!!!");
		return 0;
	}
	if(front==-1||rear==-1)
	{
		front=rear=0;
	}
	else
	{
		rear=rear+1;
	}
	Q[rear]=item;
	return 0;
}
int deletion()
{
	if(front==-1||rear==-1)
	{
		printf("UNDERFLOW!!!!");
		return 0;
	}
	printf("the deleted element is: %d\n",Q[front]);
	if(front==rear)
	{
		front=rear=-1;
	}
	else
	{
		front=front+1;
	}
	return 0;
}
int display()
{
	int i;
	for(i=front;i<=rear;i++)
	{
		printf("%d\t",Q[i]);
	}
	return 0;
}
int main()
{
	int option,n=1;
	while(n==1)
	{
		printf("\nOptions:\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\nEnter your option:");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				insertion();
				break;
			case 2:
				deletion();
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