#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct min_heap {
    int *p;
    int size;
    int count;
} Heap;

Heap *create_heap(Heap *heap); // Initializes a new heap
void down_heapify(Heap *heap, int index); // Restores min-heap property from the specified index downwards
void up_heapify(Heap *heap, int index); // Restores min-heap property from the specified index upwards
void push(Heap *heap, int x); // Inserts a new element into the heap
void pop(Heap *heap); // Removes the minimum element from the heap
int top(Heap *heap); // Retrieves the minimum element of the heap
int empty(Heap *heap); // Checks if the heap is empty
int size(Heap *heap); // Returns the current number of elements in the heap

int main() {
    Heap *head = create_heap(head);
    push(head, 10);
    printf("Pushing element : 10\n");
    push(head, 3);
    printf("Pushing element : 3\n");
    push(head, 2);
    printf("Pushing element : 2\n");
    push(head, 8);
    printf("Pushing element : 8\n");
    printf("Top element = %d \n", top(head));
    push(head, 1);
    printf("Pushing element : 1\n");
    push(head, 7);
    printf("Pushing element : 7\n");
    printf("Top element = %d \n", top(head));
    pop(head);
    printf("Popping an element.\n");
    printf("Top element = %d \n", top(head));
    pop(head);
    printf("Popping an element.\n");
    printf("Top element = %d \n", top(head));
    printf("\n");
    return 0;
}

Heap *create_heap(Heap *heap) {
    // Allocate memory for the heap and initialize its properties
    heap = (Heap *)malloc(sizeof(Heap));
    heap->size = 2; // Initial capacity of the heap array
    heap->p = (int *)malloc(heap->size * sizeof(int));
    heap->count = 0;
    return heap;
}

void down_heapify(Heap *heap, int index) {
    // Reorder the heap starting from the specified index downwards
    if (index >= heap->count) return;
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int smallest = index;

    if (left < heap->count && heap->p[left] < heap->p[smallest])
        smallest = left;
    if (right < heap->count && heap->p[right] < heap->p[smallest])
        smallest = right;
    if (smallest != index) {
        int temp = heap->p[smallest];
        heap->p[smallest] = heap->p[index];
        heap->p[index] = temp;
        down_heapify(heap, smallest);
    }
}

void up_heapify(Heap *heap, int index) {
    // Move element at index up to restore heap property
    int parent = (index - 1) / 2;
    if (parent >= 0 && heap->p[index] < heap->p[parent]) {
        int temp = heap->p[index];
        heap->p[index] = heap->p[parent];
        heap->p[parent] = temp;
        up_heapify(heap, parent);
    }
}

void push(Heap *heap, int x) {
    // Insert an element into the heap, resizing if necessary
    if (heap->count == heap->size) {
        heap->size *= 2;
        heap->p = (int *)realloc(heap->p, heap->size * sizeof(int));
    }
    heap->p[heap->count++] = x;
    up_heapify(heap, heap->count - 1);
}

void pop(Heap *heap) {
    // Remove the top (min) element and reorder the heap
    if (heap->count == 0) return;
    heap->count--;
    heap->p[0] = heap->p[heap->count];
    down_heapify(heap, 0);
    // Shrink array if necessary
    if (heap->count > 0 && heap->count <= heap->size / 4) {
        heap->size /= 2;
        heap->p = (int *)realloc(heap->p, heap->size * sizeof(int));
    }
}

int top(Heap *heap) {
    // Return min element or INT_MAX if heap is empty
    return heap->count != 0 ? heap->p[0] : INT_MAX;
}

int empty(Heap *heap) {
    return heap->count == 0;
}

int size(Heap *heap) {
    return heap->count;
}
