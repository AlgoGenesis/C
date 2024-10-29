#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ROW 100
#define MAX_COL 100

bool dfs(char board[MAX_ROW][MAX_COL], int row, int col, char *word, int index, int numRows, int numCols) {
    // If we have matched the whole word
    if (index == strlen(word)) {
        return true;
    }

    // Check for out of bounds and if the current character matches
    if (row < 0 || row >= numRows || col < 0 || col >= numCols || board[row][col] != word[index]) {
        return false;
    }

    // Mark the cell as visited by using a special character
    char temp = board[row][col];
    board[row][col] = '#';

    // Explore all four directions: up, down, left, right
    bool found = dfs(board, row - 1, col, word, index + 1, numRows, numCols) || // up
                 dfs(board, row + 1, col, word, index + 1, numRows, numCols) || // down
                 dfs(board, row, col - 1, word, index + 1, numRows, numCols) || // left
                 dfs(board, row, col + 1, word, index + 1, numRows, numCols);   // right

    // Restore the cell's original value
    board[row][col] = temp;

    return found;
}

bool exist(char board[MAX_ROW][MAX_COL], int numRows, int numCols, char *word) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (board[i][j] == word[0] && dfs(board, i, j, word, 0, numRows, numCols)) {
                return true;
            }
        }
    }
    return false;
}

// Main function to test the exist function
int main() {
    char board[MAX_ROW][MAX_COL] = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    char word[] = "ABCCED";
    int numRows = 3;
    int numCols = 4;

    if (exist(board, numRows, numCols, word)) {
        printf("The word \"%s\" exists in the board.\n", word);
    } else {
        printf("The word \"%s\" does not exist in the board.\n", word);
    }

    return 0;
}