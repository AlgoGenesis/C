#include <stdio.h>
#include <stdlib.h>

// Defining a Node structure
typedef struct Node {
    int *soln;             // Array to hold the binary string
    int level;             // Current level in the binary string
    struct Node **child;   // Array of pointers to child nodes
    struct Node *parent;   // Pointer to the parent node
} Node;

// Utility function to create a new Node
Node* createNode(Node* parent, int level, int N) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->parent = parent;
    newNode->level = level;
    newNode->soln = (int*)malloc(N * sizeof(int));
    newNode->child = (Node**)malloc(2 * sizeof(Node*)); // Each node can have two children
    return newNode;
}

// Utility function to generate binary strings of length N
void generate(Node* n, int N) {
    // If the string is complete, print it
    if (n->level == N) {
        for (int i = 0; i < N; i++)
            printf("%d", n->soln[i]);
        printf("\n");
    } else {
        int l = n->level; // Current level
        
        // Iterate for binary values 0 and 1
        for (int i = 0; i <= 1; i++) {
            Node* x = createNode(n, l + 1, N); // Create a new node
            for (int k = 0; k < l; k++)
                x->soln[k] = n->soln[k]; // Copy solution from parent
            x->soln[l] = i; // Assign binary value
            generate(x, N); // Recursive call to generate further
            free(x->soln); // Free memory allocated for solution array
            free(x->child); // Free memory allocated for child pointer array
            free(x); // Free the node itself
        }
    }
}

int main() {
    int N;

    // User input for the length of binary strings
    printf("Enter the length of binary strings: ");
    scanf("%d", &N);

    // Create the root node
    Node* root = createNode(NULL, 0, N);

    // Generate binary strings starting from the root
    generate(root, N);

    // Free memory allocated for the root node
    free(root->soln);
    free(root->child);
    free(root);

    return 0;
}
