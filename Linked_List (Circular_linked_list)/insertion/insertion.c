#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the end of the circular linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->data = data;
    newNode->next = *head;  // New node points to the head (circular property)

    // If the list is empty, make the new node the head and point to itself
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        // Traverse to the last node
        while (temp->next != *head)
            temp = temp->next;
        temp->next = newNode;  // Link last node to the new node
    }
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
    } while (temp != head);  // Loop until we reach back to the head
    printf("(Back to head)\n");
}
