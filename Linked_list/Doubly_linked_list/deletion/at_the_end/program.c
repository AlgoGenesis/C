#include <stdio.h>
#include <stdlib.h>

// Definition of a structure to represent a node in the doubly linked list
struct Node {
    int data;              // Integer data to store the value in the node
    struct Node* next;     // Pointer to the next node in the list
    struct Node* prev;     // Pointer to the previous node in the list
};

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(struct Node** head_ref, int new_data) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    // Assign the data to the new node
    new_node->data = new_data;
    
    // New node will be the last, so set its next to NULL
    new_node->next = NULL;

    // If the linked list is empty, make the new node the head
    if (*head_ref == NULL) {
        new_node->prev = NULL;  // Previous pointer of the first node is NULL
        *head_ref = new_node;
        return;
    }

    // Otherwise, traverse to the last node
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }

    // Make the last node's next point to the new node
    last->next = new_node;
    new_node->prev = last;  // Set the new node's previous pointer to last node
}

// Function to delete a node at the end of the doubly linked list
void deleteAtEnd(struct Node** head_ref) {
    // If the list is empty
    if (*head_ref == NULL) {
        printf("The list is empty, nothing to delete.\n");
        return;
    }

    // If the list contains only one node
    if ((*head_ref)->next == NULL) {
        free(*head_ref);  // Free the only node
        *head_ref = NULL; // Set head to NULL
        return;
    }

    // Traverse to the last node
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }

    // Update the second last node's next pointer to NULL
    last->prev->next = NULL;

    // Free the last node
    free(last);
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

    // Insert elements to create a list
    insertAtEnd(&head, 10);  // List: 10 <-> NULL
    insertAtEnd(&head, 20);  // List: 10 <-> 20 <-> NULL
    insertAtEnd(&head, 30);  // List: 10 <-> 20 <-> 30 <-> NULL
    insertAtEnd(&head, 40);  // List: 10 <-> 20 <-> 30 <-> 40 <-> NULL

    // Display the linked list before deletion
    printf("Doubly Linked List before deletion:\n");
    display(head);

    // Delete the last node
    deleteAtEnd(&head);

    // Display the linked list after deletion
    printf("Doubly Linked List after deletion:\n");
    display(head);

    return 0;
}
