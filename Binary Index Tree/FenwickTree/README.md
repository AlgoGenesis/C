# Fenwick Tree (Binary Indexed Tree)

## Overview
The Fenwick Tree (also known as a Binary Indexed Tree) is a data structure that provides an efficient way to handle cumulative frequency tables and perform range queries. It allows for point updates and prefix sum queries in `O(log n)` time.

## File Structure
The Fenwick Tree is implemented with separate files for building the tree, updating elements, and querying ranges.

```
/FenwickTree/
  |-- build_fenwick_tree.c    # Builds the Fenwick Tree
  |-- update_fenwick_tree.c   # Updates a value in the Fenwick Tree
  |-- query_fenwick_tree.c    # Queries a prefix sum in the Fenwick Tree
  |-- main.c     # Example usage of the Fenwick Tree
```

## Functions

### 1. `build_fenwick_tree.c`
Builds the Fenwick Tree from an array.
```c
void build_fenwick_tree(int* arr, int* fenwick_tree, int n);
```
- **arr**: The input array.
- **fenwick_tree**: The Fenwick Tree (size `n + 1`).
- **n**: The size of the array.

### 2. `update_fenwick_tree.c`
Updates a value at a specific index in the Fenwick Tree.
```c
void update_fenwick_tree(int* fenwick_tree, int n, int index, int value);
```
- **fenwick_tree**: The Fenwick Tree.
- **n**: The size of the original array.
- **index**: The index to update in the original array.
- **value**: The new value to update at `index`.

### 3. `query_fenwick_tree.c`
Performs a prefix sum query on the Fenwick Tree.
```c
int query_fenwick_tree(int* fenwick_tree, int index);
```
- **fenwick_tree**: The Fenwick Tree.
- **index**: The index to query the sum up to.

## Example
The `main.c` file demonstrates how to use the Fenwick Tree:

```c
#include <stdio.h>
#include "build_fenwick_tree.c"
#include "update_fenwick_tree.c"
#include "query_fenwick_tree.c"

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    int fenwick_tree[n + 1];
    
    build_fenwick_tree(arr, fenwick_tree, n);
    
    printf("Sum of range [0, 4): %d\n", query_fenwick_tree(fenwick_tree, 4 - 1));
    
    update_fenwick_tree(fenwick_tree, n, 3, 10);  // Update index 3 to 10
    printf("Updated sum of range [0, 4): %d\n", query_fenwick_tree(fenwick_tree, 4 - 1));

    return 0;
}
```
