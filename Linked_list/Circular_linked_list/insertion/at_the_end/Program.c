#include <stdio.h>
#include <stdlib.h>

// Definition of a structure to represent a node in the circular linked list
struct Node {
    int data;               // Integer data to store the value in the node
    struct Node* next;      // Pointer to the next node in the list
};

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct Node** head_ref, int new_data) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    // Assign the data to the new node
    new_node->data = new_data;
    new_node->next = NULL;  // Initialize next pointer

    // If the linked list is empty, make the new node the head
    if (*head_ref == NULL) {
        *head_ref = new_node; // New node becomes head
        new_node->next = new_node; // Point to itself (circular)
        return;
    }

    // If the list is not empty, traverse to the last node
    struct Node* last = *head_ref;
    while (last->next != *head_ref) {
        last = last->next;
    }

    // Make the last node's next point to the new node
    last->next = new_node;
    new_node->next = *head_ref; // New node points to head
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

    // Insert elements to create a circular linked list
    insertAtEnd(&head, 10);  // List: 10 -> (head)
    insertAtEnd(&head, 20);  // List: 10 -> 20 -> (head)
    insertAtEnd(&head, 30);  // List: 10 -> 20 -> 30 -> (head)
    insertAtEnd(&head, 40);  // List: 10 -> 20 -> 30 -> 40 -> (head)

    // Display the circular linked list
    printf("Circular Linked List:\n");
    display(head);

    return 0;
}
