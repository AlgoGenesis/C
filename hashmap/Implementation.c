#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list (for chaining)
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

// Define the structure for the Hashmap
typedef struct HashMap {
    int size;         // Size of the hashmap (number of buckets)
    Node** buckets;   // Array of pointers to the linked lists (buckets)
} HashMap;

// Create a new node (for the linked list)
Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Create the HashMap
HashMap* createHashMap(int size) {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->size = size;
    map->buckets = (Node**)malloc(size * sizeof(Node*));

    // Initialize all buckets to NULL
    for (int i = 0; i < size; i++) {
        map->buckets[i] = NULL;
    }

    return map;
}

// Hash function to map a key to an index based on table size (modulo operator)
int hashFunction(int key, int size) {
    return key % size;
}

// Insert a key-value pair into the HashMap
void insert(HashMap* map, int key, int value) {
    int index = hashFunction(key, map->size);
    Node* newNode = createNode(key, value);

    // If there's no collision, insert the node at the bucket
    if (map->buckets[index] == NULL) {
        map->buckets[index] = newNode;
    } else {
        // Handle collision using chaining (linked list)
        Node* current = map->buckets[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    printf("Inserted key: %d, value: %d at index: %d\n", key, value, index);
}

// Search for a value by key in the HashMap
int search(HashMap* map, int key) {
    int index = hashFunction(key, map->size);
    Node* current = map->buckets[index];

    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }

    return -1;  // Key not found
}

// Delete a key-value pair from the HashMap
void Delete(HashMap* map, int key) {
    int index = hashFunction(key, map->size);
    Node* current = map->buckets[index];
    Node* prev = NULL;

    while (current != NULL) {
        if (current->key == key) {
            if (prev == NULL) {
                map->buckets[index] = current->next;  // Remove head of the list
            } else {
                prev->next = current->next;  // Bypass the node to delete it
            }
            free(current);
            printf("Key %d deleted\n", key);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Key %d not found\n", key);
}

// Free the memory used by the HashMap
void freeHashMap(HashMap* map) {
    for (int i = 0; i < map->size; i++) {
        Node* current = map->buckets[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(map->buckets);
    free(map);
}

// Main function to demonstrate the usage
int main() {
    // Create a HashMap with 10 buckets
    HashMap* map = createHashMap(10);

    // Insert some key-value pairs
    insert(map, 1, 10);
    insert(map, 2, 20);
    insert(map, 12, 120);  // This will collide with key 2
    insert(map, 22, 220);  // Another collision example

    // Search for a key
    int value = search(map, 12);
    if (value != -1) {
        printf("Key 12 found with value: %d\n", value);
    } else {
        printf("Key 12 not found\n");
    }

    // Delete a key-value pair
    Delete(map, 2);
    Delete(map, 22);

    // Free the memory used by the HashMap
    freeHashMap(map);

    return 0;
}
