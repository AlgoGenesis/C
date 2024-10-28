#include <stdio.h>   // Include the standard input/output library for printf
#include <stdlib.h>  // Include the standard library for malloc and free functions

// Function to display the elements of the doubly linked list
void display(struct Node* head);

// Definition of a structure to represent a node in the doubly linked list
struct Node {
    int data;              // Integer data to store the value in the node
    struct Node* next;     // Pointer to the next node in the list
    struct Node* prev;     // Pointer to the previous node in the list
};

int main()
{
    // Pointers to the nodes in the linked list
    struct Node* first;    
    struct Node* second;
    struct Node* third;
    struct Node* fourth;

    // Allocate memory for four nodes in the linked list
    first = (struct Node*)malloc(sizeof(struct Node));    // First node
    second = (struct Node*)malloc(sizeof(struct Node));   // Second node
    third = (struct Node*)malloc(sizeof(struct Node));    // Third node
    fourth = (struct Node*)malloc(sizeof(struct Node));   // Fourth node

    // Assign data to each node
    first->data = 5;       // Assign 5 to the first node
    second->data = 10;     // Assign 10 to the second node
    third->data = 15;      // Assign 15 to the third node
    fourth->data = 20;     // Assign 20 to the fourth node

    // Link the nodes to each other to form the doubly linked list
    first->next = second;  // First node points to second
    first->prev = NULL;    // First node's prev points to NULL (start of the list)

    second->next = third;  // Second node points to third
    second->prev = first;  // Second node's prev points to first

    third->next = fourth;  // Third node points to fourth
    third->prev = second;  // Third node's prev points to second

    fourth->next = NULL;   // Fourth node is the last, so it points to NULL
    fourth->prev = third;  // Fourth node's prev points to third

    // Call the display function to print the linked list
    display(first);

    return 0;  // Return 0 to indicate successful execution
}

// Function to display the elements of the doubly linked list
void display(struct Node* ptr)
{
    // Loop through the list until we reach the end (NULL)
    while (ptr != NULL) {
        // Print the data of the current node
        printf(" %d ", ptr->data);
        
        // Move to the next node
        ptr = ptr->next;
    }
    printf("\n");  // Move to a new line after the list is displayed
}
