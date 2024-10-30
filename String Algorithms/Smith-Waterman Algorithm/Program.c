#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MAX3(a, b, c) (MAX(MAX(a, b), c))

// Function to find the maximum of 3 integers (match, insert, delete)

// Function to initialize a 2D array for the scoring matrix
int** createMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to perform the Smith-Waterman algorithm for local sequence alignment
void smithWaterman(char* seq1, char* seq2, int matchScore, int mismatchPenalty, int gapPenalty) {
    int len1 = strlen(seq1);
    int len2 = strlen(seq2);

    // Initialize scoring matrix with extra row and column for initial zeroes
    int** scoreMatrix = createMatrix(len1 + 1, len2 + 1);

    // Initialize maximum score to zero (for local alignment)
    int maxScore = 0;
    int endRow = 0, endCol = 0;

    // Fill in the scoring matrix
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0 || j == 0) {
                // Set first row and first column to 0
                scoreMatrix[i][j] = 0;
            } else {
                // Calculate match, delete, and insert scores
                int match = scoreMatrix[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1] ? matchScore : mismatchPenalty);
                int delete = scoreMatrix[i - 1][j] + gapPenalty;
                int insert = scoreMatrix[i][j - 1] + gapPenalty;

                // Get the maximum score for this cell (including zero for local alignment)
                scoreMatrix[i][j] = MAX3(0, match, MAX(delete, insert));

                // Track the maximum score and the position for traceback
                if (scoreMatrix[i][j] > maxScore) {
                    maxScore = scoreMatrix[i][j];
                    endRow = i;
                    endCol = j;
                }
            }
        }
    }

    // Output the maximum score
    printf("Maximum Alignment Score: %d\n", maxScore);

    // Traceback to find the aligned sequences
    char alignedSeq1[100], alignedSeq2[100];
    int idx1 = 0, idx2 = 0;

    while (endRow > 0 && endCol > 0 && scoreMatrix[endRow][endCol] > 0) {
        if (seq1[endRow - 1] == seq2[endCol - 1]) {
            alignedSeq1[idx1++] = seq1[endRow - 1];
            alignedSeq2[idx2++] = seq2[endCol - 1];
            endRow--;
            endCol--;
        } else if (scoreMatrix[endRow][endCol] == scoreMatrix[endRow - 1][endCol] + gapPenalty) {
            alignedSeq1[idx1++] = seq1[endRow - 1];
            alignedSeq2[idx2++] = '-';
            endRow--;
        } else {
            alignedSeq1[idx1++] = '-';
            alignedSeq2[idx2++] = seq2[endCol - 1];
            endCol--;
        }
    }

    // Reverse the aligned sequences
    alignedSeq1[idx1] = '\0';
    alignedSeq2[idx2] = '\0';
    strrev(alignedSeq1);
    strrev(alignedSeq2);

    // Print the aligned sequences
    printf("Aligned Sequence 1: %s\n", alignedSeq1);
    printf("Aligned Sequence 2: %s\n", alignedSeq2);

    // Free allocated memory for the matrix
    for (int i = 0; i <= len1; i++) {
        free(scoreMatrix[i]);
    }
    free(scoreMatrix);
}

int main() {
    char seq1[] = "ACACACTA";
    char seq2[] = "AGCACACA";
    int matchScore = 2;
    int mismatchPenalty = -1;
    int gapPenalty = -2;

    printf("Sequence 1: %s\n", seq1);
    printf("Sequence 2: %s\n", seq2);

    // Call the Smith-Waterman function
    smithWaterman(seq1, seq2, matchScore, mismatchPenalty, gapPenalty);

    return 0;
}