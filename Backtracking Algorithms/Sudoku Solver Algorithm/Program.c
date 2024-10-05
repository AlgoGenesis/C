#include <stdio.h>
#include <stdbool.h>

#define N 9

// Function to print the Sudoku grid
void printGrid(int grid[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if it's safe to place num in the given row, col
bool isSafe(int grid[N][N], int row, int col, int num)
{
    // Check if num is not in the current row
    for (int x = 0; x < N; x++)
    {
        if (grid[row][x] == num)
        {
            return false;
        }
    }

    // Check if num is not in the current column
    for (int x = 0; x < N; x++)
    {
        if (grid[x][col] == num)
        {
            return false;
        }
    }

    // Check if num is not in the current 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i + startRow][j + startCol] == num)
            {
                return false;
            }
        }
    }

    return true;
}

// Function to find an empty location
bool findEmptyLocation(int grid[N][N], int *row, int *col)
{
    for (*row = 0; *row < N; (*row)++)
    {
        for (*col = 0; *col < N; (*col)++)
        {
            if (grid[*row][*col] == 0)
            {
                return true;
            }
        }
    }
    return false;
}

// Function to solve the Sudoku grid using backtracking
bool solveSudoku(int grid[N][N])
{
    int row, col;

    // If no empty cell, then the puzzle is solved
    if (!findEmptyLocation(grid, &row, &col))
    {
        return true;
    }

    // Try digits 1 to 9 in the current empty cell
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;

            // Recursively solve the rest of the grid
            if (solveSudoku(grid))
            {
                return true;
            }

            // Backtrack if the solution is not valid
            grid[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    // Example Sudoku grid (0 represents an empty cell)
    int grid[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    if (solveSudoku(grid))
    {
        printGrid(grid);
    }
    else
    {
        printf("No solution exists\n");
    }

    return 0;
}
