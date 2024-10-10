# Fenwick Tree - Query

## Description
This folder contains the code to perform prefix sum queries in a Fenwick Tree (Binary Indexed Tree). Queries are processed in `O(log n)` time.

## File: `query_fenwick_tree.c`

### Function:

```c
int query_fenwick_tree(int* fenwick_tree, int index);
```
- **fenwick_tree**: The Fenwick Tree.
- **index**: The index to query the sum up to (inclusive).

### Explanation:
- This function computes the prefix sum up to the given index.
- Fenwick Tree uses 1-based indexing, so the `index` is incremented by 1 before querying.

## Usage Example:
```c
int result = query_fenwick_tree(fenwick_tree, 4 - 1);
printf("Sum of range [0, 4): %d\n", result);
```