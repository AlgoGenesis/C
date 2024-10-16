#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the graph/tree
typedef struct Node {
    int value;     // The value of the node (or the score)
    int n_children;  // Number of children
    struct Node** children;  // Array of pointers to child nodes
} Node;

// Function to create a new node
Node* createNode(int value, int n_children) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->n_children = n_children;
    newNode->children = (Node**)malloc(n_children * sizeof(Node*));
    return newNode;
}

// Compare function for sorting nodes by value (descending order)
int compareNodes(const void* a, const void* b) {
    Node* nodeA = *(Node**)a;
    Node* nodeB = *(Node**)b;
    return nodeB->value - nodeA->value; // Sort in descending order
}

// Function for beam search
void beamSearch(Node* root, int beam_width) {
    Node** beam = (Node**)malloc(beam_width * sizeof(Node*));
    int beam_size = 0;

    beam[beam_size++] = root;

    while (beam_size > 0) {
        printf("Current Beam: ");
        for (int i = 0; i < beam_size; i++) {
            printf("%d ", beam[i]->value);
        }
        printf("\n");

        Node** next_beam = (Node**)malloc(beam_width * sizeof(Node*));
        int next_beam_size = 0;

        // Expand nodes in the current beam
        for (int i = 0; i < beam_size; i++) {
            Node* current = beam[i];

            // Add children to the next beam
            for (int j = 0; j < current->n_children; j++) {
                Node* child = current->children[j];
                if (child != NULL) { // Check for NULL before adding
                    if (next_beam_size < beam_width) {
                        next_beam[next_beam_size++] = child;
                    } else {
                        // Replace the lowest scoring node in the next beam if a better node is found
                        qsort(next_beam, next_beam_size, sizeof(Node*), compareNodes);
                        if (child->value > next_beam[next_beam_size - 1]->value) {
                            next_beam[next_beam_size - 1] = child;
                        }
                    }
                }
            }
        }

        // Sort the next beam and limit to the beam width
        qsort(next_beam, next_beam_size, sizeof(Node*), compareNodes);
        beam_size = next_beam_size < beam_width ? next_beam_size : beam_width;
        for (int i = 0; i < beam_size; i++) {
            beam[i] = next_beam[i];
        }

        free(next_beam);

        // If no more children to explore, stop the search
        if (beam_size == 0) {
            printf("Search Complete\n");
            break;
        }
    }

    free(beam);
}

// Function to free the memory allocated for the tree
void freeTree(Node* node) {
    if (node == NULL) return;
    for (int i = 0; i < node->n_children; i++) {
        freeTree(node->children[i]);
    }
    free(node->children);
    free(node);
}

// Main function
int main() {
    // Create a sample tree
    Node* root = createNode(10, 3);

    // Level 1 children
    root->children[0] = createNode(20, 2);
    root->children[1] = createNode(15, 2);
    root->children[2] = createNode(5, 2);

    // Level 2 children
    root->children[0]->children[0] = createNode(30, 0);
    root->children[0]->children[1] = createNode(25, 0);

    root->children[1]->children[0] = createNode(18, 0);
    root->children[1]->children[1] = createNode(12, 0);

    root->children[2]->children[0] = createNode(6, 0);
    root->children[2]->children[1] = createNode(2, 0);

    // Perform beam search with beam width of 2
    int beam_width = 2;
    printf("Beam Search with beam width = %d:\n", beam_width);
    beamSearch(root, beam_width);

    // Free the allocated memory
    freeTree(root);

    return 0;
}
