#include <stdio.h>
#include <stdlib.h>

// Definition of a structure to represent a node in the linked list
struct Node {
    int data;              // Integer data to store the value in the node
    struct Node* next;     // Pointer to the next node in the list
};

// Function to delete a node from the end of the circular linked list
void deleteFromEnd(struct Node **head_ref) {
    // If the list is empty, return
    if (*head_ref == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    // If the list has only one node
    if ((*head_ref)->next == *head_ref) {
        free(*head_ref);  // Free the only node
        *head_ref = NULL; // Set head to NULL
        return;
    }

    // Otherwise, there are multiple nodes
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    // Traverse to find the second last node
    while (temp->next != *head_ref) {
        prev = temp; // Keep track of the second-last node
        temp = temp->next;
    }

    // `temp` is the last node and `prev` is the second-last node
    prev->next = *head_ref; // Update the second-last node's next to point to head
    free(temp);             // Free the last node
}

// Function to display the elements of the circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* cur = head;
    do {
        printf("%d -> ", cur->data);
        cur = cur->next;
    } while (cur != head);
    printf("(Back to head)\n");
}

// Helper function to insert nodes at the end of the list
void insertAtEnd(struct Node **head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    if (*head_ref == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
        return;
    }

    struct Node* temp = *head_ref;
    while (temp->next != *head_ref) {
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->next = *head_ref;
}

int main() {
    // Initialize the head of the list as NULL (empty list)
    struct Node* head = NULL;

    // Insert elements into the list
    insertAtEnd(&head, 10);  // List: 10 -> (back to head)
    insertAtEnd(&head, 20);  // List: 10 -> 20 -> (back to head)
    insertAtEnd(&head, 30);  // List: 10 -> 20 -> 30 -> (back to head)
    insertAtEnd(&head, 40);  // List: 10 -> 20 -> 30 -> 40 -> (back to head)

    // Display the list before deletion
    printf("Original List:\n");
    display(head);

    // Delete from the end of the list
    printf("\nDeleting from the end...\n");
    deleteFromEnd(&head);

    // Display the list after deletion
    printf("List after deletion from the end:\n");
    display(head);

    return 0;
}
