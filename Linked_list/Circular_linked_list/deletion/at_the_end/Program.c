#include <stdio.h>
#include <stdlib.h>

// Definition of a structure to represent a node in the circular linked list
struct Node {
    int data;               // Integer data to store the value in the node
    struct Node* next;      // Pointer to the next node in the list
};

// Function to delete a node at the start of the circular linked list
void deleteAtStart(struct Node** head_ref) {
    // If the list is empty
    if (*head_ref == NULL) {
        printf("The list is empty, nothing to delete.\n");
        return;
    }

    struct Node* to_delete = *head_ref;

    // If the list contains only one node
    if (to_delete->next == *head_ref) {
        free(to_delete);
        *head_ref = NULL;
        return;
    }

    // Traverse to find the last node
    struct Node* last = *head_ref;
    while (last->next != *head_ref) {
        last = last->next;
    }

    // Update the last node's next to point to the second node
    *head_ref = (*head_ref)->next; // Update head
    last->next = *head_ref; // Link last to new head
    free(to_delete); // Free memory
}

// Function to display the elements of the circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* ptr = head;
    do {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);

    printf("(head)\n");
}

int main() {
    struct Node* head = NULL;

    // Create a circular linked list for demonstration
    // Insert nodes manually for this example
    // Assume insert functions are implemented here

    // Display the list
    printf("Circular Linked List:\n");
    display(head);

    // Delete node at the start
    deleteAtStart(&head);

    // Display the list after deletion
    printf("Circular Linked List after deletion at start:\n");
    display(head);

    return 0;
}
