#include <stdio.h>
#include <stdlib.h>

// Definition of a structure to represent a node in the linked list
struct Node {
    int data;              // Integer data to store the value in the node
    struct Node* next;     // Pointer to the next node in the list
};

// Function to insert a node at the beginning of the circular linked list
void insertAtStart(struct Node **head_ref, int new_data) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    // Assign the data to the new node
    new_node->data = new_data;

    // If the list is empty, make the new node point to itself and set it as head
    if (*head_ref == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
    } else {
        // If the list is not empty
        struct Node* temp = *head_ref;
        
        // Traverse to the last node to maintain the circular structure
        while (temp->next != *head_ref) {
            temp = temp->next;
        }

        // Make the new node point to the current head
        new_node->next = *head_ref;

        // Update the last node's next to point to the new node (new head)
        temp->next = new_node;

        // Update the head to the new node
        *head_ref = new_node;
    }
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

    // Insert elements at the beginning of the list
    insertAtStart(&head, 40);  // List: 40 -> (back to head)
    insertAtStart(&head, 30);  // List: 30 -> 40 -> (back to head)
    insertAtStart(&head, 20);  // List: 20 -> 30 -> 40 -> (back to head)
    insertAtStart(&head, 10);  // List: 10 -> 20 -> 30 -> 40 -> (back to head)

    // Display the linked list
    printf("Circular Linked List after insertions at the beginning:\n");
    display(head);

    return 0;
}
