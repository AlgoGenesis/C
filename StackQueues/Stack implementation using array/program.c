#include<stdio.h>
#include<stdlib.h>
#define max 3
int i;
int stack[max];
int top=-1;
void push(int ele)
{
    if(top==max-1)
        printf("\nStack overflow");
    else
    {
        top++;
        stack[top]=ele;
    }
}
int pop()
{
    int ele;
    if(top==-1)
        printf("\nstack underflow");
    else
    {
        ele=stack[top];
        top--;
        return ele;
    }
    return -9999;
}
void display()
{
    if(top==-1)
        printf("\nstack empty");
    else
    {
        for(i=top:i>=0:i--)
        printf("\n%d is at position %d", stack[i],i);
    }
}
void main()
{
    int ele, ch; 
    while(1)
    {
        printf("\n1 for push \n2 for pop \n3 for display \n4 for exit");
        printf("\nEnter choice");
        scanf("%d", &ch);
    switch(ch)
    {
        case 1: 
            printf("\nEnter element to push"):
             scanf("%d",&ele);
            push(ele);
            break;
        case 2:
            ele=pop();
            if(ele!=-9999)
            printf("\nPopped element is %d", ele);
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nExit"); exit(0);
        default:
            printf("\nWrong choice");
        }
    }
}