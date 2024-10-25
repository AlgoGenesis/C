#include <stdio.h>

void findSubsetSum(int currentSum, int index, int remainingSum);
int n, targetSum;
int weights[25], included[25];

int main() {
    int i, totalSum = 0;

    // Input number of elements in the set
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input the elements (weights)
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
        totalSum += weights[i];
    }

    // Input the required subset sum
    printf("Enter the required sum: ");
    scanf("%d", &targetSum);

    // Check if a solution is possible
    if (totalSum < targetSum) {
        printf("No solution possible since the sum of all elements is less than the required sum.\n");
        return 0;
    }

    // Start the backtracking process
    findSubsetSum(0, 0, totalSum);

    return 0;
}

void findSubsetSum(int currentSum, int index, int remainingSum) {
    if (currentSum == targetSum) {
        // A valid subset has been found
        printf("Subset found: ");
        for (int i = 0; i < n; i++) {
            if (included[i]) {
                printf("%d ", weights[i]);
            }
        }
        printf("\n");
        return;
    }

    if (index >= n || currentSum > targetSum) {
        return;  // Base case: no solution or out of bounds
    }

    // Include the current element and recurse
    included[index] = 1;
    findSubsetSum(currentSum + weights[index], index + 1, remainingSum - weights[index]);

    // Exclude the current element and recurse
    included[index] = 0;
    findSubsetSum(currentSum, index + 1, remainingSum - weights[index]);
}
