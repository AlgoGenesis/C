#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to preprocess the pattern and create the LPS array
void buildLPS(char* pattern, int m, int* lps) {
    int length = 0;  // length of the previous longest prefix suffix
    lps[0] = 0;      // lps[0] is always 0

    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP Algorithm to find the first occurrence of the pattern in the text
int KMPSearch(char* text, char* pattern) {
    int n = strlen(text);
    int m = strlen(pattern);

    if (m == 0) {
        return 0;  // If the needle is empty, return 0 as per the problem definition
    }

    // Create LPS array for the pattern
    int* lps = (int*)malloc(m * sizeof(int));
    buildLPS(pattern, m, lps);

    int i = 0;  // index for text
    int j = 0;  // index for pattern

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            free(lps);  // Free memory after use
            return i - j;  // Return the starting index of the match
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    free(lps);  // Free memory after use
    return -1;  // Return -1 if pattern is not found
}

int main() {
    char haystack[] = "hello";
    char needle[] = "ll";

    int result = KMPSearch(haystack, needle);

    if (result != -1) {
        printf("First occurrence of needle found at index: %d\n", result);
    } else {
        printf("Needle not found in haystack.\n");
    }

    return 0;
}
