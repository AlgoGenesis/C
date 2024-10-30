#include <stdio.h>
#include <stdlib.h>

// Definition of ListNode structure
typedef struct ListNode {
    int val;
    struct ListNode* next;
    struct ListNode* random;
} ListNode;

// Helper function to create a new ListNode
ListNode* createNode(int val) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = NULL;
    newNode->random = NULL;
    return newNode;
}

// Function to clone the linked list with random pointers
ListNode* cloneLinkedListWithRandomPointer(ListNode* head) {
    if (!head) return NULL;

    // Step 1: Map original nodes to cloned nodes using an array of pointers
    ListNode** nodeMap = (ListNode**)malloc(100 * sizeof(ListNode*));
    for (int i = 0; i < 100; ++i) nodeMap[i] = NULL;

    // Step 2: Create cloned nodes without setting next or random
    ListNode* curr = head;
    while (curr) {
        nodeMap[curr->val] = createNode(curr->val);  // Map original node's value to its clone
        curr = curr->next;
    }

    // Step 3: Set next and random pointers for cloned nodes
    curr = head;
    while (curr) {
        if (curr->next) nodeMap[curr->val]->next = nodeMap[curr->next->val];
        if (curr->random) nodeMap[curr->val]->random = nodeMap[curr->random->val];
        curr = curr->next;
    }

    // Return the head of the cloned list
    ListNode* clonedHead = nodeMap[head->val];
    free(nodeMap);
    return clonedHead;
}

// Helper function to create a linked list from arrays of values and random indices
ListNode* createLinkedList(const int* values, const int* randomIndices, int size) {
    if (size == 0) return NULL;

    ListNode** nodes = (ListNode**)malloc(size * sizeof(ListNode*));
    for (int i = 0; i < size; ++i) {
        nodes[i] = createNode(values[i]);
    }

    for (int i = 0; i < size - 1; ++i) {
        nodes[i]->next = nodes[i + 1];
    }

    for (int i = 0; i < size; ++i) {
        if (randomIndices[i] != -1) {
            nodes[i]->random = nodes[randomIndices[i]];
        }
    }

    ListNode* head = nodes[0];
    free(nodes);
    return head;
}

// Helper function to print the linked list with random pointers
void printLinkedList(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
        printf("Node(%d)", curr->val);
        if (curr->random) {
            printf(" -> Random(%d)\n", curr->random->val);
        } else {
            printf(" -> Random(NULL)\n");
        }
        curr = curr->next;
    }
}

int main() {
    // Define values and random indices for each node
    int values[] = {1, 2, 3, 4, 5};
    int randomIndices[] = {2, 4, -1, 0, 1};  // -1 indicates no random pointer
    int size = sizeof(values) / sizeof(values[0]);

    // Create the linked list with random pointers
    ListNode* originalList = createLinkedList(values, randomIndices, size);

    printf("Original list with random pointers:\n");
    printLinkedList(originalList);

    // Clone the linked list
    ListNode* clonedList = cloneLinkedListWithRandomPointer(originalList);

    printf("\nCloned list with random pointers:\n");
    printLinkedList(clonedList);

    // Free the original and cloned lists
    ListNode* temp;
    while (originalList) {
        temp = originalList;
        originalList = originalList->next;
        free(temp);
    }
    while (clonedList) {
        temp = clonedList;
        clonedList = clonedList->next;
        free(temp);
    }

    return 0;
}
