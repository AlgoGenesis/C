#include <stdio.h>
#include <stdlib.h>

// Definition of a structure to represent a node in the linked list
struct Node {
    int data;               // Integer data to store the value in the node
    struct Node* next;      // Pointer to the next node in the list
    struct Node* prev;      // Pointer to the previous node in the list
};

// Function to delete a node at a specific position in the linked list
void deleteAtPosition(struct Node** head_ref, int position) {
    // If the list is empty
    if (*head_ref == NULL) {
        printf("The list is empty, nothing to delete.\n");
        return;
    }

    // Store the current head node
    struct Node* temp = *head_ref;

    // If head needs to be removed
    if (position == 1) {
        *head_ref = temp->next; // Change head
        if (*head_ref != NULL) {
            (*head_ref)->prev = NULL; // Update previous pointer of new head
        }
        free(temp); // Free old head
        return;
    }

    // Find previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    // If position is more than number of nodes
    if (temp == NULL) {
        printf("Position %d is not valid.\n", position);
        return;
    }

    // Node temp is the node to be deleted
    // Store pointer to the next of the node to be deleted
    struct Node* next = temp->next;

    // Change next only if the node to be deleted is NOT the last node
    if (next != NULL) {
        next->prev = temp->prev; // Change previous pointer of the next node
    }

    // Change the previous pointer only if the node to be deleted is NOT the first node
    if (temp->prev != NULL) {
        temp->prev->next = next; // Unlink the deleted node from the list
    }

    free(temp); // Free the memory of the node to be deleted
}

// Function to display the elements of the linked list
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

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** head_ref, int new_data) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    // Assign the data to the new node
    new_node->data = new_data;
    new_node->next = NULL;

    // If the list is empty, the new node becomes the head
    if (*head_ref == NULL) {
        new_node->prev = NULL; // The new node will be the first node
        *head_ref = new_node;
        return;
    }

    // Otherwise, traverse to the end of the list
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }

    // Change the next of the last node and the prev of new node
    last->next = new_node;
    new_node->prev = last;
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
    printf("Linked List before deletion:\n");
    display(head);

    // Delete the node at position 2
    deleteAtPosition(&head, 2); // Deleting node at position 2

    // Display the linked list after deletion
    printf("Linked List after deletion at position 2:\n");
    display(head);

    return 0; 
}
