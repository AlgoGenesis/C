#include <stdio.h>
#include <stdlib.h>

// Definition for a node in the linked list
struct ListNode {
    int value;
    struct ListNode* next;
};

// Function to create a new node with given value
struct ListNode* createListNode(int value);

// Recursive function to add one to the linked list and return any carry
int incrementWithCarry(struct ListNode* node) {
    // Base case: if the list is empty, return carry (1)
    if (node == NULL) {
        return 1;
    }

    // Add the carry from the next node to the current node's value
    int total = node->value + incrementWithCarry(node->next);

    // Update the current node's value and return new carry
    node->value = total % 10;
    return total / 10;  // Carry for the previous node
}

// Function to add one to the entire linked list
struct ListNode* addOneToLinkedList(struct ListNode* head) {
    // Increment the list from the last node and capture the carry
    int carry = incrementWithCarry(head);

    // If there's still a carry after processing all nodes,
    // create a new node to represent the carry
    if (carry) {
        struct ListNode* newNode = createListNode(carry);
        newNode->next = head;  // Link the new node to the current head
        return newNode;  // New node becomes the new head
    }

    return head;  // Return unchanged head if no carry
}

// Function to print the values in the linked list
void displayList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

// Function to create a new linked list node
struct ListNode* createListNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Main function to demonstrate adding one to a linked list
int main() {
    // Creating a sample linked list: 3 -> 9 -> 9
    struct ListNode* head = createListNode(3);
    head->next = createListNode(9);
    head->next->next = createListNode(9);

    // Add one to the linked list
    head = addOneToLinkedList(head);

    // Display the updated linked list
    displayList(head);

    return 0;
}
