# Segment Tree - Build

## Description
This folder contains the code to build a Segment Tree from an array. The Segment Tree is built in `O(n)` time.

## File: `build_segment_tree.c`

### Function:
```c
void build_segment_tree(int* arr, int* seg_tree, int n);
```
- **arr**: The input array.
- **seg_tree**: The segment tree (size `2 * n`).
- **n**: The size of the array.

### Explanation:
- The array elements are placed in the leaf nodes of the segment tree.
- Internal nodes store results of operations (sum, min, max, etc.).
- Once the leaf nodes are initialized, the parent nodes are computed recursively.

## Usage Example:
```c
int arr[] = {1, 3, 5, 7, 9, 11};
int seg_tree[2 * n];
build_segment_tree(arr, seg_tree, n);
```
