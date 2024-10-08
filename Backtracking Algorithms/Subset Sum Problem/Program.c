#include <stdio.h>
#include <stdbool.h>

// Recursive function to check if subset sum is possible
bool isSubsetSum(int set[], int n, int sum) {
    // Base Cases
    if (sum == 0) return true;
    if (n == 0 && sum != 0) return false;

    // Ignore the last element if it's greater than sum
    if (set[n-1] > sum) {
        return isSubsetSum(set, n-1, sum);
    }

    // Check if sum can be obtained by including or excluding the last element
    return isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum - set[n-1]);
}

int main() {
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);

    if (isSubsetSum(set, n, sum) == true) {
        printf("Found a subset with given sum\n");
    } else {
        printf("No subset with given sum\n");
    }

    return 0;
}
