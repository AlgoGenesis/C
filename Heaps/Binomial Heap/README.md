# Binomial Heap Implementation in C

**Binomial Heaps** are a collection of binomial trees that satisfy the min-heap property and are designed to efficiently support key operations like insertion, union, finding the minimum, decreasing keys, and deleting nodes. These operations make binomial heaps useful for algorithms that require efficient priority queues, such as Dijkstra's and Prim's algorithms.

## Features

### 1. Creating a Binomial Heap
Initializes an empty binomial heap, which will be a collection of binomial trees.

### 2. Finding the Minimum Key
Searches the root nodes of the binomial heap to find the node with the minimum key.

```c
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
```

### 3. Union (Merging Two Binomial Heaps)
Merges two binomial heaps by combining their root lists and linking binomial trees of the same degree.

```c
struct BinomialNode* unionHeaps(struct BinomialNode* heap1, struct BinomialNode* heap2) {
    struct BinomialNode* mergedHeap = mergeHeaps(heap1, heap2);
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
                mergeTrees(curr, next);
            } else {
                if (prev) prev->sibling = next;
                else mergedHeap = next;
                mergeTrees(next, curr);
                curr = next;
            }
        }
        next = curr->sibling;
    }
    return mergedHeap;
}
```

### 4. Inserting a Node
Inserts a new node by creating a new binomial tree and merging it with the existing heap.

```c
struct BinomialNode* insert(struct BinomialNode* heap, int key) {
    struct BinomialNode* newNode = createNode(key);
    return unionHeaps(heap, newNode);
}
```

### 5. Extracting the Minimum Key
Removes the node with the minimum key and re-adjusts the heap by merging its children back into the binomial heap.

```c
struct BinomialNode* extractMin(struct BinomialNode** heap) {
    if (!*heap) return NULL;

    // Find the minimum node
    struct BinomialNode* minNode = *heap;
    struct BinomialNode* prevMin = NULL;
    struct BinomialNode* curr = *heap;
    struct BinomialNode* prev = NULL;

    while (curr->sibling) {
        if (curr->sibling->key < minNode->key) {
            minNode = curr->sibling;
            prevMin = curr;
        }
        curr = curr->sibling;
    }

    // Remove minNode from root list
    if (prevMin) prevMin->sibling = minNode->sibling;
    else *heap = minNode->sibling;

    // Create a new heap from minNode's children
    struct BinomialNode* childHeap = NULL;
    struct BinomialNode* child = minNode->child;
    while (child) {
        struct BinomialNode* next = child->sibling;
        child->sibling = childHeap;
        child->parent = NULL;
        childHeap = child;
        child = next;
    }

    // Union the remaining heap with the new heap from children
    *heap = unionHeaps(*heap, childHeap);

    return minNode;
}
```

### 6. Decreasing a Key
Decreases the key of a specific node and restores the heap property by moving the node up in the tree if necessary.

```c
void decreaseKey(struct BinomialNode* heap, struct BinomialNode* node, int newKey) {
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
```

### 7. Deleting a Node
Deletes a node by first decreasing its key to a very small value and then extracting it from the heap.

```c
void deleteNode(struct BinomialNode** heap, struct BinomialNode* node) {
    decreaseKey(*heap, node, -__INT_MAX__);  // Set to a very small value
    extractMin(heap);
}


## Time Complexity of Operations

- **Insert**: O(log n)
- **Find Minimum**: O(log n)
- **Extract Minimum**: O(log n)
- **Union**: O(log n)
- **Decrease Key**: O(log n)
- **Delete**: O(log n)

