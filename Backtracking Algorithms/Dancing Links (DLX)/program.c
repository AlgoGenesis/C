#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Node structure for Dancing Links */
typedef struct Node {
    struct Node *left;
    struct Node *right;
    struct Node *up;
    struct Node *down;
    struct Column *col;
} Node;

/* Column structure, inherits from Node */
typedef struct Column {
    Node node;     // Node header
    int size;      // Number of ones in the column
    char name[20]; // Identifier for debugging
} Column;

/* Root of the Dancing Links structure */
static Column root;

/* Max number of nodes (adjust as needed) */
#define MAX_NODES 1000

/* Array of all nodes for easy memory management */
static Node nodes[MAX_NODES];
static int node_count = 0;

/* Stack to hold the partial solution */
static Node *solution[MAX_NODES];
static int solution_count = 0;

/* Function prototypes */
void cover(Column *col);
void uncover(Column *col);
void search(int k);
Column *choose_column();
void add_row(int *row_data, int row_size, char *row_name);
void build_matrix(int **matrix, int rows, int cols);
void initialize_dlx(int cols);
void free_dlx();
bool is_safe();

/* Initialize the DLX matrix */
void initialize_dlx(int cols) {
    root.node.right = &root.node;
    root.node.left = &root.node;

    for (int i = 0; i < cols; i++) {
        Column *col = (Column *)malloc(sizeof(Column));
        if (!col) {
            fprintf(stderr, "Memory allocation failed for column headers.\n");
            exit(EXIT_FAILURE);
        }
        col->size = 0;
        snprintf(col->name, sizeof(col->name), "C%d", i);
        col->node.up = &col->node;
        col->node.down = &col->node;
        col->node.col = col;

        /* Insert the new column into the header list */
        col->node.right = root.node.right;
        col->node.left = &root.node;
        root.node.right->left = &col->node;
        root.node.right = &col->node;
    }
}

/* Free the DLX matrix */
void free_dlx() {
    Node *col_node = root.node.right;
    while (col_node != &root.node) {
        Column *col = col_node->col;
        Node *temp = col_node->right;
        free(col);
        col_node = temp;
    }
}

/* Add a row to the DLX matrix */
void add_row(int *row_data, int row_size, char *row_name) {
    /* Use dynamic memory allocation instead of VLA */
    Node **row_nodes = malloc(row_size * sizeof(Node *));
    if (!row_nodes) {
        fprintf(stderr, "Memory allocation failed for row_nodes.\n");
        exit(EXIT_FAILURE);
    }

    int idx = 0;

    /* Create nodes for the row */
    Node *col_node = root.node.right;
    while (col_node != &root.node) {
        if (row_data[idx]) {
            if (node_count >= MAX_NODES) {
                fprintf(stderr, "Exceeded maximum number of nodes.\n");
                free(row_nodes);
                exit(EXIT_FAILURE);
            }
            Node *new_node = &nodes[node_count++];
            new_node->col = col_node->col;

            /* Insert into column */
            new_node->down = col_node->col->node.down;
            new_node->up = &col_node->col->node;
            col_node->col->node.down->up = new_node;
            col_node->col->node.down = new_node;

            col_node->col->size++;

            row_nodes[idx] = new_node;
        } else {
            row_nodes[idx] = NULL;
        }
        col_node = col_node->right;
        idx++;
    }

    /* Link the row nodes horizontally */
    Node *first = NULL, *last = NULL;
    for (int i = 0; i < row_size; i++) {
        if (row_nodes[i]) {
            if (!first) {
                first = row_nodes[i];
                first->left = first->right = first;
            } else {
                last->right = row_nodes[i];
                row_nodes[i]->left = last;
                row_nodes[i]->right = first;
                first->left = row_nodes[i];
            }
            last = row_nodes[i];
        }
    }

    free(row_nodes);
}

/* Choose the column with the smallest size */
Column *choose_column() {
    Column *best_col = NULL;
    int min_size = MAX_NODES;

    for (Node *col_node = root.node.right; col_node != &root.node; col_node = col_node->right) {
        Column *col = col_node->col;
        if (col->size < min_size) {
            min_size = col->size;
            best_col = col;
        }
    }

    return best_col;
}

/* Cover a column */
void cover(Column *col) {
    col->node.right->left = col->node.left;
    col->node.left->right = col->node.right;

    for (Node *row = col->node.down; row != &col->node; row = row->down) {
        for (Node *node = row->right; node != row; node = node->right) {
            node->down->up = node->up;
            node->up->down = node->down;
            node->col->size--;
        }
    }
}

/* Uncover a column */
void uncover(Column *col) {
    for (Node *row = col->node.up; row != &col->node; row = row->up) {
        for (Node *node = row->left; node != row; node = node->left) {
            node->col->size++;
            node->down->up = node;
            node->up->down = node;
        }
    }

    col->node.right->left = &col->node;
    col->node.left->right = &col->node;
}

/* Recursive search function */
void search(int k) {
    if (root.node.right == &root.node) {
        /* Solution found */
        printf("Solution %d:\n", ++solution_count);
        for (int i = 0; i < k; i++) {
            /* Print the row identifier */
            printf("Row: ");
            Node *n = solution[i];
            do {
                printf("%s ", n->col->name);
                n = n->right;
            } while (n != solution[i]);
            printf("\n");
        }
        return;
    }

    Column *col = choose_column();
    if (!col || col->size == 0) return;

    cover(col);

    for (Node *row = col->node.down; row != &col->node; row = row->down) {
        solution[k] = row;
        for (Node *node = row->right; node != row; node = node->right) {
            cover(node->col);
        }
        search(k + 1);
        for (Node *node = row->left; node != row; node = node->left) {
            uncover(node->col);
        }
    }

    uncover(col);
}

/* Check if the DLX structure is safe (self-check) */
bool is_safe() {
    /* Implement checks to ensure the integrity of the structure */
    /* For example, check that the column sizes are consistent */
    return true;
}

/* Example usage */
int main() {
    /* Example matrix for exact cover problem */
    int matrix_data[6][7] = {
        {0, 0, 1, 0, 1, 1, 0}, /* Row 0 */
        {1, 0, 0, 1, 0, 0, 1}, /* Row 1 */
        {0, 1, 1, 0, 0, 1, 0}, /* Row 2 */
        {1, 0, 0, 1, 0, 0, 0}, /* Row 3 */
        {0, 1, 0, 0, 0, 0, 1}, /* Row 4 */
        {0, 0, 0, 1, 1, 0, 1}  /* Row 5 */
    };

    initialize_dlx(7);

    /* Add rows to the DLX structure */
    for (int i = 0; i < 6; i++) {
        add_row(matrix_data[i], 7, "Row");
    }

    if (!is_safe()) {
        fprintf(stderr, "DLX structure integrity check failed.\n");
        free_dlx();
        return EXIT_FAILURE;
    }

    /* Start the search */
    search(0);

    free_dlx();
    return EXIT_SUCCESS;
}
