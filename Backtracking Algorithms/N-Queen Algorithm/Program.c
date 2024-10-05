#include <stdio.h>
#include <stdbool.h>

#define N 8 // Change this value for different N

// Function to print the solution
void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if placing a queen is safe
bool isSafe(int board[N][N], int row, int col)
{
    int i, j;

    // Check this row on the left side
    for (i = 0; i < col; i++)
    {
        if (board[row][i] == 1)
        {
            return false;
        }
    }

    // Check the upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    // Check the lower diagonal on the left side
    for (i = row, j = col; i < N && j >= 0; i++, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    return true;
}

// Function to solve the N-Queens problem using backtracking
bool solveNQueensUtil(int board[N][N], int col)
{
    // Base case: If all queens are placed, return true
    if (col >= N)
    {
        return true;
    }

    // Try placing this queen in all rows of the current column
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            // Place the queen
            board[i][col] = 1;

            // Recur to place the rest of the queens
            if (solveNQueensUtil(board, col + 1))
            {
                return true;
            }

            // If placing queen doesn't lead to a solution, backtrack
            board[i][col] = 0;
        }
    }

    return false; // If no placement is possible, return false
}

// Function to solve the N-Queens problem
bool solveNQueens()
{
    int board[N][N] = {0};

    if (!solveNQueensUtil(board, 0))
    {
        printf("Solution does not exist\n");
        return false;
    }

    printSolution(board);
    return true;
}

int main()
{
    solveNQueens();
    return 0;
}
