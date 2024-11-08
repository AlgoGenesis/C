#include <stdio.h>
#include <stdlib.h>

// Definition of the linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to detect cycle in the linked list
int detectCycle(struct Node* head) {
    struct Node* slow = head; // Tortoise
    struct Node* fast = head; // Hare

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // Move tortoise by one step
        fast = fast->next->next;   // Move hare by two steps

        if (slow == fast) {        // Cycle detected
            return 1;              // There is a cycle
        }
    }
    return 0;                      // No cycle
}

// Main function to test the cycle detection
int main() {
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = head->next; // Create a cycle for testing

    if (detectCycle(head)) {
        printf("Cycle detected\n");
    } else {
        printf("No cycle detected\n");
    }

    // Note: In a real scenario, you should free the memory
    // and handle cycles properly to avoid infinite loops.

    return 0;
}
