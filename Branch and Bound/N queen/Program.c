#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 20  // Maximum board size

/* A utility function to print the solution */
void printSolution(int board[MAX_N][MAX_N], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%2d ", board[i][j]);
        printf("\n");
    }
}

/* A function to check if a queen can be placed on board[row][col] */
bool isSafe(int row, int col, int slashCode[MAX_N][MAX_N],
            int backslashCode[MAX_N][MAX_N], bool rowLookup[],
            bool slashCodeLookup[], bool backslashCodeLookup[], int N) {
    // Check if the row or either diagonal is occupied
    if (slashCodeLookup[slashCode[row][col]] ||
        backslashCodeLookup[backslashCode[row][col]] ||
        rowLookup[row])
        return false;

    return true;
}

/* A recursive utility function to solve the N Queen problem */
bool solveNQueensUtil(int board[MAX_N][MAX_N], int col,
                      int slashCode[MAX_N][MAX_N], int backslashCode[MAX_N][MAX_N],
                      bool rowLookup[], bool slashCodeLookup[],
                      bool backslashCodeLookup[], int N) {
    // Base case: If all queens are placed then return true
    if (col >= N)
        return true;

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < N; i++) {
        // Check if queen can be placed on board[i][col]
        if (isSafe(i, col, slashCode, backslashCode, rowLookup,
                   slashCodeLookup, backslashCodeLookup, N)) {
            // Place this queen in board[i][col]
            board[i][col] = 1; // Mark this position
            rowLookup[i] = true;
            slashCodeLookup[slashCode[i][col]] = true;
            backslashCodeLookup[backslashCode[i][col]] = true;

            // Recur to place the rest of the queens
            if (solveNQueensUtil(board, col + 1, slashCode, backslashCode,
                                 rowLookup, slashCodeLookup, backslashCodeLookup, N))
                return true;

            // If placing queen in board[i][col] doesn't lead to a solution, then backtrack
            board[i][col] = 0; // Remove queen from board[i][col]
            rowLookup[i] = false;
            slashCodeLookup[slashCode[i][col]] = false;
            backslashCodeLookup[backslashCode[i][col]] = false;
        }
    }

    // If queen cannot be placed in any row in this column col then return false
    return false;
}

/* This function solves the N Queen problem using Branch and Bound */
bool solveNQueens(int N) {
    int board[MAX_N][MAX_N]; 
    memset(board, 0, sizeof(board)); // Initialize the board to 0

    // Helper matrices for diagonal checks
    int slashCode[MAX_N][MAX_N];
    int backslashCode[MAX_N][MAX_N];

    // Arrays to tell us which rows are occupied
    bool rowLookup[MAX_N] = {false}; 

    // Arrays to track occupied diagonals
    bool slashCodeLookup[2 * MAX_N - 1] = {false}; 
    bool backslashCodeLookup[2 * MAX_N - 1] = {false}; 

    // Initialize helper matrices
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            slashCode[r][c] = r + c;
            backslashCode[r][c] = r - c + (N - 1); // Corrected index
        }
    }

    // Start solving the N Queen problem
    if (solveNQueensUtil(board, 0, slashCode, backslashCode, rowLookup, 
                         slashCodeLookup, backslashCodeLookup, N) == false) {
        printf("Solution does not exist\n");
        return false;
    }

    // Solution found
    printSolution(board, N);
    return true;
}

// Driver program to test above function
int main() {
    int N;

    // User input for the size of the board
    printf("Enter the size of the board (N): ");
    scanf("%d", &N);

    // Validate input
    if (N < 1 || N > MAX_N) {
        printf("Please enter a valid board size between 1 and %d.\n", MAX_N);
        return 1; // Exit with error code
    }

    // Solve the N Queen problem
    solveNQueens(N);

    return 0; 
}
