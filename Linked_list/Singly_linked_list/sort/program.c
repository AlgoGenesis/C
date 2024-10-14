#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to split the linked list into two halves
void splitList(struct ListNode* head, struct ListNode** front, struct ListNode** back) {
    struct ListNode* slow;
    struct ListNode* fast;
    slow = head;
    fast = head->next;

    // Move fast two nodes and slow one node
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // Split the list into two halves
    *front = head;
    *back = slow->next;
    slow->next = NULL; // End the first half
}

// Function to merge two sorted linked lists
struct ListNode* mergeLists(struct ListNode* a, struct ListNode* b) {
    struct ListNode* result = NULL;

    // Base cases
    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;

    // Recursively merge the two lists
    if (a->val <= b->val) {
        result = a;
        result->next = mergeLists(a->next, b);
    } else {
        result = b;
        result->next = mergeLists(a, b->next);
    }
    return result;
}

// Function to sort the linked list using merge sort
struct ListNode* mergeSort(struct ListNode* head) {
    // Base case: if head is NULL or there is only one node
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* front;
    struct ListNode* back;

    // Split the list into two halves
    splitList(head, &front, &back);

    // Sort the two halves
    front = mergeSort(front);
    back = mergeSort(back);

    // Merge the sorted halves
    return mergeLists(front, back);
}

// Function to create a new node
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Create a sample linked list: 4 -> 2 -> 1 -> 3
    struct ListNode* head = createNode(4);
    head->next = createNode(2);
    head->next->next = createNode(1);
    head->next->next->next = createNode(3);

    printf("Original List: ");
    printList(head);

    head = mergeSort(head);

    printf("Sorted List: ");
    printList(head);

    return 0;
}
