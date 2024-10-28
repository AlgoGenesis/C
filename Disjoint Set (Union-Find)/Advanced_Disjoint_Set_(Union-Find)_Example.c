#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100000

int parent[MAX_NODES];
int rank[MAX_NODES];
int size[MAX_NODES]; // Size of each set

/**
 * Find the root of the set that the given element `x` belongs to.
 * This function uses path compression to flatten the tree and
 * improve the efficiency of subsequent find operations.
 *
 * @param x The element to find the root of.
 * @return The root of the set that `x` belongs to.
 */
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // Path compression
    }
    return parent[x];
}

/**
 * Union two sets by connecting the root of one set to the root of the other.
 * The union operation uses union by rank to maintain a balanced tree representation.
 * It also updates the size of the new set.
 *
 * @param x One of the elements to be unioned.
 * @param y The other element to be unioned.
 */
void unionSet(int x, int y) {
    int xroot = find(x);
    int yroot = find(y);

    if (xroot == yroot) {
        return; // Elements are already in the same set
    }

    if (rank[xroot] < rank[yroot]) {
        parent[xroot] = yroot; // Connect the root of x's set to the root of y's set
        size[yroot] += size[xroot];
    } else if (rank[xroot] > rank[yroot]) {
        parent[yroot] = xroot; // Connect the root of y's set to the root of x's set
        size[xroot] += size[yroot];
    } else {
        parent[yroot] = xroot; // Connect the root of y's set to the root of x's set
        rank[xroot]++;        // Increment the rank of x's root
        size[xroot] += size[yroot];
    }
}

/**
 * Check if two elements are in the same set.
 *
 * @param x One of the elements to check.
 * @param y The other element to check.
 * @return 1 if the elements are in the same set, 0 otherwise.
 */
int sameSet(int x, int y) {
    return find(x) == find(y);
}

/**
 * Get the size of the set that the given element belongs to.
 *
 * @param x The element to get the set size for.
 * @return The size of the set that `x` belongs to.
 */
int getSetSize(int x) {
    return size[find(x)];
}

int main() {
    // Initialize the parent, rank, and size arrays
    for (int i = 0; i < MAX_NODES; i++) {
        parent[i] = i;
        rank[i] = 0;
        size[i] = 1;
    }

    // Example usage
    unionSet(1, 2);
    unionSet(2, 3);
    unionSet(4, 5);
    unionSet(6, 7);
    unionSet(3, 7);

    printf("The root of 1 is %d\n", find(1));
    printf("The root of 3 is %d\n", find(3));
    printf("The root of 6 is %d\n", find(6));

    printf("Are 1 and 3 in the same set? %d\n", sameSet(1, 3));
    printf("Are 1 and 6 in the same set? %d\n", sameSet(1, 6));

    printf("The size of the set containing 1 is %d\n", getSetSize(1));
    printf("The size of the set containing 3 is %d\n", getSetSize(3));
    printf("The size of the set containing 6 is %d\n", getSetSize(6));

    return 0;
}