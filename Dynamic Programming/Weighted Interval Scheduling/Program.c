#include <stdio.h>
#include <stdlib.h>

// Structure to represent an interval
struct Interval {
    int start, finish, weight;
};

// Comparator function to sort intervals based on finish time
int compare(const void *a, const void *b) {
    return ((struct Interval *)a)->finish - ((struct Interval *)b)->finish;
}

// Function to find the last non-conflicting interval
int findLastNonConflicting(struct Interval arr[], int n) {
    for (int j = n - 1; j >= 0; j--) {
        if (arr[j].finish <= arr[n].start) {
            return j;
        }
    }
    return -1;
}

// Function to find the maximum weight of non-overlapping intervals
int weightedIntervalScheduling(struct Interval arr[], int n) {
    // Sort intervals by finish time
    qsort(arr, n, sizeof(arr[0]), compare);

    // Create a DP array to store maximum weights
    int *dp = (int *)malloc(n * sizeof(int));
    dp[0] = arr[0].weight; // Base case

    for (int i = 1; i < n; i++) {
        // Include the current interval
        int incl = arr[i].weight;
        int lastIndex = findLastNonConflicting(arr, i);
        if (lastIndex != -1) {
            incl += dp[lastIndex];
        }

        // Exclude the current interval
        int excl = dp[i - 1];

        // Store the maximum of including and excluding the current interval
        dp[i] = (incl > excl) ? incl : excl;
    }

    int result = dp[n - 1]; // Maximum weight of non-overlapping intervals
    free(dp);
    return result;
}

int main() {
    struct Interval intervals[] = {
        {1, 3, 5},
        {2, 5, 6},
        {4, 6, 5},
        {6, 7, 4},
        {5, 8, 11},
        {7, 9, 2}
    };
    int n = sizeof(intervals) / sizeof(intervals[0]);

    int maxWeight = weightedIntervalScheduling(intervals, n);
    printf("Maximum weight of non-overlapping intervals: %d\n", maxWeight);

    return 0;
}
