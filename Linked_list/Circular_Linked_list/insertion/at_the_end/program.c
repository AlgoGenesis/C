#include <stdio.h>
#include <stdlib.h>

// Definition of a structure to represent a node in the linked list
struct Node {
    int data;              // Integer data to store the value in the node
    struct Node* next;     // Pointer to the next node in the list
};

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct Node **head_ref, int new_data) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    // Assign data to the new node
    new_node->data = new_data;

    // If the list is empty, new node becomes the head and points to itself
    if (*head_ref == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
        return;
    }

    // Traverse to the last node (node whose next points to head)
    struct Node* temp = *head_ref;
    while (temp->next != *head_ref) {
        temp = temp->next;
    }

    // Insert the new node at the end
    temp->next = new_node;
    new_node->next = *head_ref; // New node points to head
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

    // Insert elements at the end of the list
    insertAtEnd(&head, 10);  // List: 10 -> (back to head)
    insertAtEnd(&head, 20);  // List: 10 -> 20 -> (back to head)
    insertAtEnd(&head, 30);  // List: 10 -> 20 -> 30 -> (back to head)
    insertAtEnd(&head, 40);  // List: 10 -> 20 -> 30 -> 40 -> (back to head)

    // Display the linked list
    display(head);

    return 0;
}
