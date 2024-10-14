#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Structure for a node in the doubly linked list
typedef struct Node {
    struct Node *left, *right, *up, *down;
    struct ColumnNode *column;
} Node;

// Structure for a column node
typedef struct ColumnNode {
    Node head;
    int size;
    struct ColumnNode *left, *right;
} ColumnNode;

ColumnNode columns[MAX];
Node nodes[MAX];
int nodeCount = 0;
int solution[MAX];
int solutionCount = 0;

// Function to create a new node
Node* newNode(ColumnNode *col) {
    Node* node = &nodes[nodeCount++];
    node->left = node->right = node->up = node->down = node;
    node->column = col;
    return node;
}

// Function to link nodes in the doubly linked list
void linkNodes(Node* n1, Node* n2) {
    n1->right = n2;
    n2->left = n1;
}

// Covering a column
void cover(ColumnNode *col) {
    col->right->left = col->left;
    col->left->right = col->right;
    for (Node* row = col->head.down; row != &col->head; row = row->down) {
        for (Node* node = row->right; node != row; node = node->right) {
            node->down->up = node->up;
            node->up->down = node->down;
            node->column->size--;
        }
    }
}

// Uncovering a column
void uncover(ColumnNode *col) {
    for (Node* row = col->head.up; row != &col->head; row = row->up) {
        for (Node* node = row->left; node != row; node = node->left) {
            node->column->size++;
            node->down->up = node;
            node->up->down = node;
        }
    }
    col->right->left = col;
    col->left->right = col;
}

// Algorithm X (Dancing Links)
int search(int depth) {
    if (columns->right == columns) {
        for (int i = 0; i < depth; i++) {
            printf("%d ", solution[i]);
        }
        printf("\n");
        return 1;
    }

    // Choose the column with the smallest size (heuristic)
    ColumnNode* col = columns->right;
    for (ColumnNode* c = col->right; c != columns; c = c->right) {
        if (c->size < col->size) col = c;
    }

    cover(col);
    for (Node* row = col->head.down; row != &col->head; row = row->down) {
        solution[depth] = row - nodes;
        for (Node* node = row->right; node != row; node = node->right) {
            cover(node->column);
        }
        if (search(depth + 1)) return 1;
        for (Node* node = row->left; node != row; node = node->left) {
            uncover(node->column);
        }
    }
    uncover(col);
    return 0;
}

// Example usage for Sudoku or N-Queens can be added based on this structure

int main() {
    // Setup for the problem: Construct exact cover matrix and call search
    search(0);
    return 0;
}
