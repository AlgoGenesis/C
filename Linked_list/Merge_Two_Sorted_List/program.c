#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to merge two sorted linked lists
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // Create a dummy node to simplify the merge process
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* current = dummy;

    // Traverse both lists
    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            current->next = list1;  // Add the node from list1
            list1 = list1->next;    // Move the pointer to the next node in list1
        } else {
            current->next = list2;  // Add the node from list2
            list2 = list2->next;    // Move the pointer to the next node in list2
        }
        current = current->next;  // Move the current pointer forward
    }

    // If one of the lists is not empty, append the remaining nodes
    if (list1 != NULL) {
        current->next = list1;
    } else if (list2 != NULL) {
        current->next = list2;
    }

    return dummy->next;  // Return the merged list (ignoring the dummy node)
}

// Helper function to create a linked list from an array
struct ListNode* createLinkedList(int* values, int size) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* current = dummy;
    for (int i = 0; i < size; i++) {
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = values[i];
    }
    return dummy->next;
}

// Helper function to print a linked list
void printLinkedList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d", current->val);
        if (current->next != NULL) {
            printf("->");
        }
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Example input
    int list1_values[] = {1, 2, 4};
    int list2_values[] = {1, 3, 4};

    struct ListNode* list1 = createLinkedList(list1_values, 3);
    struct ListNode* list2 = createLinkedList(list2_values, 3);

    printf("List1: ");
    printLinkedList(list1);

    printf("List2: ");
    printLinkedList(list2);

    // Merge the lists
    struct ListNode* mergedList = mergeTwoLists(list1, list2);

    // Print the merged list
    printf("Merged List: ");
    printLinkedList(mergedList);

    return 0;
}
