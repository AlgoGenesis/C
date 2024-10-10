#include <stdio.h>

void update_fenwick_tree(int* fenwick_tree, int n, int index, int value);

void build_fenwick_tree(int* arr, int* fenwick_tree, int n) {
    // Initialize all values in the fenwick tree to 0
    for (int i = 0; i <= n; i++) {
        fenwick_tree[i] = 0;
    }

    // Build the tree using updates
    for (int i = 0; i < n; i++) {
        update_fenwick_tree(fenwick_tree, n, i, arr[i]);
    }
}
