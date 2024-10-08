#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to delete a node from the circular linked list
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = *head, *prev;

    // If the node to be deleted is the head
    if (temp->data == key && temp->next == *head) {
        *head = NULL;
        free(temp);
        return;
    }

    // If there are more than one nodes and head needs to be deleted
    if (temp->data == key) {
        while (temp->next != *head)  // Find the last node
            temp = temp->next;
        temp->next = (*head)->next;
        free(*head);
        *head = temp->next;
        return;
    }

    // Find the node to be deleted and keep track of the previous node
    while (temp->next != *head && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If node to be deleted was found
    if (temp->data == key) {
        prev->next = temp->next;
        free(temp);
    } else {
        printf("Key not found in the list\n");
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
