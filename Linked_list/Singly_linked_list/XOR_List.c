#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct node {
    int data;
    struct node *link;
};

struct node *head = NULL, *tail = NULL; //points to the first and last node respectvely

struct node* XOR(struct node *a, struct node *b) {
    return (struct node *)((uintptr_t)a ^ (uintptr_t)b); //returns the XOR value of the two addresses
}

void insert(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->link = XOR(tail, NULL); //link of the current node is the XOR value of its previous node and next node
    
    if (head == NULL) {
        head = newnode;
        tail = newnode;
    } else {
        tail->link = XOR(XOR(tail->link, NULL), newnode);
        tail = newnode;
    }
}

void traverse() {
    struct node *temp = head;
    struct node *prev = NULL, *next;
    
    while (temp != NULL) {
        printf("%d ", temp->data);
        next = XOR(prev, temp->link);
        prev = temp;
        temp = next;
    }
    printf("\n");
}

int main() {
    printf("Enter value:\n");
    int value;
    char ch;
    
    do {
        scanf("%d", &value);
        insert(value);
        printf("Do you wish to continue? (Y/N)\n");
        scanf(" %c", &ch);
    } while (ch == 'Y' || ch == 'y');
    
    traverse();
    
    return 0;
}
