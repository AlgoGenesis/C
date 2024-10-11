# Fenwick Tree - Update

## Description
This folder contains the code to update values in a Fenwick Tree (Binary Indexed Tree). Updates are done in `O(log n)` time.

## File: `update_fenwick_tree.c`

### Function:

```c
void update_fenwick_tree(int* fenwick_tree, int n, int index, int value);
```
- **fenwick_tree**: The Fenwick Tree.
- **n**: The size of the original array.
- **index**: The index to update in the original array.
- **value**: The new value to add at `index`.

### Explanation:
- This function updates the tree by adding the new value to the given index and propagating the change upwards.
- Fenwick Tree uses 1-based indexing, so the `index` is incremented by 1 before updating.

## Usage Example:
```c
update_fenwick_tree(fenwick_tree, n, 3, 10); // Updates index 3 by adding 10
```