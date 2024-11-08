#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TABLE_SIZE 100
#define DELETED -1

// Define a structure for storing elements in the hash table
typedef struct {
    int key;
    int value;
    int probe_distance;
} HashEntry;

HashEntry* hashTable[TABLE_SIZE];

// Hash function to calculate the index
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Initialize the hash table
void initializeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

// Insert an element into the hash table
void insert(int key, int value) {
    int index = hashFunction(key);
    int probe_distance = 0;
    HashEntry* newEntry = (HashEntry*)malloc(sizeof(HashEntry));
    newEntry->key = key;
    newEntry->value = value;
    newEntry->probe_distance = 0;

    while (hashTable[index] != NULL && hashTable[index]->key != DELETED) {
        if (hashTable[index]->probe_distance < probe_distance) {
            // Swap the current entry with the new entry if its probe distance is smaller
            HashEntry* temp = hashTable[index];
            hashTable[index] = newEntry;
            newEntry = temp;
            probe_distance = newEntry->probe_distance;
        }
        // Increment probe distance and find next index
        index = (index + 1) % TABLE_SIZE;
        probe_distance++;
    }

    hashTable[index] = newEntry;
    hashTable[index]->probe_distance = probe_distance;
}

// Search for an element in the hash table
int search(int key) {
    int index = hashFunction(key);
    int probe_distance = 0;

    while (hashTable[index] != NULL) {
        if (hashTable[index]->key == key) {
            return hashTable[index]->value;
        }
        if (hashTable[index]->probe_distance < probe_distance) {
            break;
        }
        index = (index + 1) % TABLE_SIZE;
        probe_distance++;
    }
    return -1; // Key not found
}

// Delete an element from the hash table
void delete(int key) {
    int index = hashFunction(key);
    int probe_distance = 0;

    while (hashTable[index] != NULL) {
        if (hashTable[index]->key == key) {
            hashTable[index]->key = DELETED;
            hashTable[index]->value = 0;
            hashTable[index]->probe_distance = 0;
            return;
        }
        if (hashTable[index]->probe_distance < probe_distance) {
            break;
        }
        index = (index + 1) % TABLE_SIZE;
        probe_distance++;
    }
}

// Display the hash table
void displayTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != NULL && hashTable[i]->key != DELETED) {
            printf("Index %d: Key = %d, Value = %d, Probe Distance = %d\n", i, hashTable[i]->key, hashTable[i]->value, hashTable[i]->probe_distance);
        }
    }
}

int main() {
    initializeTable();
    insert(10, 100);
    insert(20, 200);
    insert(30, 300);
    insert(40, 400);
    insert(15, 150); // Causes probing with Robin Hood logic

    printf("Hash Table:\n");
    displayTable();

    printf("Searching for key 20: %d\n", search(20));
    printf("Searching for key 40: %d\n", search(40));

    printf("Deleting key 20...\n");
    delete(20);
    printf("Searching for key 20: %d\n", search(20));

    return 0;
}
