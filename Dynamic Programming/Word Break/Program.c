#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to check if a word can be segmented into valid words
bool wordBreak(char *s, char **wordDict, int dictSize) {
    int n = strlen(s);
    bool dp[n + 1];

    // Initialize the DP array
    memset(dp, 0, sizeof(dp));
    dp[0] = true; // Base case: empty string can be segmented

    // Fill the DP array
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < dictSize; j++) {
            int wordLen = strlen(wordDict[j]);
            if (i >= wordLen && dp[i - wordLen] && strncmp(s + (i - wordLen), wordDict[j], wordLen) == 0) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}

int main() {
    char s[100];
    int dictSize;
    
    printf("Enter the string: ");
    scanf("%s", s);

    printf("Enter the number of words in the dictionary: ");
    scanf("%d", &dictSize);
    
    char **wordDict = (char **)malloc(dictSize * sizeof(char *));
    for (int i = 0; i < dictSize; i++) {
        wordDict[i] = (char *)malloc(100 * sizeof(char));
        printf("Enter word %d: ", i + 1);
        scanf("%s", wordDict[i]);
    }

    if (wordBreak(s, wordDict, dictSize)) {
        printf("The string can be segmented into words from the dictionary.\n");
    } else {
        printf("The string cannot be segmented into words from the dictionary.\n");
    }

    // Free allocated memory
    for (int i = 0; i < dictSize; i++) {
        free(wordDict[i]);
    }
    free(wordDict);

    return 0;
}
