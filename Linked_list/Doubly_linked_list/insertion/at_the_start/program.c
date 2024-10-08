#include <stdio.h>
#include <stdlib.h>

// Definition of a structure to represent a node in the doubly linked list
struct Node {
    int data;               // Integer data to store the value in the node
    struct Node* next;      // Pointer to the next node in the list
    struct Node* prev;      // Pointer to the previous node in the list
};

// Function to insert a node at the beginning of the doubly linked list
void insertAtStart(struct Node** head_ref, int new_data) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    // Assign the data to the new node
    new_node->data = new_data;
    
    // Make the new node's next pointer point to the current head
    new_node->next = *head_ref;
    
    // Make the new node's prev pointer NULL (since it's the first node)
    new_node->prev = NULL;

    // If the linked list is not empty, update the previous pointer of the current head
    if (*head_ref != NULL) {
        (*head_ref)->prev = new_node;
    }
    
    // Move the head to point to the new node
    *head_ref = new_node;
}

// Function to display the elements of the doubly linked list
void display(struct Node* ptr) {
    // Loop through the list until we reach the end (NULL)
    while (ptr != NULL) {
        // Print the data of the current node
        printf("%d <-> ", ptr->data);
        
        // Move to the next node
        ptr = ptr->next;
    }
    printf("NULL\n"); // End of the list
}

int main() {
    // Initialize the head of the list as NULL (empty list)
    struct Node* head = NULL;

    // Insert elements at the start of the list
    insertAtStart(&head, 40);  // List: 40 <-> NULL
    insertAtStart(&head, 30);  // List: 30 <-> 40 <-> NULL
    insertAtStart(&head, 20);  // List: 20 <-> 30 <-> 40 <-> NULL
    insertAtStart(&head, 10);  // List: 10 <-> 20 <-> 30 <-> 40 <-> NULL

    // Display the doubly linked list
    display(head);

    return 0; 
}
