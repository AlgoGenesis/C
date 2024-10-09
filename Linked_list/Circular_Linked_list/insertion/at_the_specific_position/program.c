#include <stdio.h>
#include <stdlib.h>

// Definition of a structure to represent a node in the linked list
struct Node {
    int data;              // Integer data to store the value in the node
    struct Node* next;     // Pointer to the next node in the list
};

// Function to insert a node at a specific position in the circular linked list
void insertAtPosition(struct Node **head_ref, int new_data, int position) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    // Assign data to the new node
    new_node->data = new_data;

    // If the list is empty, insert at position 1
    if (*head_ref == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
        return;
    }

    // If inserting at the first position
    if (position == 1) {
        struct Node* temp = *head_ref;
        // Traverse to the last node to make the circular link
        while (temp->next != *head_ref) {
            temp = temp->next;
        }
        // Insert the new node at the beginning
        new_node->next = *head_ref;
        temp->next = new_node; // Update the last node's next to new node
        *head_ref = new_node;  // Update head to the new node
        return;
    }

    // Traverse to find the node just before the position
    struct Node* temp = *head_ref;
    for (int i = 1; i < position - 1 && temp->next != *head_ref; i++) {
        temp = temp->next;
    }

    // Insert the new node at the desired position
    new_node->next = temp->next;
    temp->next = new_node;
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
    //Initialize the head of the list as NULL (empty list)
    struct Node* head = NULL;

    // Insert elements at different positions in the list
    insertAtPosition(&head, 10, 1);  // Insert 10 at position 1 (list: 10 -> back to head)
    insertAtPosition(&head, 20, 2);  // Insert 20 at position 2 (list: 10 -> 20 -> back to head)
    insertAtPosition(&head, 30, 3);  // Insert 30 at position 3 (list: 10 -> 20 -> 30 -> back to head)
    insertAtPosition(&head, 40, 2);  // Insert 40 at position 2 (list: 10 -> 40 -> 20 -> 30 -> back to head)
    insertAtPosition(&head, 50, 1);  // Insert 50 at position 1 (list: 50 -> 10 -> 40 -> 20 -> 30 -> back to head)

    // Display the linked list
    display(head);

    return 0;
}
