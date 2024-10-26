#include <stdio.h>
#include <stdlib.h>

// Define the ListNode structure
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

// Function to rotate the list to the right by k positions
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL) return NULL;

    //step 1: calculate length of list and traverse till end node
    struct ListNode* end = head;
    int len = 1; // Start with 1 because we are at the head node
    while (end->next) {
        len++;
        end = end->next;
    }
    
    //step 2: case: if len<k, we need to calculate effective rotations
    k = k % len;  // Calculate the effective rotations needed
    if (len == 1 || k == 0) {
        return head; // No rotation needed
    }

    //step 3: traverse to get at end node after rotation
    struct ListNode* curr = head;
    int d = len - k;
    for (int i = 1; i < d; i++) {
        curr = curr->next;
    }

    //step 4: shifting will start from curr, i.e, curr will point to null and curr->next will become head
    struct ListNode* temp = curr->next;
    end->next = head;
    head = temp;
    curr->next = NULL;
    
    return head;
}

// Helper function to print the list
void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int k, value;
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    printf("Enter values for the nodes (enter -1 to stop):\n");
    while (1) {
        scanf("%d", &value);
        if (value == -1) break; // Stop input on entering -1

        struct ListNode* newNode = createNode(value);
        if (head == NULL) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }

    printf("Enter the value of k (number of rotations): ");
    scanf("%d", &k);

    printf("Original list: ");
    printList(head);

    head = rotateRight(head, k);

    printf("Rotated list: ");
    printList(head);

    return 0;
}
