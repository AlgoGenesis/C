// Implement Dequeue Using Doubly Linked List

#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Deque structure
typedef struct
{
    Node *front;
    Node *rear;
} Deque;

// Function to initialize the deque
void initializeDeque(Deque *deque)
{
    deque->front = NULL;
    deque->rear = NULL;
}

// Function to check if the deque is empty
int isEmpty(Deque *deque)
{
    return deque->front == NULL;
}

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert an element at the front of the deque
void insertFront(Deque *deque, int data)
{
    Node *newNode = createNode(data);

    if (isEmpty(deque))
    {
        deque->front = newNode;
        deque->rear = newNode;
    }
    else
    {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
    printf("Inserted %d at the front\n", data);
}

// Function to insert an element at the rear of the deque
void insertRear(Deque *deque, int data)
{
    Node *newNode = createNode(data);

    if (isEmpty(deque))
    {
        deque->front = newNode;
        deque->rear = newNode;
    }
    else
    {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
    printf("Inserted %d at the rear\n", data);
}

// Function to delete an element from the front of the deque
int deleteFront(Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Error: Deque is empty\n");
        return -1;
    }

    int data = deque->front->data;
    Node *temp = deque->front;

    if (deque->front == deque->rear)
    {
        deque->front = NULL;
        deque->rear = NULL;
    }
    else
    {
        deque->front = deque->front->next;
        deque->front->prev = NULL;
    }

    free(temp);
    printf("Deleted %d from the front\n", data);
    return data;
}

// Function to delete an element from the rear of the deque
int deleteRear(Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Error: Deque is empty\n");
        return -1;
    }

    int data = deque->rear->data;
    Node *temp = deque->rear;

    if (deque->front == deque->rear)
    {
        deque->front = NULL;
        deque->rear = NULL;
    }
    else
    {
        deque->rear = deque->rear->prev;
        deque->rear->next = NULL;
    }

    free(temp);
    printf("Deleted %d from the rear\n", data);
    return data;
}

// Function to display the deque from front to rear
void display(Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque (Front to Rear): ");
    Node *temp = deque->front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free the allocated memory
void destroyDeque(Deque *deque)
{
    Node *temp = deque->front;
    while (temp != NULL)
    {
        Node *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    deque->front = NULL;
    deque->rear = NULL;
}

int main()
{
    Deque deque;
    initializeDeque(&deque);
    int choice, data;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert at the front: ");
            scanf("%d", &data);
            insertFront(&deque, data);
            break;
        case 2:
            printf("Enter data to insert at the rear: ");
            scanf("%d", &data);
            insertRear(&deque, data);
            break;
        case 3:
            deleteFront(&deque);
            break;
        case 4:
            deleteRear(&deque);
            break;
        case 5:
            display(&deque);
            break;
        case 6:
            destroyDeque(&deque);
            printf("Exiting...\n");
            exit(0);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
