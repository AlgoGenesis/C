#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
    int y;
} Pair;

// Function to perform BFS traversal
void bfs(char** grid, int r, int c, int startX, int startY) {
    // Directions for moving in 4 possible ways (up, down, left, right)
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    // Create a queue to hold the coordinates
    Pair* queue = (Pair*)malloc(r * c * sizeof(Pair));
    int front = 0, rear = 0;

    // Enqueue the starting cell and mark it as visited
    queue[rear++] = (Pair){startX, startY};
    grid[startX][startY] = '0';  // Mark as visited

    while (front < rear) {
        Pair current = queue[front++];

        // Check all 4 possible directions
        for (int i = 0; i < 4; i++) {
            int newX = current.x + directions[i][0];
            int newY = current.y + directions[i][1];

            // Check if the new position is within bounds and is land
            if (newX >= 0 && newX < r && newY >= 0 && newY < c && grid[newX][newY] == '1') {
                // Mark the cell as visited
                grid[newX][newY] = '0';
                // Enqueue the new position
                queue[rear++] = (Pair){newX, newY};
            }
        }
    }
    free(queue);  // Free allocated memory for queue
}

// Function to count the number of islands using BFS
int numIslands(char** grid, int gridSize, int* gridColSize) {
    int ans = 0;
    int r = gridSize;
    int c = *gridColSize;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == '1') {  // If we find an unvisited land cell
                ans++;  // Increment island count
                bfs(grid, r, c, i, j);  // Perform BFS to mark all connected lands
            }
        }
    }
    return ans;
}

int main() {
    // Sample input grid
    char* grid[5] = {
        "11000",
        "11000",
        "00100",
        "00011",
        "10001"
    };

    // Convert to a 2D character array (2D array of pointers)
    int gridSize = 5;
    int gridColSize = 5;
    char** gridPtr = (char**)malloc(gridSize * sizeof(char*));
    for (int i = 0; i < gridSize; i++) {
        gridPtr[i] = (char*)malloc((gridColSize + 1) * sizeof(char));  // +1 for null terminator
        strcpy(gridPtr[i], grid[i]);
    }

    // Count the number of islands
    int islandsCount = numIslands(gridPtr, gridSize, &gridColSize);
    printf("Number of islands: %d\n", islandsCount);

    // Free allocated memory
    for (int i = 0; i < gridSize; i++) {
        free(gridPtr[i]);
    }
    free(gridPtr);

    return 0;
}
