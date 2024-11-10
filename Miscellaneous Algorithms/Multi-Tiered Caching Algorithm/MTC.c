#include <stdio.h>
#include <stdlib.h>

#define L1_CACHE_SIZE 3
#define L2_CACHE_SIZE 5

typedef struct Cache {
    int *data;
    int size;
    int count;
} Cache;

// Initialize cache
Cache *initialize_cache(int size) {
    Cache *cache = (Cache *)malloc(sizeof(Cache));
    cache->data = (int *)malloc(size * sizeof(int));
    cache->size = size;
    cache->count = 0;
    return cache;
}

// Check if a value exists in cache and return its position
int find_in_cache(Cache *cache, int value) {
    for (int i = 0; i < cache->count; i++) {
        if (cache->data[i] == value) {
            return i;
        }
    }
    return -1;
}

// Add value to cache with FIFO replacement
void add_to_cache(Cache *cache, int value) {
    if (cache->count < cache->size) {
        cache->data[cache->count++] = value;
    } else {
        // Shift data and add new value at the end
        for (int i = 1; i < cache->size; i++) {
            cache->data[i - 1] = cache->data[i];
        }
        cache->data[cache->size - 1] = value;
    }
}

// Multi-tiered caching function
void multi_tiered_cache(Cache *L1, Cache *L2, int value) {
    int pos_in_L1 = find_in_cache(L1, value);
    int pos_in_L2 = find_in_cache(L2, value);

    if (pos_in_L1 != -1) {
        printf("Value %d found in L1 cache.\n", value);
    } else if (pos_in_L2 != -1) {
        printf("Value %d found in L2 cache. Moving to L1.\n", value);
        // Move from L2 to L1 cache
        add_to_cache(L1, value);
        // Remove from L2 (by shifting)
        for (int i = pos_in_L2; i < L2->count - 1; i++) {
            L2->data[i] = L2->data[i + 1];
        }
        L2->count--;
    } else {
        printf("Value %d not found in L1 or L2. Adding to L1 and L2.\n", value);
        add_to_cache(L1, value);
        add_to_cache(L2, value);
    }
}

// Free allocated memory for cache
void free_cache(Cache *cache) {
    free(cache->data);
    free(cache);
}

// Main function to test multi-tiered caching
int main() {
    Cache *L1 = initialize_cache(L1_CACHE_SIZE);
    Cache *L2 = initialize_cache(L2_CACHE_SIZE);

    int requests[] = {10, 20, 10, 30, 40, 50, 20, 60, 70, 10};
    int num_requests = sizeof(requests) / sizeof(requests[0]);

    for (int i = 0; i < num_requests; i++) {
        multi_tiered_cache(L1, L2, requests[i]);
    }

    // Free memory
    free_cache(L1);
    free_cache(L2);

    return 0;
}
