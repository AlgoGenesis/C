#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int longestBitonicSubsequence(const char* str) {
    int n = strlen(str);
    int inc[n];
    int dec[n];

    // Initialize all values to 1 for the increasing subsequence
    for (int i = 0; i < n; i++) {
        inc[i] = 1;
    }

    // Calculate longest increasing subsequence (LIS) ending at each position
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (str[i] > str[j]) {
                inc[i] = max(inc[i], inc[j] + 1);
            }
        }
    }

    // Initialize all values to 1 for the decreasing subsequence
    for (int i = 0; i < n; i++) {
        dec[i] = 1;
    }

    // Calculate longest decreasing subsequence (LDS) starting at each position
    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (str[i] > str[j]) {
                dec[i] = max(dec[i], dec[j] + 1);
            }
        }
    }

    // Find the maximum value of inc[i] + dec[i] - 1
    int maxLength = 0;
    for (int i = 0; i < n; i++) {
        maxLength = max(maxLength, inc[i] + dec[i] - 1);
    }

    return maxLength;
}

int main() {
    const char* str = "character";
    printf("Length of Longest Bitonic Subsequence is %d\n", longestBitonicSubsequence(str));
    return 0;
}
