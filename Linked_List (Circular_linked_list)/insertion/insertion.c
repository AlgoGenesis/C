#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert at the beginning of the circular linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head; // Point to the current head

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head; // Single node points to itself
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) // Find the last node
            temp = temp->next;
        temp->next = newNode; // Link last node to new node
    }

    *head = newNode; // Update head to new node
}

// Function to insert at the end of the circular linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head; // Point to head (circular property)

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head; // Single node points to itself
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) // Find the last node
            temp = temp->next;
        temp->next = newNode; // Link last node to new node
    }
}

// Function to insert after a given node
void insertAfter(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = prevNode->next; // Link new node to the next of prevNode
    prevNode->next = newNode; // Link prevNode to new node
}

// Function to display the circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);  // Loop back to the head
    printf("(Back to head)\n");
}

int main() {
    struct Node* head = NULL;

    // Inserting nodes
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 10);
    insertAfter(head->next, 25); // Insert 25 after 20

    // Display the circular linked list
    printf("Circular Linked List: ");
    display(head);

    return 0;
}
