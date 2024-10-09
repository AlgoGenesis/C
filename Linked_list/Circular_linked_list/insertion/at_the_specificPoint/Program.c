#include <stdio.h>
#include <stdlib.h>

// Definition of a structure to represent a node in the circular linked list
struct Node {
    int data;               // Integer data to store the value in the node
    struct Node* next;      // Pointer to the next node in the list
};

// Function to insert a node at a specific position in the circular linked list
void insertAtPosition(struct Node** head_ref, int new_data, int position) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    // If the linked list is empty or inserting at the start (position 0)
    if (*head_ref == NULL || position == 0) {
        if (*head_ref == NULL) {
            *head_ref = new_node;
            new_node->next = new_node; // Point to itself (circular)
        } else {
            struct Node* last = *head_ref;
            while (last->next != *head_ref) {
                last = last->next;
            }
            last->next = new_node;
            new_node->next = *head_ref; // New node points to head
            *head_ref = new_node;       // Update head to new node
        }
        return;
    }

    // Traverse to the desired position
    struct Node* current = *head_ref;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
        if (current == *head_ref) {
            printf("Position out of bounds, inserting at the end.\n");
            break; // Position is out of bounds, will insert at end
        }
    }

    // Insert new node at the current position
    new_node->next = current->next;
    current->next = new_node;
}

// Function to display the elements of the circular linked list
void display(struct Node* head) {
    // If the list is empty
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* ptr = head;
    do {
        // Print the data of the current node
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head); // Loop until we reach the head again

    printf("(head)\n"); // Indicate the circular nature
}

int main() {
    // Initialize the head of the list as NULL (empty list)
    struct Node* head = NULL;

    // Insert elements at specific positions
    insertAtPosition(&head, 10, 0);  // List: 10 -> (head)
    insertAtPosition(&head, 20, 1);  // List: 10 -> 20 -> (head)
    insertAtPosition(&head, 30, 1);  // List: 10 -> 30 -> 20 -> (head)
    insertAtPosition(&head, 40, 2);  // List: 10 -> 30 -> 40 -> 20 -> (head)

    // Display the circular linked list
    printf("Circular Linked List:\n");
    display(head);

    return 0;
}
