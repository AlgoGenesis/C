# Segment Tree

## Overview
A Segment Tree is a data structure used to efficiently handle range queries (like sum, min, or max) and updates on an array in `O(log n)` time. It is particularly useful when there are frequent updates and queries over a range of elements in the array.

## File Structure
The Segment Tree is implemented with separate files for building the tree, updating elements, and querying ranges.

```
/SegmentTree/
  |-- build_segment_tree.c    # Builds the Segment Tree
  |-- update_segment_tree.c   # Updates a value in the Segment Tree
  |-- query_segment_tree.c    # Queries a range in the Segment Tree
  |-- main.c     # Example usage of the Segment Tree
```

## Functions

### 1. `build_segment_tree.c`
Builds the segment tree from an array.
```c
void build_segment_tree(int* arr, int* seg_tree, int n);
```
- **arr**: The input array.
- **seg_tree**: The segment tree (size `2 * n`).
- **n**: The size of the array.

### 2. `update_segment_tree.c`
Updates a value at a specific index in the Segment Tree.
```c
void update_segment_tree(int* seg_tree, int n, int index, int value);
```
- **seg_tree**: The segment tree.
- **n**: The size of the original array.
- **index**: The index to update in the original array.
- **value**: The new value to update at `index`.

### 3. `query_segment_tree.c`
Performs a range query on the Segment Tree.
```c
int query_segment_tree(int* seg_tree, int n, int left, int right);
```
- **seg_tree**: The segment tree.
- **n**: The size of the original array.
- **left**: The starting index of the query (inclusive).
- **right**: The ending index of the query (exclusive).

## Example
The `main.c` file demonstrates how to use the Segment Tree:

```c
#include <stdio.h>
#include "build_segment_tree.c"
#include "update_segment_tree.c"
#include "query_segment_tree.c"

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Segment tree has 2*n space
    int seg_tree[2 * n];
    
    build_segment_tree(arr, seg_tree, n);
    
    printf("Sum of range [1, 5): %d\n", query_segment_tree(seg_tree, n, 1, 5));
    
    update_segment_tree(seg_tree, n, 3, 10);  // Update index 3 to 10
    printf("Updated sum of range [1, 5): %d\n", query_segment_tree(seg_tree, n, 1, 5));

    return 0;
}
```

