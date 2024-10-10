#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void insertEnd(struct Node** head, int data);
void deleteNode(struct Node** head, int key);
void display(struct Node* head);

int main() {
    struct Node* head = NULL;

    // Inserting nodes into the circular linked list
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    
    // Display the list
    printf("Circular Linked List: ");
    display(head);  // Output: 10 -> 20 -> 30 -> 40 -> (Back to head)

    // Deleting a node from the list
    printf("\nDeleting 30 from the list...\n");
    deleteNode(&head, 30);
    display(head);  // Output: 10 -> 20 -> 40 -> (Back to head)

    // Deleting another node
    printf("\nDeleting 10 from the list...\n");
    deleteNode(&head, 10);
    display(head);  // Output: 20 -> 40 -> (Back to head)

    return 0;
}

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
