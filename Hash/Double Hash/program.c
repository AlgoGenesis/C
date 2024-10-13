#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
#define EMPTY -1
#define DELETED -2

// Hash table declaration
int hashTable[TABLE_SIZE];

void initializeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = EMPTY;
    }
}

// Primary hash function
int primaryHash(int key) {
    return key % TABLE_SIZE;
}

// Secondary hash function (for calculating the step size)
int secondaryHash(int key) {
    return (7 - (key % 7));  // Step size, typically based on prime number smaller than TABLE_SIZE
}

// Insert a key into the hash table using double hashing
void insert(int key) {
    int index = primaryHash(key);
    int stepSize = secondaryHash(key);
    int originalIndex = index;

    // Check for collision and resolve using double hashing
    while (hashTable[index] != EMPTY && hashTable[index] != DELETED) {
        index = (index + stepSize) % TABLE_SIZE; // Probe to the next index using step size
        if (index == originalIndex) { // Loop around; hash table is full
            printf("Hash table is full, cannot insert key: %d\n", key);
            return;
        }
    }

    // Insert key when an empty or deleted slot is found
    hashTable[index] = key;
    printf("Key %d inserted at index %d.\n", key, index);
}

// Search for a key in the hash table
int search(int key) {
    int index = primaryHash(key);
    int stepSize = secondaryHash(key);
    int originalIndex = index;
    
    // Traverse the hash table using the probing sequence
    while (hashTable[index] != EMPTY) {
        if (hashTable[index] == key) {
            return index; // Key found
        }
        index = (index + stepSize) % TABLE_SIZE;
        if (index == originalIndex) {
            return -1; // Key not found, looped around
        }
    }
    return -1; // Key not found
}

// Delete a key from the hash table (mark it as deleted)
void deleteKey(int key) {
    int index = search(key);
    if (index == -1) {
        printf("Key %d not found in the hash table.\n", key);
    } else {
        hashTable[index] = DELETED;
        printf("Key %d deleted from the hash table.\n", key);
    }
}

// Display the hash table
void display() {
    printf("Hash table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == EMPTY) {
            printf("Slot %d: EMPTY\n", i);
        } else if (hashTable[i] == DELETED) {
            printf("Slot %d: DELETED\n", i);
        } else {
            printf("Slot %d: %d\n", i, hashTable[i]);
        }
    }
}

int main() {
    initializeTable();

    // Insert keys
    insert(23);
    insert(43);
    insert(13);
    insert(27);
    insert(37);

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
