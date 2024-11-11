#include <stdio.h>
#include <stdlib.h>

// Define the structure for a singly linked list node.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to create a new node with given value.
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Function to merge k sorted linked lists into one sorted linked list.
struct ListNode* mergeKLists(struct ListNode** lists, int k) {
    int size = k; 
    // Dummy head to simplify edge cases.
    struct ListNode* dummyHead = newNode(0); 
    // Tail pointer to build the merged list.
    struct ListNode* tail = dummyHead; 
    
    while (1) {
        // Node with the smallest value.
        struct ListNode* minNode = NULL; 
        // Index of the list containing the minNode.
        int minPointer = -1; 
        
        for (int i = 0; i < size; i++) {
            if (lists[i] == NULL) {
                continue; 
            }
            if (minNode == NULL || lists[i]->val < minNode->val) {
                minNode = lists[i];
                minPointer = i;
            }
        }
        
        if (minPointer == -1) {
            break;
        }
        // Link the smallest node to the merged list and move the tail pointer.
        tail->next = minNode;
        tail = tail->next;
        // Move to the next node in the list from which minNode was taken.
        lists[minPointer] = lists[minPointer]->next;
    }

    // The merged list starts after the dummy head.
    struct ListNode* head = dummyHead->next;
    // Free the dummy head as it's not part of the actual list.
    free(dummyHead);
    return head;
}

// Function to print the linked list starting from the given head node.
void printList(struct ListNode* head) {
    while (head) {
        printf("%d", head->val);
        if (head->next) {
            printf("->");
        }
        head = head->next;
    }
    printf("\n");
}

// Main function to test the mergeKLists function.
int main() {
    // Create three example linked lists.
    struct ListNode* l1 = newNode(-1);
    l1->next = newNode(4);
    l1->next->next = newNode(5);
    
    struct ListNode* l2 = newNode(0);
    l2->next = newNode(2);
    l2->next->next = newNode(4996);
    
    struct ListNode* l3 = newNode(-10);
    l3->next = newNode(8);
    
    struct ListNode* lists[] = {l1, l2, l3};
    int k = sizeof(lists) / sizeof(lists[0]); 
    
    struct ListNode* mergedList = mergeKLists(lists, k);

    printList(mergedList);
    
    return 0;
}