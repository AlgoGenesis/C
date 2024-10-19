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

// Function to insert a node at a specific position
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode; // If the list is empty, set head to the new node
        return;
    }

    struct Node* current = *head;

    // Traverse to the position
    for (int i = 1; i < position - 1 && current->next != *head; i++) {
        current = current->next;
    }

    // Insert the new node at the desired position
    struct Node* nextNode = current->next;

    current->next = newNode;
    newNode->prev = current;
    newNode->next = nextNode;
    nextNode->prev = newNode;

    // If inserting at the head position
    if (position == 1) {
        *head = newNode;
    }
}

//Function to delete the node at beginning
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* tail = (*head)->prev;
    struct Node* temp = *head;

    // If there's only one node
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
    } else {
        struct Node* nextNode = (*head)->next;

        // Update tail and nextNode's pointers
        tail->next = nextNode;
        nextNode->prev = tail;

        // Free the old head and update the new head
        free(temp);
        *head = nextNode;
    }
}

//Function to delete a node at end
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* tail = (*head)->prev;

    // If there's only one node
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
    } else {
        struct Node* prevNode = tail->prev;

        // Update the previous node's next pointer and head's prev pointer
        prevNode->next = *head;
        (*head)->prev = prevNode;

        // Free the tail
        free(tail);
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
    insertAtBeginning(&head, 50);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    printf("List after insertion (forward): ");
    traverseForward(head);

    printf("List after insertion (backward): ");
    traverseBackward(head);

    // Insert at position
    insertAtPosition(&head, 25, 3);  // Insert 25 at position 3
    printf("List after inserting 25 at position 3 (forward): ");
    traverseForward(head);

    //Delete at beginning
    deleteAtBeginning(&head);
    printf("List after deleting node at beginning (forward): ");
    traverseForward(head);
    
    // Deleting a node
    deleteNode(&head, 20);
    printf("List after deleting 20 (forward): ");
    traverseForward(head);

    deleteNode(&head, 40);
    printf("List after deleting 40 (forward): ");
    traverseForward(head);

    // Deleting the last node
    deleteAtEnd(&head);
    printf("List after deleting node at end (forward): ");
    traverseForward(head);

    // Deleting a non-existent node
    deleteNode(&head, 60);

    return 0;
}
