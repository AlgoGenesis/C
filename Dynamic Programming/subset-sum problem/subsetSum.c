#include <stdio.h>
#include <stdbool.h>

bool isSubsetSum(int set[], int n, int sum) {
    // Initialize a 1D DP array of size (sum + 1)
    bool dp[sum + 1];

    // If sum is 0, a subset with sum 0 can always be formed (empty subset)
    dp[0] = true;

    // Initialize all other values as false
    for (int i = 1; i <= sum; i++)
        dp[i] = false;

    // Iterate over each element in the set
    for (int i = 0; i < n; i++) {
        // Update the DP array from right to left
        // This ensures that we don't reuse an element in the same iteration
        for (int j = sum; j >= set[i]; j--) {
            if (dp[j - set[i]]) {
                dp[j] = true;
            }
        }
    }

    // Return whether it's possible to form the given sum
    return dp[sum];
}

int main() {
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);

    if (isSubsetSum(set, n, sum))
        printf("Subset with the given sum exists\n");
    else
        printf("No subset with the given sum exists\n");

    return 0;
}
