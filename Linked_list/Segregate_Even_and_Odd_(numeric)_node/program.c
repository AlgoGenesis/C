#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int x) {
    struct Node* temp = 
        (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

// Function to segregate even and odd nodes 
// and return the head of the new list
struct Node* segregateEvenOdd(struct Node* head) {
  
    // Result list to hold even nodes
    struct Node* resStart = NULL;
    struct Node* resEnd = NULL;

    // Pointers for the original list
    struct Node* curr = head;
    struct Node* prev = NULL;

    // Move all even nodes from original to result
    while (curr != NULL) {
      
        // If current node is even
        if (curr->data % 2 == 0) {
          
            // Remove the current even node
            // from the original list
            if (prev != NULL) {
                prev->next = curr->next;
            } else {
                // If the even node is at the head
                head = curr->next;
            }

            // Add the current even node to the result list
            if (resStart == NULL) {
                resStart = curr;
                resEnd = resStart;
            } else {
                resEnd->next = curr;
                resEnd = resEnd->next;
            }

            curr = curr->next;
        } else {
            // If the node is odd, just move to the next
            prev = curr;
            curr = curr->next;
        }
    }

    // If there are no even nodes, return the original list
    if (resStart == NULL) {
        return head;
    }

    // Append the remaining original list
    // (odd nodes) to the result list
    resEnd->next = head;

    // Return the result list (starting with even nodes)
    return resStart;
}

// Helper function to insert nodes at the end of the list
void insertAtEnd(struct Node **head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    if (*head_ref == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
        return;
    }

    struct Node* temp = *head_ref;
    while (temp->next != *head_ref) {
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->next = *head_ref;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    // Create a sample linked list: head->1->4->6->9->10->11
    struct Node* head = NULL;
  
    // Insert elements into the list
    insertAtEnd(&head, 1); 
    insertAtEnd(&head, 4);  
    insertAtEnd(&head, 6);  
    insertAtEnd(&head, 9);  
    insertAtEnd(&head, 10);  
    insertAtEnd(&head, 11);
  
    printf("Original Linked list: ");
    printList(head);

    head = segregateEvenOdd(head);

    printf("Modified Linked list: ");
    printList(head);

    return 0;
}
