#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to compute the Longest Proper Prefix which is also Suffix (LPS) array
void computeLPSArray(char* pattern, int M, int* lps) {
    int len = 0;  // length of the previous longest prefix suffix
    lps[0] = 0;   // lps[0] is always 0
    int i = 1;

    // the loop calculates lps[i] for i = 1 to M-1
    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                // This is tricky. Consider the example AAACAAAA and i = 7.
                len = lps[len - 1];
                // Note that we do not increment i here
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// The main KMP algorithm function
void KMPSearch(char* pattern, char* text) {
    int M = strlen(pattern);
    int N = strlen(text);

    // Create lps[] that will hold the longest prefix suffix values for pattern
    int* lps = (int*)malloc(M * sizeof(int));
    
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pattern, M, lps);

    int i = 0;  // index for text[]
    int j = 0;  // index for pattern[]
    while (i < N) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == M) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < N && pattern[j] != text[i]) {
            // mismatch after j matches
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }

    free(lps); // don't forget to free allocated memory
}

int main() {
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";
    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);
    KMPSearch(pattern, text);
    return 0;
}