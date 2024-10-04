#include <stdio.h>   // Include the standard input/output library for printf
#include <stdlib.h>  // Include the standard library for malloc and free functions

// Function to display the elements of the singly linked list
void display(); 

// Definition of a structure to represent a node in the linked list
struct Node {
    int data;              // Integer data to store the value in the node
    struct Node* next;     // Pointer to the next node in the list
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
    first->data = 5;     // Assign 10 to the first node
    second->data = 10;    // Assign 20 to the second node
    third->data = 15;     // Assign 30 to the third node
    fourth->data = 20;    // Assign 40 to the fourth node

    // Link the nodes to each other to form the linked list
    first->next = second;   // First node points to second
    second->next = third;   // Second node points to third
    third->next = fourth;   // Third node points to fourth
    fourth->next = NULL;    // Fourth node is the last, so it points to NULL

    // Call the display function to print the linked list
    display(first);

    return 0;  // Return 0 to indicate successful execution
}

// Function to display the elements of the linked list
void display(struct Node* ptr)
{
    // Loop through the list until we reach the end (NULL)
    while (ptr != NULL) {
        // Print the data of the current node
        printf(" %d ", ptr->data);
        
        // Move to the next node
        ptr = ptr->next;
    }
}
