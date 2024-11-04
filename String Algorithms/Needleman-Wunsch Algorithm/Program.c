#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MATCH 1   // Score for a match
#define MISMATCH -1 // Score for a mismatch
#define GAP -2     // Penalty for a gap

// Function to calculate the maximum of three values
int max(int a, int b, int c) {
    if (a >= b && a >= c) return a;
    else if (b >= a && b >= c) return b;
    else return c;
}

// Function to implement the Needleman-Wunsch algorithm
void needlemanWunsch(char* seq1, char* seq2) {
    int len1 = strlen(seq1);
    int len2 = strlen(seq2);

    // Initialize score matrix
    int scoreMatrix[len1 + 1][len2 + 1];
    
    // Initialize first row and first column with gap penalties
    for (int i = 0; i <= len1; i++) {
        scoreMatrix[i][0] = i * GAP;
    }
    for (int j = 0; j <= len2; j++) {
        scoreMatrix[0][j] = j * GAP;
    }

    // Fill the score matrix
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int matchMismatchScore = (seq1[i - 1] == seq2[j - 1]) ? MATCH : MISMATCH;
            scoreMatrix[i][j] = max(
                scoreMatrix[i - 1][j - 1] + matchMismatchScore, // Match/Mismatch
                scoreMatrix[i - 1][j] + GAP,                    // Deletion (gap in seq2)
                scoreMatrix[i][j - 1] + GAP                     // Insertion (gap in seq1)
            );
        }
    }

    // Print the final score matrix
    printf("Score Matrix:\n");
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            printf("%3d ", scoreMatrix[i][j]);
        }
        printf("\n");
    }

    // Traceback to get the optimal alignment
    printf("\nOptimal Alignment:\n");
    int i = len1, j = len2;
    char alignedSeq1[len1 + len2 + 1], alignedSeq2[len1 + len2 + 1];
    int idx = 0;

    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && scoreMatrix[i][j] == scoreMatrix[i - 1][j - 1] + ((seq1[i - 1] == seq2[j - 1]) ? MATCH : MISMATCH)) {
            alignedSeq1[idx] = seq1[i - 1];
            alignedSeq2[idx] = seq2[j - 1];
            i--; j--;
        }
        else if (i > 0 && scoreMatrix[i][j] == scoreMatrix[i - 1][j] + GAP) {
            alignedSeq1[idx] = seq1[i - 1];
            alignedSeq2[idx] = '-';
            i--;
        }
        else {
            alignedSeq1[idx] = '-';
            alignedSeq2[idx] = seq2[j - 1];
            j--;
        }
        idx++;
    }

    // Print aligned sequences
    alignedSeq1[idx] = '\0';
    alignedSeq2[idx] = '\0';
    
    // Reverse the sequences
    for (int k = 0; k < idx / 2; k++) {
        char temp = alignedSeq1[k];
        alignedSeq1[k] = alignedSeq1[idx - k - 1];
        alignedSeq1[idx - k - 1] = temp;

        temp = alignedSeq2[k];
        alignedSeq2[k] = alignedSeq2[idx - k - 1];
        alignedSeq2[idx - k - 1] = temp;
    }

    printf("Seq1: %s\n", alignedSeq1);
    printf("Seq2: %s\n", alignedSeq2);
}

int main() {
    char seq1[] = "GATTACA";
    char seq2[] = "GCATGCU";
    
    printf("Sequence 1: %s\n", seq1);
    printf("Sequence 2: %s\n", seq2);
    
    needlemanWunsch(seq1, seq2);
    
    return 0;
}