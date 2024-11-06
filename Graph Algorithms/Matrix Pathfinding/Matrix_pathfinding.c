#include <stdio.h>
#include <stdbool.h>

// Matrix size
#define N 5

// Directions for moving: down, right, up, left
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

// Function to check if a cell (x, y) is within bounds, walkable, and unvisited
bool isValid(int x, int y, int matrix[N][N], bool visited[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && matrix[x][y] == 1 && !visited[x][y]);
}

// Recursive DFS function to find the path from (x, y) to (4, 4)
bool findPath(int matrix[N][N], int x, int y, bool visited[N][N]) {
    // Base case: if destination is reached, print path and stop
    if (x == N - 1 && y == N - 1) {
        printf("(%d, %d)\n", x, y);
        return true;
    }

    // Mark the current cell as visited
    visited[x][y] = true;
    printf("(%d, %d) -> ", x, y);

    // Explore all four possible directions
    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        // Move to the next cell if it is valid
        if (isValid(newX, newY, matrix, visited)) {
            if (findPath(matrix, newX, newY, visited)) {
                return true;  // Stop if path to destination is found
            }
        }
    }

    // Backtrack: unmark the cell as visited
    visited[x][y] = false;
    printf("Backtracking from (%d, %d)\n", x, y);

    return false;
}

int main() {
    // Define a 5x5 matrix with walkable (1) and blocked (0) cells
    int matrix[N][N] = {
        {1, 0, 1, 1, 0},
        {1, 1, 1, 0, 1},
        {0, 0, 1, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 1, 1}
    };

    // Initialize a visited array to keep track of visited cells
    bool visited[N][N] = {false};

    printf("Finding path from (0, 0) to (4, 4):\n");

    // Start DFS from the top-left corner (0, 0)
    if (!findPath(matrix, 0, 0, visited)) {
        printf("No path exists\n");
    }

    return 0;
}
