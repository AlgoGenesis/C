#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to remove the N-th node from end of list
struct Node* removeNthFromEnd(struct Node* head, int n) {
    struct Node* dummy = (struct Node*)malloc(sizeof(struct Node));
    dummy->next = head;
    struct Node *slow = dummy, *fast = dummy;
    
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    struct Node* temp = slow->next;
    slow->next = slow->next->next;
    free(temp);

    return dummy->next;
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
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    int n = 2;
    head = removeNthFromEnd(head, n);

    printf("List after removing %d-th node from end: ", n);
    printList(head);

    return 0;
}
