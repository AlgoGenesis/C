#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
#define EMPTY -1

int hashTable[TABLE_SIZE];

void initializeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = EMPTY;
    }
}

int primaryHash(int key) {
    return key % TABLE_SIZE;
}

int secondaryHash(int key) {
    return (7 - (key % 7));  
}
void insert(int key) {
    int index = primaryHash(key);
    int stepSize = secondaryHash(key);
    
    int originalIndex = index;

    while (hashTable[index] != EMPTY) {
        index = (index + stepSize) % TABLE_SIZE; 
        if (index == originalIndex) { 
            printf("Hash table is full, cannot insert key: %d\n", key);
            return;
        }
    }

  
    hashTable[index] = key;
}


int search(int key) {
    int index = primaryHash(key);
    int stepSize = secondaryHash(key);

    int originalIndex = index;
    
    while (hashTable[index] != EMPTY) {
        if (hashTable[index] == key) {
            return index; 
        }
        index = (index + stepSize) % TABLE_SIZE;
        if (index == originalIndex) {
            return -1; 
        }
    }
    return -1; 
}

void deleteKey(int key) {
    int index = search(key);
    if (index == -1) {
        printf("Key %d not found in the hash table.\n", key);
    } else {
        hashTable[index] = EMPTY;
        printf("Key %d deleted from the hash table.\n", key);
    }
}

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

    // Insert keys
    insert(23);
    insert(43);
    insert(13);
    insert(27);
    insert(37);

    // Display the hash table
    display();

    // Searching
    int key = 27;
    int index = search(key);
    if (index != -1) {
        printf("Key %d found at index %d.\n", key, index);
    } else {
        printf("Key %d not found.\n", key);
    }

    deleteKey(13);
    
    // Display the hash table after deletion
    display();

    return 0;
}