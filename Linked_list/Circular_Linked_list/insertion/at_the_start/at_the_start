#include <stdio.h>
#include <stdlib.h>

// Definition of structure to represent a node in the linked list
struct Node {
    int data;              // Integer data to store the value in the node
    struct Node* next;     // Pointer to the next node in the list
};

// Function to insert a node at the beginning of the linked list
void insertAtStart(struct Node **head_ref, int new_data) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    // Assign the data to the new node
    new_node->data = new_data;

    // Insertion at beginning if it is an empty list
    if (*head_ref == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
        return;
    }
    
    // Code for insertion at the beginning when at least 1 element is present
    // Add the new node after the head
    new_node->next = (*head_ref)->next;
    (*head_ref)->next = new_node;

    // Swap the data between head and new node to maintain the circular linked list logic
    int temp = new_node->data;
    new_node->data = (*head_ref)->data;
    (*head_ref)->data = temp;
}

// Function to display the elements of the linked list
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

    // Insert elements at the start of the list
    insertAtStart(&head, 40);  // List: 40 -> (back to head)
    insertAtStart(&head, 30);  // List: 30 -> 40 -> (back to head)
    insertAtStart(&head, 20);  // List: 20 -> 30 -> 40 -> (back to head)
    insertAtStart(&head, 10);  // List: 10 -> 20 -> 30 -> 40 -> (back to head)

    // Display the linked list
    display(head);

    return 0;
}
