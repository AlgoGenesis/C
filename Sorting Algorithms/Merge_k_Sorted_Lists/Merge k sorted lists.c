#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Min-Heap Node
struct MinHeapNode {
    struct ListNode *listNode;
};

// MinHeap
struct MinHeap {
    int size;
    struct MinHeapNode **array;
};

// Function to create a new MinHeap Node
struct MinHeapNode* newMinHeapNode(struct ListNode *listNode) {
    struct MinHeapNode* minHeapNode = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    minHeapNode->listNode = listNode;
    return minHeapNode;
}

// Function to create a MinHeap
struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->array= (struct MinHeapNode*)malloc(capacity * sizeof(struct MinHeapNode));
    return minHeap;
}

// Function to swap two MinHeap Nodes
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Function to min-heapify at a given index
void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->listNode->val < minHeap->array[smallest]->listNode->val)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->listNode->val < minHeap->array[smallest]->listNode->val)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Function to extract the minimum node from the heap
struct ListNode* extractMin(struct MinHeap* minHeap) {
    if (minHeap->size == 0)
        return NULL;

    struct ListNode* root = minHeap->array[0]->listNode;

    if (minHeap->size > 1) {
        minHeap->array[0] = minHeap->array[minHeap->size - 1];
        minHeapify(minHeap, 0);
    }
    minHeap->size--;
    return root;
}

// Function to insert a new node into the heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
    minHeap->size++;
    int i = minHeap->size - 1;
    while (i && minHeapNode->listNode->val < minHeap->array[(i - 1) / 2]->listNode->val) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

// Function to merge k sorted linked