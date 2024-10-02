#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
#define EMPTY -1

// Hash table declaration
int hashTable[TABLE_SIZE];

// Initialize the hash table with -1 (indicating that it's empty)
void initializeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = EMPTY;
    }
}

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert a key into the hash table using quadratic probing
void insert(int key) {
    int index = hashFunction(key);
    int i = 0;
    
    // Check for collision and resolve using quadratic probing
    while (hashTable[(index + i * i) % TABLE_SIZE] != EMPTY) {
        i++;
        if (i == TABLE_SIZE) { // If table is full, cannot insert
            printf("Hash table is full, cannot insert key: %d\n", key);
            return;
        }
    }
    
    // Insert key when an empty slot is found
    hashTable[(index + i * i) % TABLE_SIZE] = key;
}

// Search for a key in the hash table
int search(int key) {
    int index = hashFunction(key);
    int i = 0;
    
    // Traverse the hash table using quadratic probing sequence
    while (hashTable[(index + i * i) % TABLE_SIZE] != EMPTY) {
        if (hashTable[(index + i * i) % TABLE_SIZE] == key) {
            return (index + i * i) % TABLE_SIZE; // Key found
        }
        i++;
        if (i == TABLE_SIZE) {
            return -1; // Key not found, looped around
        }
    }
    return -1; // Key not found
}

// Delete a key from the hash table
void deleteKey(int key) {
    int index = search(key);
    if (index == -1) {
        printf("Key %d not found in the hash table.\n", key);
    } else {
        hashTable[index] = EMPTY;
        printf("Key %d deleted from the hash table.\n", key);
    }
}

// Display the hash table
void display() {
    printf("Hash table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == EMPTY) {
            printf("Slot %d: EMPTY\n", i);
        } else {
            printf("Slot %d: %d\n", i, hashTable[i]);
        }
    }
}

int main() {
    initializeTable();

    // Insert keys into hash table
    insert(23);
    insert(43);
    insert(13);
    insert(27);
    insert(37);
    insert(33);

    // Display the hash table
    display();

    // Search for a key
    int key = 27;
    int index = search(key);
    if (index != -1) {
        printf("Key %d found at index %d.\n", key, index);
    } else {
        printf("Key %d not found.\n", key);
    }

    // Delete a key
    deleteKey(13);
    
    // Display the hash table after deletion
    display();

    return 0;
}