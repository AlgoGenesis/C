#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    // Array of currency notes
    int arr[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int n = sizeof(arr) / sizeof(arr[0]); // Number of currency notes

    // Amount to be made
    int amt;
    printf("Enter amount: ");
    scanf("%d", &amt);

    // dp[i] will store the minimum number of notes required to make amount i
    int dp[amt + 1];
    int note[amt + 1]; // To store the last note used for each amount

    // Initialize dp array with a large value (INT_MAX)
    for (int i = 0; i <= amt; i++) {
        dp[i] = INT_MAX;
    }
    dp[0] = 0; // Base case: 0 amount requires 0 notes

    // Dynamic Programming to find minimum number of notes for each amount
    for (int i = 1; i <= amt; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j] <= i && dp[i - arr[j]] != INT_MAX) {
                if (dp[i] > dp[i - arr[j]] + 1) {
                    dp[i] = dp[i - arr[j]] + 1;
                    note[i] = arr[j]; // Store the note used
                }
            }
        }
    }

    if (dp[amt] == INT_MAX) {
        printf("No solution\n");
    } else {
        printf("Minimum number of notes: %d\n", dp[amt]);

        // To print the notes used
        printf("Notes used: ");
        while (amt > 0) {
            printf("%d ", note[amt]);
            amt -= note[amt]; // Reduce the amount by the note used
        }
        printf("\n");
    }

    return 0;
}
