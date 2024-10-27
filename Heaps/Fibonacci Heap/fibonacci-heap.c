#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent a node in the Fibonacci heap
typedef struct Node {
    int key;
    int degree;
    struct Node* parent;
    struct Node* child;
    struct Node* next;
    struct Node* prev;
    int marked;
} Node;

// Structure to represent the Fibonacci heap
typedef struct FibonacciHeap {
    Node* min;
    int count;
} FibonacciHeap;


// Create a new Fibonacci heap
FibonacciHeap* createFibonacciHeap() {
    FibonacciHeap* heap = (FibonacciHeap*)malloc(sizeof(FibonacciHeap));
    heap->min = NULL;
    heap->count = 0;
    return heap;
}

// Create a new node
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->degree = 0;
    newNode->parent = NULL;
    newNode->child = NULL;
    newNode->next = newNode; // Points to itself
    newNode->prev = newNode; // Points to itself
    newNode->marked = 0;
    return newNode;
}

// Insert a key into the Fibonacci heap
void insert(FibonacciHeap* heap, int key) {
    Node* newNode = createNode(key);
    if (heap->min == NULL) {
        heap->min = newNode;
    } else {
        // Add new node to the root list
        newNode->next = heap->min;
        newNode->prev = heap->min->prev;
        heap->min->prev->next = newNode;
        heap->min->prev = newNode;

        // Update min if necessary
        if (newNode->key < heap->min->key) {
            heap->min = newNode;
        }
    }
    heap->count++;
}

// Merge two Fibonacci heaps
void merge(FibonacciHeap* heap1, FibonacciHeap* heap2) {
    if (heap1->min == NULL) {
        heap1->min = heap2->min;
    } else if (heap2->min != NULL) {
        // Connect the root lists
        Node* temp = heap1->min->next;
        heap1->min->next = heap2->min->next;
        heap2->min->next->prev = heap1->min;
        heap2->min->next = temp;
        temp->prev = heap2->min;

        // Update min if necessary
        if (heap2->min->key < heap1->min->key) {
            heap1->min = heap2->min;
        }
    }
    heap1->count += heap2->count;
    free(heap2); // Free the merged heap
}

// Consolidate trees of the same degree in the Fibonacci heap
void consolidate(FibonacciHeap* heap) {
    int maxDegree = 0;
    Node* current = heap->min;

    // Find the maximum degree of nodes
    do {
        if (current->degree > maxDegree) {
            maxDegree = current->degree;
        }
        current = current->next;
    } while (current != heap->min);

    // Create an array to keep track of trees by their degree
    Node** degreeArray = (Node**)malloc((maxDegree + 1) * sizeof(Node*));
    for (int i = 0; i <= maxDegree; i++) {
        degreeArray[i] = NULL; // Initialize all degrees to NULL
    }

    current = heap->min;
    int numRoots = heap->count;

    // Iterate through the root list
    while (numRoots > 0) {
        Node* next = current->next; // Save next node
        int degree = current->degree;

        // Find if there's another node of the same degree
        while (degreeArray[degree] != NULL) {
            Node* other = degreeArray[degree];

            // Ensure current is always the smaller one
            if (current->key > other->key) {
                Node* temp = current;
                current = other;
                other = temp;
            }

            // Merge the two trees
            if (other == heap->min) {
                heap->min = current; // Update min if necessary
            }

            // Make other a child of current
            other->next->prev = other->prev;
            other->prev->next = other->next;

            // Add other to the children of current
            other->parent = current;
            if (current->child == NULL) {
                current->child = other;
                other->next = other; // Points to itself
                other->prev = other; // Points to itself
            } else {
                other->next = current->child;
                other->prev = current->child->prev;
                current->child->prev->next = other;
                current->child->prev = other;
            }

            current->degree++;
            degreeArray[degree] = NULL; // Reset degree
            degree++;
        }

        // Place the current node into the degree array
        degreeArray[degree] = current;

        current = next; // Move to the next node
        numRoots--;
    }

    // Reconstruct the root list
    heap->min = NULL;
    for (int i = 0; i <= maxDegree; i++) {
        if (degreeArray[i] != NULL) {
            if (heap->min == NULL) {
                heap->min = degreeArray[i];
            } else {
                // Add to the root list
                degreeArray[i]->next = heap->min;
                degreeArray[i]->prev = heap->min->prev;
                heap->min->prev->next = degreeArray[i];
                heap->min->prev = degreeArray[i];

                // Update min if necessary
                if (degreeArray[i]->key < heap->min->key) {
                    heap->min = degreeArray[i];
                }
            }
        }
    }

    free(degreeArray); // Free the degree array
}

// Extract the minimum node from the Fibonacci heap
Node* extractMin(FibonacciHeap* heap) {
    Node* minNode = heap->min;
    if (minNode != NULL) {
        if (minNode->child != NULL) {
            // Add the child nodes to the root list
            Node* child = minNode->child;
            do {
                Node* nextChild = child->next;
                child->prev = heap->min->prev;
                child->next = heap->min;
                heap->min->prev->next = child;
                heap->min->prev = child;
                child->parent = NULL; // Set parent to NULL
                child = nextChild;
            } while (child != minNode->child);
        }

        // Remove minNode from the root list
        if (minNode->prev == minNode) {
            heap->min = NULL; // Heap is now empty
        } else {
            minNode->prev->next = minNode->next;
            minNode->next->prev = minNode->prev;
            heap->min = minNode->next; // Set min to the next node
        }

        // Consolidate the heap
        consolidate(heap);
        heap->count--;
    }
    return minNode;
}

// Decrease the key of a node
void decreaseKey(FibonacciHeap* heap, Node* node, int newKey) {
    if (newKey > node->key) {
        printf("New key is greater than current key\n");
        return;
    }
    node->key = newKey;

    Node* parent = node->parent;
    if (parent != NULL && node->key < parent->key) {
        // Cut the node from its parent
        if (parent->child == node) {
            parent->child = node->next; // Remove node from parent's child list
        }
        node->prev->next = node->next;
        node->next->prev = node->prev;

        parent->degree--;
        node->next = heap->min; // Add to the root list
        node->prev = heap->min->prev;
        heap->min->prev->next = node;
        heap->min->prev = node;
        node->parent = NULL; // Set parent to NULL

        node->marked = 0; // Reset the marked status
    }

    // Update the min node if necessary
    if (node->key < heap->min->key) {
        heap->min = node;
    }
}

// Delete a node from the Fibonacci heap
void deleteNode(FibonacciHeap* heap, Node* node) {
    decreaseKey(heap, node, INT_MIN); // Decrease to minimum possible value
    extractMin(heap); // Now extract the minimum
}

// Print the Fibonacci heap (in a simple way)
void printHeap(Node* minNode) {
    if (minNode == NULL) {
        printf("Heap is empty.\n");
        return;
    }
    Node* current = minNode;
    do {
        printf("%d ", current->key);
        current = current->next;
    } while (current != minNode);
    printf("\n");
}

// Free the Fibonacci heap
void freeHeap(Node* node) {
    if (node == NULL) return;
    Node* current = node;
    do {
        Node* next = current->next;
        free(current);
        current = next;
    } while (current != node);
}

// Main function to test the Fibonacci heap
int main() {
    FibonacciHeap* heap = createFibonacciHeap();
    
    insert(heap, 10);
    insert(heap, 20);
    insert(heap, 30);
    insert(heap, 5);
    insert(heap, 15);

    printf("Heap after inserts: ");
    printHeap(heap->min);

    Node* minNode = extractMin(heap);
    printf("Extracted min: %d\n", minNode->key);
    free(minNode);

    printf("Heap after extracting min: ");
    printHeap(heap->min);

    decreaseKey(heap, heap->min, 12);
    printf("Heap after decreasing key: ");
    printHeap(heap->min);

    deleteNode(heap, heap->min);
    printf("Heap after deleting min: ");
    printHeap(heap->min);

    freeHeap(heap->min); // Free remaining nodes
    free(heap); // Free heap structure
    return 0;
}
