#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function prototype declarations
bool searchNext(char board[][4], int m, int n, char *word, int row, int col, int index);
bool exist(char board[][4], int m, int n, char *word);

bool searchNext(char board[][4], int m, int n, char *word, int row, int col, int index) {
    // If index reaches the end, it means we have found the word
    if (index == strlen(word))
        return true;

    // Check boundaries and current character
    if (row < 0 || col < 0 || row >= m || col >= n || board[row][col] != word[index] || board[row][col] == '!')
        return false;

    // Mark the cell as visited
    char temp = board[row][col];
    board[row][col] = '!';

    // Search in all four directions
    bool found = searchNext(board, m, n, word, row - 1, col, index + 1) || // Up
                 searchNext(board, m, n, word, row + 1, col, index + 1) || // Down
                 searchNext(board, m, n, word, row, col - 1, index + 1) || // Left
                 searchNext(board, m, n, word, row, col + 1, index + 1);   // Right

    // Undo the visit mark
    board[row][col] = temp;

    return found;
}

bool exist(char board[][4], int m, int n, char *word) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // Check for the first character of the word
            if (board[i][j] == word[0]) {
                if (searchNext(board, m, n, word, i, j, 0))
                    return true;
            }
        }
    }
    return false;
}

int main() {
    char board[3][4] = {{'A','B','C','E'},
                        {'S','F','C','S'},
                        {'A','D','E','E'}};

    char word[] = "ABCCED";
    int m = 3, n = 4;

    if (exist(board, m, n, word))
        printf("True\n");
    else
        printf("False\n");

    return 0;
}

// Output: True