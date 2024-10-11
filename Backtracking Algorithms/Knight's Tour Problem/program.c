#include <stdio.h>

#define N 8

// Possible moves for the knight
int xMoves[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int yMoves[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

// Function to print the chessboard
void printSolution(int board[N][N]) {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            printf(" %2d ", board[x][y]);
        }
        printf("\n");
    }
}

// Check if the move is valid (within bounds and not yet visited)
int isValidMove(int x, int y, int board[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

// Solve the Knight's Tour problem using backtracking
int solveKnightTour(int x, int y, int moveCount, int board[N][N], int xMoves[N], int yMoves[N]) {
    if (moveCount == N * N)
        return 1;

    // Try all possible moves for the knight
    for (int i = 0; i < 8; i++) {
        int nextX = x + xMoves[i];
        int nextY = y + yMoves[i];
        if (isValidMove(nextX, nextY, board)) {
            board[nextX][nextY] = moveCount;
            if (solveKnightTour(nextX, nextY, moveCount + 1, board, xMoves, yMoves))
                return 1;
            else
                board[nextX][nextY] = -1; // Backtrack
        }
    }

    return 0;
}

// Main function to initialize the chessboard and start the tour
int main() {
    int board[N][N];

    // Initialize the chessboard with -1 (unvisited)
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            board[x][y] = -1;

    // Starting position of the knight
    int startX = 0;
    int startY = 0;
    board[startX][startY] = 0;

    // Solve the Knight's Tour
    if (solveKnightTour(startX, startY, 1, board, xMoves, yMoves))
        printSolution(board);
    else
        printf("No solution exists.\n");

    return 0;
}
