#include <stdio.h>
#include <string.h>

// Function to count the distinct subsequences of S2 in S1
int countDistinctSubsequences(char* S1, char* S2) {
    int n = strlen(S1);
    int m = strlen(S2);

    // Edge case: If S2 is empty, there's exactly 1 subsequence (the empty subsequence)
    if (m == 0) return 1;
    // If S1 is empty but S2 is not, there are no subsequences
    if (n == 0) return 0;

    // Create a dp array of size m+1 (for storing subsequence counts up to S2)
    int dp[m + 1];
    memset(dp, 0, sizeof(dp)); // Initialize all elements to 0

    // Base condition: An empty S2 can be formed in exactly 1 way from any prefix of S1
    dp[0] = 1;

    // Loop over each character in S1
    for (int i = 1; i <= n; i++) {
        // Update dp array from right to left (backwards)
        for (int j = m; j >= 1; j--) {
            // If characters match, add the count of previous subsequences
            if (S1[i - 1] == S2[j - 1]) {
                dp[j] = dp[j - 1] + dp[j];
            }
        }
    }

    // The result will be in dp[m], which gives the count of subsequences matching S2 in S1
    return dp[m];
}

int main() {
    char S1[] = "rabbbit";
    char S2[] = "rabbit";

    int result = countDistinctSubsequences(S1, S2);
    printf("The number of distinct subsequences of '%s' in '%s' is: %d\n", S2, S1, result);

    return 0;
}
