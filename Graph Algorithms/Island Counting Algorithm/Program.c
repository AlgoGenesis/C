#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

// Function prototypes
void dfs(int grid[ROWS][COLS], int visited[ROWS][COLS], int row, int col);
void bfs(int grid[ROWS][COLS], int visited[ROWS][COLS], int row, int col);
int countIslandsDFS(int grid[ROWS][COLS]);
int countIslandsBFS(int grid[ROWS][COLS]);

int main() {
    // Example grid
    int grid[ROWS][COLS] = {
        {1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 1, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 1}
    };

    printf("Number of islands using DFS: %d\n", countIslandsDFS(grid));
    printf("Number of islands using BFS: %d\n", countIslandsBFS(grid));

    return 0;
}

// DFS function to traverse and mark connected land (1s)
void dfs(int grid[ROWS][COLS], int visited[ROWS][COLS], int row, int col) {
    // Check bounds and whether the cell is land and not visited
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS || visited[row][col] || grid[row][col] == 0) {
        return;
    }

    // Mark the cell as visited
    visited[row][col] = 1;

    // Visit all adjacent cells (up, down, left, right)
    dfs(grid, visited, row - 1, col); // Up
    dfs(grid, visited, row + 1, col); // Down
    dfs(grid, visited, row, col - 1); // Left
    dfs(grid, visited, row, col + 1); // Right
}

// BFS function to traverse and mark connected land (1s)
void bfs(int grid[ROWS][COLS], int visited[ROWS][COLS], int row, int col) {
    int queue[ROWS * COLS][2]; // Queue for BFS
    int front = 0, rear = 0;
    
    // Start with the initial cell
    queue[rear][0] = row;
    queue[rear][1] = col;
    rear++;

    // Mark the cell as visited
    visited[row][col] = 1;

    // Directions for moving up, down, left, and right
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (front < rear) {
        int currentRow = queue[front][0];
        int currentCol = queue[front][1];
        front++;

        // Explore all adjacent cells
        for (int i = 0; i < 4; i++) {
            int newRow = currentRow + directions[i][0];
            int newCol = currentCol + directions[i][1];

            // Check bounds and whether the cell is land and not visited
            if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS && !visited[newRow][newCol] && grid[newRow][newCol] == 1) {
                // Mark the cell as visited and add it to the queue
                visited[newRow][newCol] = 1;
                queue[rear][0] = newRow;
                queue[rear][1] = newCol;
                rear++;
            }
        }
    }
}

// Function to count the number of islands using DFS
int countIslandsDFS(int grid[ROWS][COLS]) {
    int visited[ROWS][COLS] = {0}; // Array to keep track of visited cells
    int islandCount = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // If we find land (1) that hasn't been visited, it's a new island
            if (grid[i][j] == 1 && !visited[i][j]) {
                dfs(grid, visited, i, j); // Use DFS to mark all parts of the island
                islandCount++; // Increment island count
            }
        }
    }
    return islandCount; // Return total number of islands
}

// Function to count the number of islands using BFS
int countIslandsBFS(int grid[ROWS][COLS]) {
    int visited[ROWS][COLS] = {0}; // Array to keep track of visited cells
    int islandCount = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // If we find land (1) that hasn't been visited, it's a new island
            if (grid[i][j] == 1 && !visited[i][j]) {
                bfs(grid, visited, i, j); // Use BFS to mark all parts of the island
                islandCount++; // Increment island count
            }
        }
    }
    return islandCount; // Return total number of islands
}
