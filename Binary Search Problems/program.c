#include <stdio.h>
#include <stdlib.h>

// Function to check if it's possible to place 'k' cows with a minimum allowed distance 'minAllowedDist'
int isPossible(int stalls[], int n, int k, int minAllowedDist) {
    int cows = 1, lastStallPos = stalls[0];
    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastStallPos >= minAllowedDist) {
            cows++;
            lastStallPos = stalls[i];
        }
        if (cows == k) {
            return 1;  // true
        }
    }
    return 0;  // false
}

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Function to find the largest minimum distance
int solve(int n, int k, int stalls[]) {
    // Sort the stalls array
    qsort(stalls, n, sizeof(int), compare);
    
    int st = 1, end = stalls[n - 1] - stalls[0], ans = -1;
    
    while (st <= end) {
        int mid = st + (end - st) / 2;
        if (isPossible(stalls, n, k, mid)) {
            ans = mid;
            st = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n = 5, k = 3;
    int stalls[] = {1, 2, 8, 4, 9};

    int result = solve(n, k, stalls);
    printf("The largest minimum distance is: %d\n", result);
    return 0;
}
