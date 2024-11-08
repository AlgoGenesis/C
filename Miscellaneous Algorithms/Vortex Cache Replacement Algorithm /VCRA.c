#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CACHE_SIZE 5  // Example cache size

typedef struct {
    int data;
    int frequency;   // Frequency counter
    time_t lastUsed; // Last used timestamp
} CacheEntry;

CacheEntry cache[CACHE_SIZE];

// Initialize the cache with default values
void initializeCache() {
    for (int i = 0; i < CACHE_SIZE; i++) {
        cache[i].data = -1;
        cache[i].frequency = 0;
        cache[i].lastUsed = 0;
    }
}

// Function to find data in the cache
int findInCache(int data) {
    for (int i = 0; i < CACHE_SIZE; i++) {
        if (cache[i].data == data) {
            cache[i].frequency++;
            cache[i].lastUsed = time(NULL);
            return i;
        }
    }
    return -1;
}

// Function to replace a cache entry based on frequency and LRU
void replaceInCache(int data) {
    int minFreqIndex = 0;
    for (int i = 1; i < CACHE_SIZE; i++) {
        if ((cache[i].frequency < cache[minFreqIndex].frequency) ||
            (cache[i].frequency == cache[minFreqIndex].frequency && cache[i].lastUsed < cache[minFreqIndex].lastUsed)) {
            minFreqIndex = i;
        }
    }
    cache[minFreqIndex].data = data;
    cache[minFreqIndex].frequency = 1;
    cache[minFreqIndex].lastUsed = time(NULL);
}

// Function to access the cache
void accessCache(int data) {
    int index = findInCache(data);
    if (index == -1) {
        printf("Cache miss for data %d. Replacing entry.\n", data);
        replaceInCache(data);
    } else {
        printf("Cache hit for data %d at index %d.\n", data, index);
    }
}

// Print cache state
void printCache() {
    printf("Cache State:\n");
    for (int i = 0; i < CACHE_SIZE; i++) {
        printf("Index %d: Data = %d, Frequency = %d, Last Used = %ld\n",
               i, cache[i].data, cache[i].frequency, cache[i].lastUsed);
    }
}

int main() {
    initializeCache();
    int accesses[] = {1, 2, 3, 4, 5, 1, 6, 2, 7, 8, 3, 1}; // Example access pattern

    for (int i = 0; i < sizeof(accesses) / sizeof(accesses[0]); i++) {
        accessCache(accesses[i]);
        printCache();
        printf("\n");
    }

    return 0;
}
