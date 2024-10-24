
#include <stdio.h>
#include <stdbool.h>

#define GRID_SIZE 5  // Define the grid size

// Function to check if placing a magnet violates any rules
bool is_valid(int grid[GRID_SIZE][GRID_SIZE], int row, int col, int magnet) {
    // Check adjacent cells for the same type of magnet
    // Example: Check the cell above, below, left, and right
    if (row > 0 && grid[row - 1][col] == magnet) return false; // Check above
    if (row < GRID_SIZE - 1 && grid[row + 1][col] == magnet) return false; // Check below
    if (col > 0 && grid[row][col - 1] == magnet) return false; // Check left
    if (col < GRID_SIZE - 1 && grid[row][col + 1] == magnet) return false; // Check right
    return true;  // Valid placement
}

// Backtracking function to place magnets
bool place_magnets(int grid[GRID_SIZE][GRID_SIZE], int magnets[], int index, int num_magnets) {
    if (index == num_magnets) {
        return true;  // All magnets placed successfully
    }

    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            if (grid[row][col] == 0) {  // Check if the cell is empty
                // Try placing the magnet
                grid[row][col] = magnets[index];
                if (is_valid(grid, row, col, magnets[index])) {
                    if (place_magnets(grid, magnets, index + 1, num_magnets)) {
                        return true;  // Successful placement
                    }
                }
                // Backtrack
                grid[row][col] = 0;
            }
        }
    }
    return false;  // No valid placement found
}

// Function to print the grid
void print_grid(int grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 0) {
                printf(". ");  // Empty cell
            } else if (grid[i][j] == 1) {
                printf("N ");  // North magnet
            } else {
                printf("S ");  // South magnet
            }
        }
        printf("\n");
    }
}

int main() {
    int grid[GRID_SIZE][GRID_SIZE] = {0};  // Initialize grid to 0 (empty)
    int magnets[] = {1, 2};  // Example magnets: 1 for North, 2 for South
    int num_magnets = sizeof(magnets) / sizeof(magnets[0]);

    if (place_magnets(grid, magnets, 0, num_magnets)) {
        printf("Solution found:\n");
        print_grid(grid);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}