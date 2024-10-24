#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if all characters in S1 are '*'
bool isAllStars(char *S1, int i) {
    for (int j = 0; j < i; j++) {
        if (S1[j] != '*')
            return false;
    }
    return true;
}

// Function to check wildcard matching
bool wildcardMatching(char *S1, char *S2) {
    int n = strlen(S1);
    int m = strlen(S2);

    // Previous and current row arrays for DP
    bool prev[m + 1], cur[m + 1];

    // Initialize the prev array (for i = 0)
    prev[0] = true;  // Empty pattern matches empty string
    for (int j = 1; j <= m; j++) {
        prev[j] = false;  // Empty pattern doesn't match any non-empty string
    }

    // Loop over each character in S1
    for (int i = 1; i <= n; i++) {
        // Initialize cur[0] (matching an empty S2 with S1[0..i-1])
        cur[0] = isAllStars(S1, i);

        // Loop over each character in S2
        for (int j = 1; j <= m; j++) {
            if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?') {
                cur[j] = prev[j - 1];
            } else if (S1[i - 1] == '*') {
                cur[j] = prev[j] || cur[j - 1];
            } else {
                cur[j] = false;
            }
        }

        // Copy cur to prev for the next iteration
        for (int j = 0; j <= m; j++) {
            prev[j] = cur[j];
        }
    }

    // Final result is in prev[m]
    return prev[m];
}

int main() {
    char S1[] = "a*?b";
    char S2[] = "axxb";

    if (wildcardMatching(S1, S2)) {
        printf("The strings match!\n");
    } else {
        printf("The strings do not match.\n");
    }

    return 0;
}
