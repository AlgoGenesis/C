#include <stdio.h>
#include <stdbool.h>

#define M 5  // Number of rows
#define N 6  // Number of columns

// Check - horizontal pattern can be placed at position (i, j)
bool canPutPatternHorizontally(char rules[M][N], int i, int j, char pat[2]) {
    if (j - 1 >= 0 && rules[i][j - 1] == pat[0]) {
        return false;
    } else if (i - 1 >= 0 && rules[i - 1][j] == pat[0]) {
        return false;
    } else if (i - 1 >= 0 && rules[i - 1][j + 1] == pat[1]) {
        return false;
    } else if (j + 2 < N && rules[i][j + 2] == pat[1]) {
        return false;
    }
    return true;
}

// Check - vertical pattern can be placed at position (i, j)
bool canPutPatternVertically(char rules[M][N], int i, int j, char pat[2]) {
    if (j - 1 >= 0 && rules[i][j - 1] == pat[0]) {
        return false;
    } else if (i - 1 >= 0 && rules[i - 1][j] == pat[0]) {
        return false;
    } else if (j + 1 < N && rules[i][j + 1] == pat[0]) {
        return false;
    }
    return true;
}

// Check if the constraints are satisfied
bool checkConstraints(char rules[M][N]) {
    int top[N] = {1, -1, -1, 2, 1, -1};
    int bottom[N] = {2, -1, -1, 2, -1, 3};
    int left[M] = {2, 3, -1, -1, -1};
    int right[M] = {-1, -1, -1, 1, -1};

    int pCountH[M] = {0}, nCountH[M] = {0};
    int pCountV[N] = {0}, nCountV[N] = {0};

    // Count poles horizontally
    for (int row = 0; row < M; row++) {
        for (int col = 0; col < N; col++) {
            char ch = rules[row][col];
            if (ch == '+') {
                pCountH[row]++;
            } else if (ch == '-') {
                nCountH[row]++;
            }
        }
    }

    // Count poles vertically
    for (int col = 0; col < N; col++) {
        for (int row = 0; row < M; row++) {
            char ch = rules[row][col];
            if (ch == '+') {
                pCountV[col]++;
            } else if (ch == '-') {
                nCountV[col]++;
            }
        }
    }

    // Check row constraints
    for (int row = 0; row < M; row++) {
        if (left[row] != -1 && pCountH[row] != left[row]) {
            return false;
        }
        if (right[row] != -1 && nCountH[row] != right[row]) {
            return false;
        }
    }

    // Check column constraints
    for (int col = 0; col < N; col++) {
        if (top[col] != -1 && pCountV[col] != top[col]) {
            return false;
        }
        if (bottom[col] != -1 && nCountV[col] != bottom[col]) {
            return false;
        }
    }

    return true;
}

// Backtracking function to solve the magnet puzzle
void solveMagnets(char rules[M][N], int i, int j) {
    // Base case: all rows filled
    if (i == M && j == 0) {
        if (checkConstraints(rules)) {
            // Print the grid
            printf("[");
            for (int row = 0; row < M; row++) {
                printf("[");
                for (int col = 0; col < N; col++) {
                    printf("'%c', ", rules[row][col]);
                }
                printf("]");
            }
            printf("]\n");
        }
        return;
    }

    // Move to next row if column limit is reached
    if (j >= N) {
        solveMagnets(rules, i + 1, 0);
        return;
    }

    // Skip over if already filled
    if (rules[i][j] == 'L') {
        // Option 1: +-
        if (canPutPatternHorizontally(rules, i, j, "+-")) {
            rules[i][j] = '+';
            rules[i][j + 1] = '-';
            solveMagnets(rules, i, j + 2);
            rules[i][j] = 'L';
            rules[i][j + 1] = 'R';
        }

        // Option 2: -+
        if (canPutPatternHorizontally(rules, i, j, "-+")) {
            rules[i][j] = '-';
            rules[i][j + 1] = '+';
            solveMagnets(rules, i, j + 2);
            rules[i][j] = 'L';
            rules[i][j + 1] = 'R';
        }

        // Option 3: xx
        rules[i][j] = 'x';
        rules[i][j + 1] = 'x';
        solveMagnets(rules, i, j + 2);
        rules[i][j] = 'L';
        rules[i][j + 1] = 'R';
    } else if (rules[i][j] == 'T') {
        // Option 1: +-
        if (canPutPatternVertically(rules, i, j, "+-")) {
            rules[i][j] = '+';
            rules[i + 1][j] = '-';
            solveMagnets(rules, i, j + 1);
            rules[i][j] = 'T';
            rules[i + 1][j] = 'B';
        }

        // Option 2: -+
        if (canPutPatternVertically(rules, i, j, "-+")) {
            rules[i][j] = '-';
            rules[i + 1][j] = '+';
            solveMagnets(rules, i, j + 1);
            rules[i][j] = 'T';
            rules[i + 1][j] = 'B';
        }

        // Option 3: xx
        rules[i][j] = 'x';
        rules[i + 1][j] = 'x';
        solveMagnets(rules, i, j + 1);
        rules[i][j] = 'T';
        rules[i + 1][j] = 'B';
    } else {
        solveMagnets(rules, i, j + 1);
    }
}

// Main function
int main() {
    char rules[M][N] = {
        {'L', 'R', 'L', 'R', 'T', 'T'},
        {'L', 'R', 'L', 'R', 'B', 'B'},
        {'T', 'T', 'T', 'T', 'L', 'R'},
        {'B', 'B', 'B', 'B', 'T', 'T'},
        {'L', 'R', 'L', 'R', 'B', 'B'}
    };

    solveMagnets(rules, 0, 0);
    return 0;
}
