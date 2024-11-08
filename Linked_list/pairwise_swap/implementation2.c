// C program to pairwise swap elements
// in a given linked list

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to swap data of nodes in pairs
void pairwiseSwap(struct Node* head) {
    struct Node* curr = head;

    // Traverse the list and swap data in pairs
    while (curr != NULL && curr->next != NULL) {
        
        // Swap data of current node and the next node
        int temp = curr->data;
        curr->data = curr->next->data;
        curr->next->data = temp;

        // Move to the next pair
        curr = curr->next->next;
    }
}

void printList(struct Node* head) {
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

struct Node* createNode(int val) {
    struct Node* newNode = 
      (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

int main() {
    
    // Creating the linked list: 
      //1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);

    pairwiseSwap(head);

    printList(head);

    return 0;
}
