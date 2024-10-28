#include <stdio.h>

void build_fenwick_tree(int* arr, int* fenwick_tree, int n) {
    // Initialize all values in the Fenwick Tree to 0
    for (int i = 0; i <= n; i++) {
        fenwick_tree[i] = 0;
    }

    // Build the tree by directly applying the update logic
    for (int i = 0; i < n; i++) {
        int index = i + 1;  // Fenwick Tree is 1-indexed

        while (index <= n) {
            fenwick_tree[index] += arr[i];
            index += index & -index;
        }
    }
}
