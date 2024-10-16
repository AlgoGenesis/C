#include <stdio.h>

void build_segment_tree(int* arr, int* seg_tree, int n) {
    // Insert leaf nodes in tree
    for (int i = 0; i < n; i++) {
        seg_tree[n + i] = arr[i];
    }
    
    // Build the tree by calculating parents
    for (int i = n - 1; i > 0; i--) {
        seg_tree[i] = seg_tree[2 * i] + seg_tree[2 * i + 1];
    }
}
