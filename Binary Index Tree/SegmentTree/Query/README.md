# Segment Tree - Query

## Description
This folder contains the code to perform range queries in a Segment Tree. Queries are processed in `O(log n)` time.

## File: `query_segment_tree.c`

### Function:
```c
int query_segment_tree(int* seg_tree, int n, int left, int right);
```
- **seg_tree**: The segment tree.
- **n**: The size of the original array.
- **left**: The starting index of the query (inclusive).
- **right**: The ending index of the query (exclusive).

### Explanation:
- This function computes the sum (or other operations like min/max) over a given range [left, right).
- The query is handled in `O(log n)` time by traversing both left and right boundaries toward their common ancestor in the tree.

## Usage Example:
```c
int result = query_segment_tree(seg_tree, n, 1, 5);
printf("Sum of range [1, 5): %d\n", result);
```