#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 100000

int parent[MAX_ELEMENTS];
int rank[MAX_ELEMENTS];

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
    } else if (rank[xroot] > rank[yroot]) {
        parent[yroot] = xroot; // Connect the root of y's set to the root of x's set
    } else {
        parent[yroot] = xroot; // Connect the root of y's set to the root of x's set
        rank[xroot]++;        // Increment the rank of x's root
    }
}

int main() {
    // Initialize the parent and rank arrays
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        parent[i] = i;
        rank[i] = 0;
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

    return 0;
}