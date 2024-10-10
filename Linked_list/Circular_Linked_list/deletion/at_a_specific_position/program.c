#include <stdio.h>
#include <stdlib.h>

// Definition of a structure to represent a node in the linked list
struct Node {
    int data;              // Integer data to store the value in the node
    struct Node* next;     // Pointer to the next node in the list
};

// Function to delete a node at a specified position in the circular linked list
void deleteAtPosition(struct Node **head_ref, int position) {
    // If the list is empty, return
    if (*head_ref == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    // Get a reference to the head
    struct Node* current = *head_ref;
    
    // If the position is 1, delete the first node (special case)
    if (position == 1) {
        // If there is only one node in the list
        if (current->next == *head_ref) {
            free(current);  // Free the only node
            *head_ref = NULL; // Set head to NULL
        } else {
            // Otherwise, traverse to the last node to maintain the circular structure
            struct Node* last = *head_ref;
            while (last->next != *head_ref) {
                last = last->next;
            }
            // Point the last node's next to the second node
            last->next = current->next;
            *head_ref = current->next; // Update head to the second node
            free(current); // Free the old head node
        }
        return;
    }

    // Traverse the list to find the node before the one to be deleted
    struct Node* prev = NULL;
    int count = 1;
    while (count < position && current->next != *head_ref) {
        prev = current;
        current = current->next;
        count++;
    }

    // If the position is beyond the length of the list, print a message
    if (count != position) {
        printf("Position %d is out of bounds. No deletion occurred.\n", position);
        return;
    }

    // Unlink the node from the list
    prev->next = current->next;
    free(current); // Free the node to be deleted
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

    // Delete the node at position 3
    printf("\nDeleting node at position 3...\n");
    deleteAtPosition(&head, 3);

    // Display the list after deletion
    printf("List after deletion at position 3:\n");
    display(head);

    // Delete the node at position 1 (head)
    printf("\nDeleting node at position 1...\n");
    deleteAtPosition(&head, 1);

    // Display the list after deletion at the head
    printf("List after deletion at position 1:\n");
    display(head);

    return 0;
}
