#include <stdio.h>

#define MAX 1000 // Maximum number of elements in the set

// Parent and rank arrays
int parent[MAX];
int rank[MAX];

// Function to initialize the union-find structure
void init() {
    for (int i = 0; i < MAX; i++) {
        parent[i] = i; // Each element is its own parent
        rank[i] = 0;    // Initial rank is zero
    }
}

// Find with path compression
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // Path compression
    }
    return parent[x];
}

// Union by rank
void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX; // Attach smaller tree to the root of larger tree
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY; // Attach smaller tree to the root of larger tree
        } else {
            parent[rootY] = rootX;  // Attach one tree under the other
            rank[rootX]++;           // Increase the rank of the new root
        }
    }
}

// Function to check if two elements are in the same subset
int connected(int x, int y) {
    return find(x) == find(y);
}

// Main function to demonstrate the union-find operations
int main() {
    init(); // Initialize the union-find structure
    
    // Example usage: union and find operations
    unionSets(1, 2);
    unionSets(2, 3);
    unionSets(4, 5);

    // Checking connectivity
    printf("1 and 3 are connected: %s\n", connected(1, 3) ? "Yes" : "No"); // Should be Yes
    printf("1 and 4 are connected: %s\n", connected(1, 4) ? "Yes" : "No"); // Should be No
    printf("4 and 5 are connected: %s\n", connected(4, 5) ? "Yes" : "No"); // Should be Yes
    
    return 0;
}

