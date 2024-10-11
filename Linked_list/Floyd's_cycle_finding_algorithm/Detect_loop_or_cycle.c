#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a linked list node
struct Node {
    int data;              // Data part of the node
    struct Node* next;     // Pointer to the next node
};

// Function to detect a loop in the linked list
bool detectLoop(struct Node* head) {
    // Initialize two pointers, slow and fast
    struct Node *slow = head;  // Slow pointer moves one step
    struct Node *fast = head;  // Fast pointer moves two steps

    // Loop until we reach the end of the list
    while (slow != NULL && fast != NULL && fast->next != NULL) {
        slow = slow->next;           // Move slow one step
        fast = fast->next->next;     // Move fast two steps

        // If slow and fast meet, there is a loop
        if (slow == fast) {
            return true; // Loop detected
        }
    }
    return false; // No loop
}

// Function to create a new linked list node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory
    newNode->data = data; // Set node data
    newNode->next = NULL; // Initialize next pointer to NULL
    return newNode;
}

int main() {
    // Create a linked list: 10 -> 20 -> 30 -> 40 -> 50 -> 60
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);
    head->next->next->next->next->next = createNode(60);

    // Create a loop for testing (linking the last node back to the third node)
    head->next->next->next->next->next->next = head->next->next; // Creating a loop

    // Check for loop in the linked list and print the result
    if (detectLoop(head))
        printf("Loop detected\n");
    else
        printf("No loop detected\n");

    return 0; // End of the program
}

