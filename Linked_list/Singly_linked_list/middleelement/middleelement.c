#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Global variable for the head of the linked list
struct Node *head = NULL;
// Function to insert a new node at the end of the linked list
struct Node *tail = NULL; // Global variable to keep track of the last node

void insert(int data)
{
    // Create a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // If the list is empty, make the new node the head
    if (!head)
    {
        head = newNode; // Set the new node as the head
        tail = newNode; // Update tail to the new node
    }
    else
    {
        tail->next = newNode; // Link the new node to the last node
        tail = newNode;       // Update tail to the new node
    }
}

// Function to print the linked list
void printList()
{
    struct Node *current = head;
    printf("Linked List: ");
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
void middleelement()
{
    struct Node *slow = head;
    struct Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("%d", slow->data);
}
int main()
{
    int numNodes, data;

    // Ask the user for the number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    // Loop to get user input for each node
    for (int i = 0; i < numNodes; i++)
    {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insert(data);
    }

    // Print the linked list
    printList();
    middleelement();
    return 0;
}
