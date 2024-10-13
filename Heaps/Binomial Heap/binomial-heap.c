#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define the structure for a binomial heap node
struct BinomialNode {
    int key;                        // Key of the node
    int degree;                     // Degree of the node
    struct BinomialNode* parent;    // Pointer to the parent node
    struct BinomialNode* child;     // Pointer to the first child node
    struct BinomialNode* sibling;   // Pointer to the next sibling node
};

// Function to create a new binomial heap node
struct BinomialNode* createNode(int key) {
    struct BinomialNode* newNode = (struct BinomialNode*)malloc(sizeof(struct BinomialNode));
    newNode->key = key;
    newNode->degree = 0;
    newNode->parent = NULL;
    newNode->child = NULL;
    newNode->sibling = NULL;
    return newNode;
}

// Function to merge two binomial heaps( combines two binomial heaps while maintaining their structure)
struct BinomialNode* mergeHeaps(struct BinomialNode* h1, struct BinomialNode* h2) {
    if (!h1) return h2;
    if (!h2) return h1;

    struct BinomialNode* head = NULL;
    struct BinomialNode* tail = NULL;
    struct BinomialNode* a = h1;
    struct BinomialNode* b = h2;

    // Merge the two heaps
    while (a && b) {
        if (a->degree <= b->degree) {
            if (!head) {
                head = tail = a;
            } else {
                tail->sibling = a;
                tail = a;
            }
            a = a->sibling;
        } else {
            if (!head) {
                head = tail = b;
            } else {
                tail->sibling = b;
                tail = b;
            }
            b = b->sibling;
        }
    }

    // Attach any remaining nodes
    if (a) tail->sibling = a;
    else tail->sibling = b;

    return head;
}

// Function to link two binomial trees
void linkTrees(struct BinomialNode* y, struct BinomialNode* z) {
    y->parent = z;
    y->sibling = z->child;
    z->child = y;
    z->degree++;
}

// Function to union two binomial heaps(merges two heaps and ensures that the properties of the binomial heap are preserved)
struct BinomialNode* unionHeaps(struct BinomialNode* h1, struct BinomialNode* h2) {
    struct BinomialNode* mergedHeap = mergeHeaps(h1, h2);
    if (!mergedHeap) return NULL;

    struct BinomialNode* prev = NULL;
    struct BinomialNode* curr = mergedHeap;
    struct BinomialNode* next = curr->sibling;

    while (next) {
        if (curr->degree != next->degree || 
            (next->sibling && next->sibling->degree == curr->degree)) {
            prev = curr;
            curr = next;
        } else {
            if (curr->key <= next->key) {
                curr->sibling = next->sibling;
                linkTrees(next, curr);
            } else {
                if (prev) prev->sibling = next;
                else mergedHeap = next;
                linkTrees(curr, next);
                curr = next;
            }
        }
        next = curr->sibling;
    }
    return mergedHeap;
}

// Function to insert a new key into the binomial heap
struct BinomialNode* insert(struct BinomialNode* heap, int key) {
    struct BinomialNode* newNode = createNode(key);
    return unionHeaps(heap, newNode);
}

// Function to find the minimum key in the binomial heap
struct BinomialNode* findMin(struct BinomialNode* heap) {
    struct BinomialNode* minNode = heap;
    struct BinomialNode* curr = heap;

    while (curr) {
        if (curr->key < minNode->key) {
            minNode = curr;
        }
        curr = curr->sibling;
    }
    return minNode;
}

// Function to extract the minimum key from the binomial heap
struct BinomialNode* extractMin(struct BinomialNode** heap) {
    if (!*heap) return NULL;

    struct BinomialNode* minNode = findMin(*heap);
    struct BinomialNode* prevMin = NULL;
    struct BinomialNode* curr = *heap;
    struct BinomialNode* prev = NULL;

    while (curr->sibling) {
        if (curr->sibling == minNode) {
            prevMin = curr;
            break;
        }
        curr = curr->sibling;
    }

    // Remove minNode from the heap
    if (prevMin) {
        prevMin->sibling = minNode->sibling;
    } else {
        *heap = minNode->sibling;
    }

    struct BinomialNode* childHeap = minNode->child;
    struct BinomialNode* child = NULL;

    // Reverse the order of children and create a new heap
    while (childHeap) {
        child = childHeap;
        childHeap = childHeap->sibling;
        child->sibling = NULL;
        child->parent = NULL;
    }

    *heap = unionHeaps(*heap, child);
    return minNode;
}

// Function to decrease the key of a specific node
void decreaseKey(struct BinomialNode* node, int newKey) {
    if (newKey > node->key) {
        printf("New key is greater than current key\n");
        return;
    }

    node->key = newKey;
    struct BinomialNode* parent = node->parent;

    while (parent && node->key < parent->key) {
        // Swap keys
        int temp = node->key;
        node->key = parent->key;
        parent->key = temp;

        // Move up the heap
        node = parent;
        parent = parent->parent;
    }
}

// Function to delete a node from the binomial heap
void deleteNode(struct BinomialNode** heap, struct BinomialNode* node) {
    decreaseKey(node, INT_MIN);  // Decrease the key to a minimum value
    extractMin(heap);             // Extract the minimum node
}

// Function to print the binomial heap
void printHeap(struct BinomialNode* heap) {
    struct BinomialNode* curr = heap;
    while (curr) {
        printf("Node key: %d, Degree: %d\n", curr->key, curr->degree);
        if (curr->child) {
            printf("Children of %d: ", curr->key);
            struct BinomialNode* child = curr->child;
            while (child) {
                printf("%d ", child->key);
                child = child->sibling;
            }
            printf("\n");
        }
        curr = curr->sibling;
    }
}

// Main function to demonstrate binomial heap operations
int main() {
    struct BinomialNode* heap = NULL;

    // Inserting elements into the binomial heap
    heap = insert(heap, 10);
    heap = insert(heap, 20);
    heap = insert(heap, 30);
    heap = insert(heap, 5);
    heap = insert(heap, 15);

    printf("Heap after insertions:\n");
    printHeap(heap);

    // Finding minimum key
    struct BinomialNode* minNode = findMin(heap);
    printf("Minimum key: %d\n", minNode->key);

    // Extracting the minimum key
    struct BinomialNode* extractedMin = extractMin(&heap);
    printf("Extracted minimum key: %d\n", extractedMin->key);
    free(extractedMin);

    printf("Heap after extracting minimum:\n");
    printHeap(heap);

    // Decreasing a key of a child node
    decreaseKey(heap->child, 1);
    printf("Heap after decreasing a key:\n");
    printHeap(heap);

    // Deleting a node from the heap
    deleteNode(&heap, heap->child); 
    printf("Heap after deleting a node:\n");
    printHeap(heap);

    return 0;
}
