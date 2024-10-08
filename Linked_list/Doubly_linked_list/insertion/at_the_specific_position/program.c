#include <stdio.h>
#include <stdlib.h>

// Definition of a structure to represent a node in the doubly linked list
struct Node {
    int data;              // Integer data to store the value in the node
    struct Node* next;     // Pointer to the next node in the list
    struct Node* prev;     // Pointer to the previous node in the list
};

// Function to insert a node at a specific position in the doubly linked list
void insertAtPosition(struct Node** head_ref, int new_data, int position) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    // Assign the data to the new node
    new_node->data = new_data;
    new_node->next = NULL;
    new_node->prev = NULL;

    // Handle case when inserting at the head (position 1)
    if (position == 1) {
        new_node->next = *head_ref; // Make next of new node as head
        if (*head_ref != NULL) {
            (*head_ref)->prev = new_node; // Change prev of head to new node
        }
        *head_ref = new_node; // Move the head to point to the new node
        return;
    }

    // Traverse the list to find the node before the desired position
    struct Node* temp = *head_ref;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // Check if the position is valid
    if (temp == NULL) {
        printf("Position %d is out of range\n", position);
        free(new_node); // Free allocated memory
        return;
    }

    // Insert the new node at the desired position
    new_node->next = temp->next; // Make next of new node as next of temp
    new_node->prev = temp; // Link previous of new node to temp
    temp->next = new_node; // Link temp's next to the new node

    // If the new node is not inserted at the end, link the next node's prev to the new node
    if (new_node->next != NULL) {
        new_node->next->prev = new_node; // Change the next node's prev to the new node
    }
}

// Function to display the elements of the doubly linked list
void display(struct Node* node) {
    // Loop through the list until we reach the end (NULL)
    while (node != NULL) {
        // Print the data of the current node
        printf("%d <-> ", node->data);
        
        // Move to the next node
        node = node->next;
    }
    printf("NULL\n"); // End of the list
}

int main() {
    // Initialize the head of the list as NULL (empty list)
    struct Node* head = NULL;

    // Insert elements at specific positions in the list
    insertAtPosition(&head, 10, 1);  // List: 10 <-> NULL
    insertAtPosition(&head, 20, 2);  // List: 10 <-> 20 <-> NULL
    insertAtPosition(&head, 15, 2);  // List: 10 <-> 15 <-> 20 <-> NULL
    insertAtPosition(&head, 5, 1);   // List: 5 <-> 10 <-> 15 <-> 20 <-> NULL
    insertAtPosition(&head, 25, 5);  // List: 5 <-> 10 <-> 15 <-> 20 <-> 25 <-> NULL
    insertAtPosition(&head, 30, 2);  // List: 5 <-> 30 <-> 10 <-> 15 <-> 20 <-> 25 <-> NULL

    // Display the doubly linked list
    display(head);

    return 0;  
}
