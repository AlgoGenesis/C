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

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    int i = 0;
    
    while (hashTable[(index + i * i) % TABLE_SIZE] != EMPTY) {
        i++;
        if (i == TABLE_SIZE) { 
            printf("Hash table is full, cannot insert key: %d\n", key);
            return;
        }
    }
    
    hashTable[(index + i * i) % TABLE_SIZE] = key;
}


int search(int key) {
    int index = hashFunction(key);
    int i = 0;
    
    while (hashTable[(index + i * i) % TABLE_SIZE] != EMPTY) {
        if (hashTable[(index + i * i) % TABLE_SIZE] == key) {
            return (index + i * i) % TABLE_SIZE; 
        }
        i++;
        if (i == TABLE_SIZE) {
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

    deleteKey(13);
    
    // Display the hash table after deletion
    display();

    return 0;
}