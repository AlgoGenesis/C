#include <stdio.h>
#include <stdlib.h>

// Definition of a structure to represent a node in the linked list
struct Node {
    int data;              // Integer data to store the value in the node
    struct Node* next;     // Pointer to the next node in the list
};

// Function to insert a node at a specified position in the circular linked list
void insertAtPosition(struct Node **head_ref, int new_data, int position) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    // If the list is empty, make the new node point to itself and set it as head
    if (*head_ref == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
        return;
    }

    // If inserting at the first position
    if (position == 1) {
        struct Node* temp = *head_ref;
        while (temp->next != *head_ref) {
            temp = temp->next;
        }
        // Insert the new node at the beginning
        new_node->next = *head_ref;
        temp->next = new_node;
        *head_ref = new_node;
        return;
    }

    // For any other position, find the correct place to insert the new node
    struct Node* current = *head_ref;
    for (int i = 1; i < position - 1 && current->next != *head_ref; i++) {
        current = current->next;
    }

    // Insert the new node in the list
    new_node->next = current->next;
    current->next = new_node;
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

int main() {
    // Initialize the head of the list as NULL (empty list)
    struct Node* head = NULL;

    // Insert elements at specific positions
    insertAtPosition(&head, 40, 1);  // List: 40 -> (back to head)
    insertAtPosition(&head, 30, 2);  // List: 40 -> 30 -> (back to head)
    insertAtPosition(&head, 20, 2);  // List: 40 -> 20 -> 30 -> (back to head)
    insertAtPosition(&head, 10, 1);  // List: 10 -> 40 -> 20 -> 30 -> (back to head)

    // Display the linked list
    printf("Circular Linked List after insertions at specified positions:\n");
    display(head);

    return 0;
}
