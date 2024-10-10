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
