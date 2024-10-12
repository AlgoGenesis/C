#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to detect a cycle in the linked list using the Hare and Tortoise algorithm
int detectCycle(struct Node* head) {
    if (head == NULL) return 0; // No cycle if the list is empty

    struct Node* tortoise = head;
    struct Node* hare = head;

    while (hare != NULL && hare->next != NULL) {
        tortoise = tortoise->next;           // Move tortoise by 1 step
        hare = hare->next->next;             // Move hare by 2 steps

        if (tortoise == hare) {               // Cycle detected
            return 1;
        }
    }

    return 0; // No cycle detected
}

// Function to free the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function to demonstrate cycle detection
int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // Create a cycle for testing (5 -> 3)
    head->next->next->next->next->next = head->next->next;

    // Detect cycle
    if (detectCycle(head)) {
        printf("Cycle detected in the linked list.\n");
    } else {
        printf("No cycle detected in the linked list.\n");
    }

    // Free the linked list (not fully correct due to the cycle, but for demonstration)
    freeList(head);

    return 0;
}
