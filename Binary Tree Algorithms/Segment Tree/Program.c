#include <stdio.h>
#include <limits.h>

#define N 100000

int a[N];          // Input array
int tree[4 * N];   // Segment tree to store max values for each segment

// Function to build the segment tree
void build(int node, int s, int e) {
    if (s == e) {
        // Leaf node: store the value from array
        tree[node] = a[s];
        return;
    }
    
    int mid = (s + e) / 2;
    // Build the left child
    build(2 * node, s, mid);
    // Build the right child
    build(2 * node + 1, mid + 1, e);
    
    // Internal node: store the maximum of both children
    tree[node] = (tree[2 * node] > tree[2 * node + 1]) ? tree[2 * node] : tree[2 * node + 1];
}

// Function to get the maximum value in a segment [l, r]
int query(int node, int s, int e, int l, int r) {
    if (s > r || e < l) {
        // Segment is out of range
        return INT_MIN;
    }
    
    if (l <= s && e <= r) {
        // Segment is completely inside range
        return tree[node];
    }
    
    int mid = (s + e) / 2;
    // Query the left and right children
    int q1 = query(2 * node, s, mid, l, r);
    int q2 = query(2 * node + 1, mid + 1, e, l, r);
    // Return the maximum value found
    return (q1 > q2) ? q1 : q2;
}

// Function to update the segment tree
void update(int node, int s, int e, int ind, int val) {
    if (s == e) {
        // Leaf node: update the value in array and tree
        a[s] = val;
        tree[node] = val;
        return;
    }
    
    int mid = (s + e) / 2;
    // Check if we need to update the left or right child
    if (ind <= mid) {
        update(2 * node, s, mid, ind, val);
    } else {
        update(2 * node + 1, mid + 1, e, ind, val);
    }
    
    // Update the current node after updating children
    tree[node] = (tree[2 * node] > tree[2 * node + 1]) ? tree[2 * node] : tree[2 * node + 1];
}

int main() {
    int n, q;
    
    // Input size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    // Input the array elements
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Build the segment tree
    build(1, 0, n - 1);
    
    // Input number of queries
    printf("Enter the number of queries: ");
    scanf("%d", &q);
    
    for (int i = 0; i < q; i++) {
        int type;
        printf("\nChoose query type (1 for range max query, 2 for update): ");
        scanf("%d", &type);
        
        if (type == 1) {
            // Range maximum query
            int l, r;
            printf("Enter range (l r): ");
            scanf("%d %d", &l, &r);
            int result = query(1, 0, n - 1, l, r);
            printf("Maximum in range [%d, %d] is: %d\n", l, r, result);
        } else if (type == 2) {
            // Update query
            int ind, val;
            printf("Enter index and new value (ind val): ");
            scanf("%d %d", &ind, &val);
            update(1, 0, n - 1, ind, val);
            printf("Updated index %d to value %d\n", ind, val);
        } else {
            printf("Invalid query type.\n");
        }
    }
    
    return 0;
}
