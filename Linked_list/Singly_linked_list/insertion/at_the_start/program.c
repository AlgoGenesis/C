// Implementing a program to insert a node at the beginning of a singly linked list

#include <stdio.h>
#include <stdlib.h>

// Definition of a structure to represent a node in the linked list
struct Node {
    int data;              // Integer data to store the value in the node
    struct Node* next;     // Pointer to the next node in the list
};

// Function to insert a node at the beginning of the linked list
void insertAtStart(struct Node** head_ref, int new_data) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    // Assign the data to the new node
    new_node->data = new_data;

    // Make the new node point to the current head of the list
    new_node->next = *head_ref;

    // Move the head to point to the new node
    *head_ref = new_node;
}

// Function to display the elements of the linked list
void display(struct Node* ptr) {
    // Loop through the list until we reach the end (NULL)
    while (ptr != NULL) {
        // Print the data of the current node
        printf("%d -> ", ptr->data);
        
        // Move to the next node
        ptr = ptr->next;
    }
    printf("NULL\n"); // End of the list
}

int main() {
    // Initialize the head of the list as NULL (empty list)
    struct Node* head = NULL;

    // Insert elements at the start of the list
    insertAtStart(&head, 40);  // List: 40 -> NULL
    insertAtStart(&head, 30);  // List: 30 -> 40 -> NULL
    insertAtStart(&head, 20);  // List: 20 -> 30 -> 40 -> NULL
    insertAtStart(&head, 10);  // List: 10 -> 20 -> 30 -> 40 -> NULL

    // Display the linked list
    display(head);

    return 0; 
}