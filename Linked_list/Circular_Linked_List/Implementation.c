#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL; // Next will be set when added to the list
    return new_node;
}

// Function to insert a new node at the end of the circular linked list
void insert_end(Node** head, int data) {
    Node* new_node = create_node(data);
    if (*head == NULL) {
        // If the list is empty, point the new node to itself
        *head = new_node;
        new_node->next = *head;
    } else {
        Node* temp = *head;
        // Traverse to the last node
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = new_node; // Link last node to new node
        new_node->next = *head; // Complete the circular link
    }
}

// Function to display the circular linked list
void display(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Function to delete a node from the circular linked list
void delete_node(Node** head, int key) {
    if (*head == NULL) return;

    Node *temp = *head, *prev = NULL;

    // If the node to be deleted is the head
    if (temp->data == key) {
        // If there is only one node in the list
        if (temp->next == *head) {
            free(temp);
            *head = NULL;
            return;
        } else {
            // Find the last node to update its next pointer
            while (temp->next != *head) {
                temp = temp->next;
            }
            temp->next = (*head)->next; // Link last node to the second node
            free(*head);
            *head = temp->next; // Update head
            return;
        }
    }

    // Traverse to find the node to delete
    while (temp->next != *head && temp->next->data != key) {
        temp = temp->next;
    }

    // If the node to be deleted was found
    if (temp->next != *head) {
        Node* node_to_delete = temp->next;
        temp->next = node_to_delete->next; // Bypass the node to delete
        free(node_to_delete);
    } else {
        printf("Node with value %d not found\n", key);
    }
}

// Function to free the circular linked list
void free_list(Node** head) {
    if (*head == NULL) return;

    Node *temp = *head, *next_node;
    do {
        next_node = temp->next;
        free(temp);
        temp = next_node;
    } while (temp != *head);
    *head = NULL; // Set head to NULL
}

// Main function to demonstrate the circular linked list operations
int main() {
    Node* head = NULL;

    // Insert nodes into the circular linked list
    insert_end(&head, 10);
    insert_end(&head, 20);
    insert_end(&head, 30);
    insert_end(&head, 40);

    // Display the list
    printf("Circular Linked List: ");
    display(head);

    // Delete a node
    printf("Deleting node with value 20\n");
    delete_node(&head, 20);
    printf("Circular Linked List after deletion: ");
    display(head);

    // Delete another node
    printf("Deleting node with value 10\n");
    delete_node(&head, 10);
    printf("Circular Linked List after deletion: ");
    display(head);

    // Free the circular linked list
    free_list(&head);
    printf("Circular Linked List after freeing: ");
    display(head); // Should show "List is empty"

    return 0;
}
