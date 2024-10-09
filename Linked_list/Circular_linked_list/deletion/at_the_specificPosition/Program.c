#include <stdio.h>
#include <stdlib.h>

// Definition of a structure to represent a node in the circular linked list
struct Node {
    int data;               // Integer data to store the value in the node
    struct Node* next;      // Pointer to the next node in the list
};

// Function to delete a node at the end of the circular linked list
void deleteAtEnd(struct Node** head_ref) {
    // If the list is empty
    if (*head_ref == NULL) {
        printf("The list is empty, nothing to delete.\n");
        return;
    }

    struct Node* last = *head_ref;
    struct Node* second_last = NULL;

    // If the list contains only one node
    if (last->next == *head_ref) {
        free(last);
        *head_ref = NULL;
        return;
    }

    // Traverse to the last node
    while (last->next != *head_ref) {
        second_last = last;
        last = last->next;
    }

    // Update the second last node's next to point to head
    second_last->next = *head_ref;
    free(last); // Free memory
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
    // Assume insert functions are implemented here

    // Display the list
    printf("Circular Linked List:\n");
    display(head);

    // Delete node at the end
    deleteAtEnd(&head);

    // Display the list after deletion
    printf("Circular Linked List after deletion at end:\n");
    display(head);

    return 0;
}
