#include <stdio.h>
#include <stdlib.h>

#define EMPTY -1  // Indicator for empty slots

typedef struct HashTable {
    int *table;
    int size;
} HashTable;

// Function to create and initialize the hash table
HashTable* createHashTable(int size) {
    HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
    ht->size = size;
    ht->table = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        ht->table[i] = EMPTY;  // Mark all slots as empty
    }
    return ht;
}

// Hash function to get an index
int hashFunction(int key, int size) {
    return key % size;
}

// Insert function using linear probing
void insert(HashTable *ht, int key) {
    int index = hashFunction(key, ht->size);
    int originalIndex = index;

    // If the slot is occupied, probe to the next slot
    while (ht->table[index] != EMPTY) {
        index = (index + 1) % ht->size;  // Move to the next slot in a circular manner
        if (index == originalIndex) {  // If we've gone through the entire table
            printf("Hash table is full!\n");
            return;
        }
    }
    ht->table[index] = key;  // Place the key in the found empty slot
    printf("Inserted %d at index %d\n", key, index);
}

// Search function
int search(HashTable *ht, int key) {
    int index = hashFunction(key, ht->size);
    int originalIndex = index;

    while (ht->table[index] != EMPTY) {
        if (ht->table[index] == key) {
            return 1;  // Key found
        }
        index = (index + 1) % ht->size;  // Probe to the next slot
        if (index == originalIndex) {
            return 0;  // Full loop completed, key not found
        }
    }
    return 0;  // Empty slot found, key not present
}

// Display the hash table
void display(HashTable *ht) {
    for (int i = 0; i < ht->size; i++) {
        if (ht->table[i] != EMPTY) {
            printf("Index %d: %d\n", i, ht->table[i]);
        } else {
            printf("Index %d: Empty\n", i);
        }
    }
}

// Free memory allocated for the hash table
void freeHashTable(HashTable *ht) {
    free(ht->table);
    free(ht);
}

int main() {
    HashTable *ht = createHashTable(7);  // Create a hash table of size 7

    insert(ht, 10);
    insert(ht, 3);
    insert(ht, 17);
    insert(ht, 20);
    insert(ht, 6);

    printf("\nHash Table:\n");
    display(ht);

    // Search for a key
    int key = 17;
    if (search(ht, key)) {
        printf("\n%d is found in the hash table!\n", key);
    } else {
        printf("\n%d is not found in the hash table.\n", key);
    }

    // Free memory
    freeHashTable(ht);

    return 0;
}
