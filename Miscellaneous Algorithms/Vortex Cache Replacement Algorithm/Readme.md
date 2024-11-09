# Vortex Cache Replacement Algorithm in C

This repository contains an implementation of the **Vortex Cache Replacement Algorithm** in the C programming language. This algorithm is designed to manage cache memory efficiently by tracking the frequency and recency of access for each cached item, providing a balance between frequently accessed items and those that have not been accessed recently.

## Overview

The Vortex Cache Replacement Algorithm focuses on optimizing cache usage by retaining frequently accessed items while also considering the age or time of the last access. This dual approach helps ensure that items in the cache are both relevant and frequently used, improving cache hit rates.

### Key Features
- **Frequency Tracking**: Tracks the number of accesses for each item in the cache.
- **Eviction Criteria**: Evicts items with the lowest access frequency and, in case of a tie, removes the oldest accessed item.
- **Age or Time Factor**: Adds a time-based metric to differentiate between items with the same frequency of access.

## Code Structure

The main components of the code include:

1. **`CacheItem` Struct**: Represents an item in the cache, holding its `data`, `frequency` of access, and `last_access_time`.
2. **`Cache` Struct**: Contains an array of `CacheItem` structs and a `current_time` field for tracking time.
3. **Initialization**: Initializes the cache with empty items and sets access frequency and times to initial values.
4. **Find Item Function**: Checks if an item is already in the cache.
5. **Eviction Function**: Determines which item to evict based on frequency and age.
6. **Access Function**: Updates the cache with a new access, managing frequency, and triggering eviction if needed.
7. **Print Function**: Displays the current state of the cache.

## Usage

The program simulates cache access by calling `accessItem` with different data values. This helps test the algorithm's ability to evict the least relevant items over time.

```c
// Example usage in main function:
accessItem(&cache, 1);
printCache(&cache);

accessItem(&cache, 2);
printCache(&cache);

// Access item 1 again to increase frequency
accessItem(&cache, 1);
printCache(&cache);

// Further accesses to test eviction
accessItem(&cache, 4);
accessItem(&cache, 5);
accessItem(&cache, 6);  // Should trigger eviction based on Vortex criteria
printCache(&cache);
