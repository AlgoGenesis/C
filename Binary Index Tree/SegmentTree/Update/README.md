# Segment Tree - Update

## Description
This folder contains the code to update values in the Segment Tree. Updates are done in `O(log n)` time.

## File: `update_segment_tree.c`

### Function:
```c
void update_segment_tree(int* seg_tree, int n, int index, int value);
```
- **seg_tree**: The segment tree.
- **n**: The size of the original array.
- **index**: The index to update in the original array.
- **value**: The new value to update at `index`.

### Explanation:
- The value at the given index is updated.
- The update is propagated to all parent nodes in the tree to ensure that the tree maintains correct range query results.

## Usage Example:
```c
update_segment_tree(seg_tree, n, 3, 10); // Updates index 3 to 10
