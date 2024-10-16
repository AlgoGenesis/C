#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

// Structure representing a node in the suffix tree
typedef struct SuffixTreeNode {
    struct SuffixTreeNode *children[MAX_CHAR];  // Pointers to child nodes
    struct SuffixTreeNode *suffixLink;          // Pointer for the suffix link
    int start;                                  // Starting index of the edge
    int *end;                                   // Ending index of the edge
    int suffixIndex;                            // Suffix index for leaf nodes
} Node;

char text[1000];                                // Input text
Node *root = NULL;                              // Root of the suffix tree
Node *lastNewNode = NULL, *activeNode = NULL;

int activeEdge = -1, activeLength = 0;
int remainingSuffixCount = 0;
int leafEnd = -1;
int *rootEnd = NULL, *splitEnd = NULL;
int size = -1;                                  // Length of the input text

Node *newNode(int start, int *end) {
    Node *node = (Node *)malloc(sizeof(Node));
    for (int i = 0; i < MAX_CHAR; i++)
        node->children[i] = NULL;
    node->suffixLink = root;
    node->start = start;
    node->end = end;
    node->suffixIndex = -1;
    return node;
}

// Function to extend the suffix tree at position `pos`
void extendSuffixTree(int pos) {
    leafEnd = pos;
    remainingSuffixCount++;
    lastNewNode = NULL;

    while (remainingSuffixCount > 0) {
        if (activeLength == 0)
            activeEdge = pos;

        if (activeNode->children[text[activeEdge]] == NULL) {
            // Create a new leaf node
            activeNode->children[text[activeEdge]] = newNode(pos, &leafEnd);

            if (lastNewNode != NULL) {
                lastNewNode->suffixLink = activeNode;
                lastNewNode = NULL;
            }
        } else {
            Node *next = activeNode->children[text[activeEdge]];
            int edgeLength = *(next->end) - next->start + 1;

            if (activeLength >= edgeLength) {
                activeEdge += edgeLength;
                activeLength -= edgeLength;
                activeNode = next;
                continue;
            }

            if (text[next->start + activeLength] == text[pos]) {
                if (lastNewNode != NULL && activeNode != root) {
                    lastNewNode->suffixLink = activeNode;
                    lastNewNode = NULL;
                }
                activeLength++;
                break;
            }

            splitEnd = (int *)malloc(sizeof(int));
            *splitEnd = next->start + activeLength - 1;

            // Create a new internal node (split node)
            Node *split = newNode(next->start, splitEnd);
            activeNode->children[text[activeEdge]] = split;

            split->children[text[pos]] = newNode(pos, &leafEnd);
            next->start += activeLength;
            split->children[text[next->start]] = next;

            if (lastNewNode != NULL)
                lastNewNode->suffixLink = split;

            lastNewNode = split;
        }

        remainingSuffixCount--;

        if (activeNode == root && activeLength > 0) {
            activeLength--;
            activeEdge = pos - remainingSuffixCount + 1;
        } else if (activeNode != root) {
            activeNode = activeNode->suffixLink;
        }
    }
}

// Set suffix index in the leaves via depth-first search (DFS)
void setSuffixIndexByDFS(Node *n, int labelHeight) {
    if (n == NULL)
        return;

    int leaf = 1;
    for (int i = 0; i < MAX_CHAR; i++) {
        if (n->children[i] != NULL) {
            leaf = 0;
            setSuffixIndexByDFS(n->children[i], labelHeight + *(n->children[i]->end) - n->children[i]->start + 1);
        }
    }
    if (leaf == 1) {
        n->suffixIndex = size - labelHeight;
    }
}

// Build the suffix tree
void buildSuffixTree() {
    size = strlen(text);
    rootEnd = (int *)malloc(sizeof(int));
    *rootEnd = -1;
    root = newNode(-1, rootEnd);
    activeNode = root;

    for (int i = 0; i < size; i++) {
        extendSuffixTree(i);
    }

    // Set suffix indexes
    setSuffixIndexByDFS(root, 0);
}

// Free the tree by post-order traversal
void freeSuffixTreeByPostOrder(Node *n) {
    if (n == NULL)
        return;

    for (int i = 0; i < MAX_CHAR; i++) {
        if (n->children[i] != NULL) {
            freeSuffixTreeByPostOrder(n->children[i]);
        }
    }
    if (n->suffixIndex == -1)
        free(n->end);
    free(n);
}

// Print the suffix tree
void printSuffixTree(Node *n, int labelHeight) {
    if (n == NULL)
        return;

    if (n->start != -1) {
        for (int i = n->start; i <= *(n->end); i++)
            printf("%c", text[i]);
        if (n->suffixIndex == -1)
            printf(" [internal]\n");
        else
            printf(" [leaf: %d]\n", n->suffixIndex);
    }

    for (int i = 0; i < MAX_CHAR; i++) {
        if (n->children[i] != NULL) {
            printSuffixTree(n->children[i], labelHeight + *(n->children[i]->end) - n->children[i]->start + 1);
        }
    }
}

int main() {
    printf("Enter text: ");
    scanf("%s", text);

    buildSuffixTree();
    printf("\nSuffix Tree for '%s':\n", text);
    printSuffixTree(root, 0);
    
    freeSuffixTreeByPostOrder(root);

    return 0;
}
