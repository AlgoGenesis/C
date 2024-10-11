#include <stdio.h>

#define N 5 // Define the size of the maze

// Function to print the solved maze
void printSolution(int maze[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf(" %d ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to check if (x, y) is valid
int isSafe(int maze[N][N], int x, int y) {
    // Check if x and y are within the bounds of the maze and the cell is not blocked
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

// Recursive function to solve the maze
int solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]) {
    // If (x, y) is the goal, mark it in the solution and return true
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return 1;
    }

    // Check if the current position is valid
    if (isSafe(maze, x, y)) {
        // Mark x, y as part of the solution path
        sol[x][y] = 1;

        // Move forward in the x direction
        if (solveMazeUtil(maze, x + 1, y, sol))
            return 1;

        // If moving in x direction doesn't lead to a solution then
        // Move down in the y direction
        if (solveMazeUtil(maze, x, y + 1, sol))
            return 1;

        // If none of the above movements work, unmark x, y as part of solution path
        sol[x][y] = 0;
        return 0;
    }

    return 0;
}

// Function to solve the maze
void solveMaze(int maze[N][N]) {
    int sol[N][N] = { { 0, 0, 0, 0, 0 },
                      { 0, 0, 0, 0, 0 },
                      { 0, 0, 0, 0, 0 },
                      { 0, 0, 0, 0, 0 },
                      { 0, 0, 0, 0, 0 } };

    if (solveMazeUtil(maze, 0, 0, sol) == 0) {
        printf("No solution exists\n");
        return;
    }

    printSolution(sol);
}

// Driver code
int main() {
    // 1s represent open cells and 0s represent blocked cells
    int maze[N][N] = { { 1, 0, 0, 0, 1 },
                       { 1, 1, 0, 1, 1 },
                       { 0, 1, 0, 0, 0 },
                       { 0, 1, 1, 1, 0 },
                       { 0, 0, 0, 1, 1 } };

    solveMaze(maze);
    return 0;
}
