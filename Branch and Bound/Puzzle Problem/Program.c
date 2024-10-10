#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 3  // Size of the puzzle (3x3 grid)

// Structure to store the coordinates of the blank tile (0)
typedef struct {
    int x, y;
} Position;

// Structure to represent a state of the puzzle
typedef struct Node {
    int puzzle[N][N]; // Current state of the puzzle
    Position blank;   // Position of the blank tile (0)
    int cost;         // Cost (number of misplaced tiles)
    int level;        // Level (number of moves so far)
    struct Node* parent; // Pointer to parent node for backtracking
} Node;

// Utility function to print a puzzle
void printPuzzle(int puzzle[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", puzzle[i][j]); // Print each tile
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if a position is within the puzzle's boundaries
int isWithinBounds(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

// Function to calculate the cost (number of misplaced tiles)
int calculateCost(int puzzle[N][N], int goal[N][N]) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (puzzle[i][j] && puzzle[i][j] != goal[i][j])
                count++; // Increment count for each misplaced tile
        }
    }
    return count;
}

// Function to create a new node
Node* createNode(int puzzle[N][N], Position blank, int level, Node* parent) {
    Node* node = (Node*)malloc(sizeof(Node)); // Allocate memory for a new node
    node->parent = parent; // Set the parent of the new node
    node->blank = blank;   // Set the position of the blank tile
    node->level = level;   // Set the current level (number of moves)

    // Copy the puzzle state from the given puzzle
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            node->puzzle[i][j] = puzzle[i][j];
        }
    }

    return node;
}

// Function to check if two puzzles are equal
int areEqual(int puzzle1[N][N], int puzzle2[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (puzzle1[i][j] != puzzle2[i][j]) {
                return 0; // Return 0 if any tile is different
            }
        }
    }
    return 1; // Return 1 if the puzzles are equal
}

// Moves for the blank tile (left, right, up, down)
int row[] = {0, 0, -1, 1};
int col[] = {-1, 1, 0, 0};

// Compare function for sorting nodes based on their total cost (level + heuristic)
int compare(const void* a, const void* b) {
    Node* nodeA = *(Node**)a;
    Node* nodeB = *(Node**)b;
    return (nodeA->cost + nodeA->level) - (nodeB->cost + nodeB->level);
}

// Branch and Bound algorithm to solve the puzzle
void solvePuzzle(int initial[N][N], Position blank, int goal[N][N]) {
    // Initialize the root node with the initial state
    Node* root = createNode(initial, blank, 0, NULL);
    root->cost = calculateCost(initial, goal); // Calculate the initial cost

    // List of open nodes (priority queue)
    Node** queue = (Node**)malloc(1000 * sizeof(Node*)); // Allocate memory for the queue
    int queueSize = 0; // Initialize the size of the queue

    // Add root to the queue
    queue[queueSize++] = root;

    while (queueSize > 0) {
        // Sort the queue based on total cost
        qsort(queue, queueSize, sizeof(Node*), compare);

        // Get the node with the lowest total cost
        Node* current = queue[0];

        // Remove the current node from the queue
        for (int i = 1; i < queueSize; i++) {
            queue[i - 1] = queue[i];
        }
        queueSize--;

        // If the current state is the goal state (cost == 0)
        if (current->cost == 0) {
            printf("Solution found in %d moves:\n", current->level);
            Node* solution = current;

            // Backtrack to print the solution path
            while (solution) {
                printPuzzle(solution->puzzle); // Print each step in the solution
                solution = solution->parent; // Move to the parent node
            }
            // Free memory
            free(queue);
            return;
        }

        // Generate all possible moves for the blank tile
        for (int i = 0; i < 4; i++) {
            int newX = current->blank.x + row[i]; // New x position
            int newY = current->blank.y + col[i]; // New y position

            if (isWithinBounds(newX, newY)) { // Check if the new position is valid
                // Create a new puzzle configuration by moving the blank tile
                Node* child = createNode(current->puzzle, current->blank, current->level + 1, current);
                int temp = child->puzzle[current->blank.x][current->blank.y];
                child->puzzle[current->blank.x][current->blank.y] = child->puzzle[newX][newY];
                child->puzzle[newX][newY] = temp;

                // Update the blank tile's position
                child->blank.x = newX;
                child->blank.y = newY;
                child->cost = calculateCost(child->puzzle, goal); // Calculate the new cost

                // Add the child to the queue
                queue[queueSize++] = child; // Increase the queue size
            }
        }

        // Free memory for the current node
        free(current);
    }

    // If no solution is found
    printf("No solution found.\n");
    free(queue);
}

// Function to read a puzzle from the user
void readPuzzle(int puzzle[N][N]) {
    printf("Enter the puzzle state (0 for blank tile):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &puzzle[i][j]); // Read each tile value
        }
    }
}

// Main function
int main() {
    int initial[N][N]; // Initial state of the puzzle
    int goal[N][N];    // Goal state of the puzzle

    Position blank; // Position of the blank tile

    // Read the initial puzzle state from the user
    readPuzzle(initial);

    // Find the position of the blank tile (0)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (initial[i][j] == 0) {
                blank.x = i; // Set x coordinate of blank tile
                blank.y = j; // Set y coordinate of blank tile
            }
        }
    }

    // Read the goal puzzle state from the user
    printf("Enter the goal puzzle state:\n");
    readPuzzle(goal);

    // Solve the puzzle using the Branch and Bound algorithm
    solvePuzzle(initial, blank, goal);

    return 0;
}
