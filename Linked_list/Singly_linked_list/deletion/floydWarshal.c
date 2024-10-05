#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to detect cycle using Floyd's Cycle Detection Algorithm
int detectCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return 1;  // Cycle found
    }
    return 0;  // No cycle
}

// Utility to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Example usage
int main() {
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);

    // Creating a cycle for testing
    head->next->next->next->next = head->next;

    if (detectCycle(head))
        printf("Cycle detected!\n");
    else
        printf("No cycle detected.\n");

    return 0;
}
