#include <stdio.h>
#include <stdlib.h>

// Definition of a node in a circular singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode; // Pointing to itself
    return newNode;
}

// Function to insert a new node at the end of the list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    newNode->next = *head; // Making it circular
}

// Function to insert a new node at the beginning of the list
void insertBegin(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    newNode->next = *head; // Making it circular
    *head = newNode; // Updating head to new node
}

// Function to delete a node by value
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *current = *head, *previous = NULL;

    // If head needs to be deleted
    if (current->data == key) {
        // If there's only one node
        if (current->next == *head) {
            free(current);
            *head = NULL;
            return;
        } else {
            previous = *head;
            while (previous->next != *head) {
                previous = previous->next;
            }
            previous->next = current->next;
            *head = current->next; // Move head to next node
            free(current);
            return;
        }
    }

    // Searching for the key in the list
    do {
        previous = current;
        current = current->next;
        if (current->data == key) {
            previous->next = current->next;
            free(current);
            return;
        }
    } while (current != *head);

    printf("Node with value %d not found.\n", key);
}

// Function to traverse and display the list
void traverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// Function to search for a node by value
int search(struct Node* head, int key) {
    if (head == NULL) {
        return 0;
    }
    struct Node* temp = head;
    do {
        if (temp->data == key) {
            return 1; // Found
        }
        temp = temp->next;
    } while (temp != head);
    return 0; // Not found
}

// Main function to demonstrate circular linked list operations
int main() {
    struct Node* head = NULL;
    int choice, value;

    do {
        printf("\nCircular Singly Linked List Operations:\n");
        printf("1. Insert at End\n");
        printf("2. Insert at Beginning\n");
        printf("3. Delete Node\n");
        printf("4. Traverse List\n");
        printf("5. Search Node\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;
            case 2:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertBegin(&head, value);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 4:
                traverse(head);
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(head, value)) {
                    printf("Node with value %d found.\n", value);
                } else {
                    printf("Node with value %d not found.\n", value);
                }
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 6);

    return 0;
}
