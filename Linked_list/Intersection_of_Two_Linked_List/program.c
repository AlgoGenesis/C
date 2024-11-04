#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// Helper function to create a new node
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

// Function to find the intersection node of two linked lists
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    if (!headA || !headB) return NULL;

    struct ListNode* ptrA = headA;
    struct ListNode* ptrB = headB;

    // Traverse both lists; when one pointer reaches the end, start from the beginning of the other list
    while (ptrA != ptrB) {
        ptrA = (ptrA == NULL) ? headB : ptrA->next;
        ptrB = (ptrB == NULL) ? headA : ptrB->next;
    }

    // Either both pointers meet at the intersection node, or they meet at NULL
    return ptrA;
}

// Helper function to print the linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct ListNode* listA = createNode(4);
    listA->next = createNode(1);
    struct ListNode* intersectNode = createNode(9);
    listA->next->next = intersectNode;
    intersectNode->next = createNode(4);
    intersectNode->next->next = createNode(5);

    struct ListNode* listB = createNode(5);
    listB->next = createNode(6);
    listB->next->next = createNode(1);
    listB->next->next->next = intersectNode;

    printf("List A: ");
    printList(listA);
    printf("List B: ");
    printList(listB);

    struct ListNode* intersection = getIntersectionNode(listA, listB);

    if (intersection) {
        printf("Intersected at '%d'\n", intersection->val);
    } else {
        printf("No intersection\n");
    }

    return 0;
}
