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
