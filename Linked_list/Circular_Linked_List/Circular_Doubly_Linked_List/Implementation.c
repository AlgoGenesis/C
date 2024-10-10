#include <stdio.h>
#include <stdlib.h>

// Node structure for circular doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode; // Point to itself
    newNode->prev = newNode; // Point to itself
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode; // If the list is empty, set head to the new node
    } else {
        struct Node* tail = (*head)->prev;

        // Update pointers for the new node
        newNode->next = *head;
        newNode->prev = tail;

        // Adjust the old head and tail
        tail->next = newNode;
        (*head)->prev = newNode;

        // Update head
        *head = newNode;
    }
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode; // If the list is empty, set head to the new node
    } else {
        struct Node* tail = (*head)->prev;

        // Update pointers for the new node
        newNode->next = *head;
        newNode->prev = tail;

        // Adjust the old tail and head
        tail->next = newNode;
        (*head)->prev = newNode;
    }
}

// Function to delete a node by value
void deleteNode(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = *head;

    do {
        if (current->data == value) {
            // If node is found, adjust pointers
            if (current->next == current) {
                // Only one node in the list
                free(current);
                *head = NULL;
            } else {
                struct Node* prevNode = current->prev;
                struct Node* nextNode = current->next;

                prevNode->next = nextNode;
                nextNode->prev = prevNode;

                // If the deleted node is the head, move head pointer
                if (current == *head) {
                    *head = nextNode;
                }

                free(current);
            }
            return;
        }
        current = current->next;
    } while (current != *head);

    printf("Node with value %d not found.\n", value);
}

// Function to traverse the list in forward direction
void traverseForward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

// Function to traverse the list in backward direction
void traverseBackward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* tail = head->prev;
    struct Node* current = tail;
    do {
        printf("%d ", current->data);
        current = current->prev;
    } while (current != tail);
    printf("\n");
}

// Main function to demonstrate operations on Circular Doubly Linked List
int main() {
    struct Node* head = NULL;

    // Inserting nodes
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    printf("List after insertion (forward): ");
    traverseForward(head);

    printf("List after insertion (backward): ");
    traverseBackward(head);

    // Deleting a node
    deleteNode(&head, 20);
    printf("List after deleting 20 (forward): ");
    traverseForward(head);

    deleteNode(&head, 40);
    printf("List after deleting 40 (forward): ");
    traverseForward(head);

    // Deleting a non-existent node
    deleteNode(&head, 50);

    return 0;
}
