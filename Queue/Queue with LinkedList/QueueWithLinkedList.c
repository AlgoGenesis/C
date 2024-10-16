#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};

void Display();
bool IsEmpty();
void Enqueue();
int Dequeue();
int Peek();
void freeQueue(struct node *ptr);

struct node *front = NULL;
struct node *rear = NULL;

int main()
{
    int choice;

    while (true)
    {
        printf("\n1.Enqueue Data\n2.Dequeue\n3.Display Queue\n4.Check Empty\n5.Peek\n6.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Enqueue();
            break;
        case 2:
            printf("Dequeued : %d\n\n", Dequeue());
            break;
        case 3:
            Display();
            break;
        case 4:
            if (IsEmpty())
                printf("Queue is empty.\n\n");
            else
                printf("Queue is not empty.\n\n");
            break;
        case 5:
            printf("front element is : %d\n\n", Peek());
            break;
        case 6:
            freeQueue(front);
            exit(0);
            break;
        default:
            printf("Invalid Operation\n\n");
            break;
        }
    }
    return 0;
}

void Display()
{
    struct node *ptr = front;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n\n");
}

bool IsEmpty()
{
    if (front == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Enqueue()
{
    int data;
    printf("Enter data to add: ");
    scanf("%d", &data);

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if (IsEmpty())
    {
        rear = temp;
        front = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
    printf("Data Queued!\n\n");
}

int Dequeue()
{
    if (IsEmpty())
    {
        printf("Queue is empty! Nothing to delete!\n");
        return -1;
    }
    struct node *ptr = front;
    int data = front->data;
    front = front->next;
    free(ptr);
    if (front == NULL)
    {
        rear = NULL;
    }
    printf("Dequeued!\n\n");
    return data;
}

int Peek()
{
    if (IsEmpty())
    {
        printf("Stack is empty!\n");
        return -1;
    }
    else
    {
        return front->data;
    }
}

void freeQueue(struct node *ptr)
{
    if (ptr->next != NULL)
    {
        freeQueue(ptr->next);
    }
    free(ptr);
}
