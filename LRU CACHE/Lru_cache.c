#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int value;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    int capacity;
    int size;
    Node* head;
    Node* tail;
    Node** hashTable;
} LRUCache;

// Helper function to create a new node
Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Initialize LRU Cache
LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* cache = (LRUCache*)malloc(sizeof(LRUCache));
    cache->capacity = capacity;
    cache->size = 0;
    cache->head = createNode(0, 0); // Dummy head
    cache->tail = createNode(0, 0); // Dummy tail
    cache->head->next = cache->tail;
    cache->tail->prev = cache->head;

    cache->hashTable = (Node**)calloc(10001, sizeof(Node*)); // Hash table size: 10001 for simplicity
    return cache;
}

// Move a node to the front (most recently used)
void moveToHead(LRUCache* cache, Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;

    node->next = cache->head->next;
    node->prev = cache->head;
    cache->head->next->prev = node;
    cache->head->next = node;
}

// Remove the least recently used node (from tail)
Node* removeTail(LRUCache* cache) {
    Node* node = cache->tail->prev;
    node->prev->next = cache->tail;
    cache->tail->prev = node->prev;
    return node;
}

// Get value from the cache
int lRUCacheGet(LRUCache* cache, int key) {
    Node* node = cache->hashTable[key];
    if (!node) return -1; // Key not found

    moveToHead(cache, node); // Move accessed node to the front
    return node->value;
}

// Put a key-value pair into the cache
void lRUCachePut(LRUCache* cache, int key, int value) {
    Node* node = cache->hashTable[key];

    if (node) {
        node->value = value;  // Update value
        moveToHead(cache, node);  // Move to front
    } else {
        Node* newNode = createNode(key, value);
        cache->hashTable[key] = newNode;
        newNode->next = cache->head->next;
        newNode->prev = cache->head;
        cache->head->next->prev = newNode;
        cache->head->next = newNode;

        cache->size++;
        if (cache->size > cache->capacity) {
            Node* tailNode = removeTail(cache);
            cache->hashTable[tailNode->key] = NULL;
            free(tailNode);
            cache->size--;
        }
    }
}

// Free memory used by the cache
void lRUCacheFree(LRUCache* cache) {
    Node* current = cache->head;
    while (current) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(cache->hashTable);
    free(cache);
}

// Example usage
int main() {
    LRUCache* cache = lRUCacheCreate(2);

    lRUCachePut(cache, 1, 1);
    lRUCachePut(cache, 2, 2);
    printf("%d\n", lRUCacheGet(cache, 1)); // returns 1

    lRUCachePut(cache, 3, 3); // evicts key 2
    printf("%d\n", lRUCacheGet(cache, 2)); // returns -1 (not found)

    lRUCachePut(cache, 4, 4); // evicts key 1
    printf("%d\n", lRUCacheGet(cache, 1)); // returns -1 (not found)
    printf("%d\n", lRUCacheGet(cache, 3)); // returns 3
    printf("%d\n", lRUCacheGet(cache, 4)); // returns 4

    lRUCacheFree(cache);
    return 0;
}
