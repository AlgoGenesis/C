#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// Comparator function to sort strings based on their length
int compareStrings(const void *a, const void *b) {
    return strlen(*(const char **)a) - strlen(*(const char **)b);
}

// Function to check if s1 can be formed by adding one character to s2
bool canForm(char *s1, char *s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    
    if (len1 != len2 + 1) return false;
    
    int i = 0, j = 0;
    
    while (i < len1) {
        if (j < len2 && s1[i] == s2[j]) {
            i++;
            j++;
        } else {
            i++;
        }
    }
    
    return (i == len1 && j == len2);
}

// Function to find the longest string chain length
int longestStrChain(char *words[], int n) {
    // Sort the words based on their lengths
    qsort(words, n, sizeof(char *), compareStrings);
    
    // Dynamic programming array to store the maximum chain length for each word
    int dp[n];
    for (int i = 0; i < n; i++) dp[i] = 1;
    
    int maxLength = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (canForm(words[i], words[j]) && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > maxLength) {
            maxLength = dp[i];
        }
    }
    
    return maxLength;
}

int main() {
    char *words[] = {"a", "b", "ba", "bca", "bda", "bdca"};
    int n = sizeof(words) / sizeof(words[0]);

    int result = longestStrChain(words, n);
    printf("The length of the longest string chain is: %d\n", result);

    return 0;
}
