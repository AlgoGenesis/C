#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256 // Maximum number of unique characters

typedef struct Node {
    char character;
    int frequency;
    struct Node *left, *right;
} Node;

typedef struct MinHeap {
    int size;
    Node *array[MAX_TREE_NODES];
} MinHeap;

// Function to create a new tree node
Node* createNode(char character, int frequency) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create a MinHeap
MinHeap* createMinHeap() {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    return minHeap;
}

// Function to insert a node into the MinHeap
void insertMinHeap(MinHeap* minHeap, Node* node) {
    minHeap->array[minHeap->size++] = node;
}

// Function to build the MinHeap
void buildMinHeap(MinHeap* minHeap) {
    for (int i = (minHeap->size - 1) / 2; i >= 0; i--) {
        for (int j = 0; j < minHeap->size - 1; j++) {
            if (minHeap->array[j]->frequency > minHeap->array[j + 1]->frequency) {
                Node* temp = minHeap->array[j];
                minHeap->array[j] = minHeap->array[j + 1];
                minHeap->array[j + 1] = temp;
            }
        }
    }
}

// Function to extract the minimum node from the MinHeap
Node* extractMin(MinHeap* minHeap) {
    if (minHeap->size == 0) return NULL;
    Node* minNode = minHeap->array[0];
    minHeap->array[0] = minHeap->array[--minHeap->size];
    return minNode;
}

// Function to build the Huffman Tree
Node* buildHuffmanTree(char characters[], int frequencies[], int size) {
    MinHeap* minHeap = createMinHeap();
    for (int i = 0; i < size; i++) {
        insertMinHeap(minHeap, createNode(characters[i], frequencies[i]));
    }
    buildMinHeap(minHeap);

    while (minHeap->size > 1) {
        Node* left = extractMin(minHeap);
        Node* right = extractMin(minHeap);
        Node* newNode = createNode('\0', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;
        insertMinHeap(minHeap, newNode);
    }
    
    return extractMin(minHeap); // Return the root of the Huffman Tree
}

// Function to print the Huffman codes
void printCodes(Node* root, char* code, int top) {
    if (root->left) {
        code[top] = '0';
        printCodes(root->left, code, top + 1);
    }
    if (root->right) {
        code[top] = '1';
        printCodes(root->right, code, top + 1);
    }
    if (!(root->left) && !(root->right)) {
        printf("Character: %c, Code: ", root->character);
        for (int i = 0; i < top; i++) {
            printf("%c", code[i]);
        }
        printf("\n");
    }
}

// Main function to demonstrate Huffman Coding
int main() {
    char characters[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequencies[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(characters) / sizeof(characters[0]);

    Node* root = buildHuffmanTree(characters, frequencies, size);
    
    char code[MAX_TREE_NODES];
    printCodes(root, code, 0);

    return 0;
}