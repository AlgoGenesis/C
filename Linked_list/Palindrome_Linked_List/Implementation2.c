#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

int isPalindrome(struct Node* head) {
    struct Node* temp = head;
    int stack[1000], top = -1;

    while (temp != NULL) {
        stack[++top] = temp->data;
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL) {
        if (temp->data != stack[top--]) {
            return 0;
        }
        temp = temp->next;
    }
    return 1;
}

int main() {
    struct Node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);

    if (isPalindrome(head)) {
        printf("Palindrome\n");
    } else {
        printf("Not Palindrome\n");
    }
    return 0;
}
