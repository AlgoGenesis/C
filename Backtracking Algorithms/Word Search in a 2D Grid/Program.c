#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define ROWS 3
#define COLS 4

// Struct to store board and word details
typedef struct {
    char board[ROWS][COLS];
    int rows;
    int cols;
} Board;

// Helper function for backtracking
bool backtrack(Board *b, const char *word, int index, int i, int j) {
    if (index == strlen(word)) {
        return true; // All characters in the word have been found
    }
    // Check if the current position is within the board boundaries and if the character matches
    if (i < 0 || j < 0 || i >= b->rows || j >= b->cols || b->board[i][j] != word[index]) {
        return false; // Out of bounds or mismatch
    }

    char temp = b->board[i][j];
    b->board[i][j] = '*'; // Mark the current cell as visited

    // Explore neighboring cells
    bool exist = backtrack(b, word, index + 1, i - 1, j) ||
                 backtrack(b, word, index + 1, i, j - 1) ||
                 backtrack(b, word, index + 1, i + 1, j) ||
                 backtrack(b, word, index + 1, i, j + 1);

    b->board[i][j] = temp; // Restore the cell

    return exist;
}

// Function to check if a word exists in the board
bool exist(Board *b, const char *word) {
    for (int i = 0; i < b->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            if (backtrack(b, word, 0, i, j)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    Board b = {
        {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}
        },
        ROWS, COLS
    };
    const char *word1 = "ABCCED";
    const char *word2 = "SEE";
    const char *word3 = "ABCB";

    printf("Word \"%s\" exists: %s\n", word1, exist(&b, word1) ? "true" : "false");
    printf("Word \"%s\" exists: %s\n", word2, exist(&b, word2) ? "true" : "false");
    printf("Word \"%s\" exists: %s\n", word3, exist(&b, word3) ? "true" : "false");

    return 0;
}
