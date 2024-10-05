#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to merge two sorted lists
struct Node* mergeTwoLists(struct Node* l1, struct Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    
    if (l1->data < l2->data) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

// Utility to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Utility to print linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Example usage
int main() {
    struct Node* l1 = newNode(1);
    l1->next = newNode(3);
    l1->next->next = newNode(5);

    struct Node* l2 = newNode(2);
    l2->next = newNode(4);
    l2->next->next = newNode(6);

    struct Node* mergedList = mergeTwoLists(l1, l2);

    printf("Merged List: ");
    printList(mergedList);

    return 0;
}
