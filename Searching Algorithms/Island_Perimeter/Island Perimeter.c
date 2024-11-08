#include <stdio.h>

#define ROWS 5
#define COLS 5

int islandPerimeter(int grid[ROWS][COLS]) {
    int perimeter = 0;

    // Directions for the four possible adjacent cells (up, down, left, right)
    int directions[4][2] = {
        {-1, 0}, // Up
        {1, 0},  // Down
        {0, -1}, // Left
        {0, 1}   // Right
    };

    // Iterate through each cell in the grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) { // If it's land
                // For each land cell, check all four directions
                for (int d = 0; d < 4; d++) {
                    int newRow = i + directions[d][0];
                    int newCol = j + directions[d][1];

                    // Check if the adjacent cell is out of bounds or water
                    if (newRow < 0 || newRow >= ROWS || newCol < 0 || newCol >= COLS || grid[newRow][newCol] == 0) {
                        perimeter++; // Increase perimeter for water or out of bounds
                    }
                }
            }
        }
    }

    return perimeter;
}

int main() {
    // Example grid with islands (1 = land, 0 = water)
    int grid[ROWS][COLS] = {
        {0, 1, 0, 0, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0}
    };

    int perimeter = islandPerimeter(grid);
    printf("The perimeter of the island is: %d\n", perimeter);

    return 0;
}