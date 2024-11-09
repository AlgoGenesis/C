#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to add a new node at the end of the list
struct ListNode* addNode(struct ListNode* head, int val) {
    if (head == NULL) return createNode(val);
    struct ListNode* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = createNode(val);
    return head;
}

// Function to convert linked list to array
int* linkedListToArray(struct ListNode* head, int* size) {
    int* values = (int*)malloc(10000 * sizeof(int));  // Allocate large array for simplicity
    *size = 0;
    while (head != NULL) {
        values[(*size)++] = head->val;
        head = head->next;
    }
    return values;
}

// Function to find the next greater node values
int* nextLargerNodes(struct ListNode* head, int* returnSize) {
    int size;
    int* values = linkedListToArray(head, &size);  // Convert linked list to array
    *returnSize = size;
    
    int* result = (int*)calloc(size, sizeof(int));  // Initialize result array with 0
    int* stack = (int*)malloc(size * sizeof(int));
    int top = -1;  // Stack pointer to store indices

    // Traverse the array to find the next greater element for each node
    for (int i = 0; i < size; ++i) {
        while (top >= 0 && values[i] > values[stack[top]]) {
            result[stack[top]] = values[i];
            top--;
        }
        stack[++top] = i;
    }

    // Clean up
    free(values);
    free(stack);
    return result;
}

// Function to print the result array
void printArray(int* array, int size) {
    printf("Next greater nodes: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    struct ListNode* head = NULL;
    head = addNode(head, 2);
    head = addNode(head, 1);
    head = addNode(head, 5);

    int resultSize;
    int* result = nextLargerNodes(head, &resultSize);

    printArray(result, resultSize);

    // Free the linked list nodes
    while (head != NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
    
    // Free the result array
    free(result);

    return 0;
}
