#include <stdio.h>

// Function to calculate the number of ways to paint the fence
int countWays(int n, int k) {
    // If there's only one post, there are 'k' ways to paint it
    if (n == 1)
        return k;

    // If there are two posts:
    // For the first post, we have 'k' options.
    // For the second post, we can either paint it the same as the first or different.
    // There are 'k' ways to paint the first post, and for the second:
    // - If it's the same, there are 'k' options.
    // - If it's different, there are 'k * (k - 1)' options.
    if (n == 2)
        return k * k;

    // For more than two posts, we use dynamic programming
    int same = k;           // Ways to paint the first 2 posts the same
    int diff = k * (k - 1); // Ways to paint the first 2 posts differently
    int total = same + diff;

    // Loop through the remaining posts
    for (int i = 3; i <= n; i++) {
        same = diff; // The current post has to be different from the previous one
        diff = total * (k - 1); // All 'k-1' color options for painting differently
        total = same + diff;    // Total ways to paint up to current post
    }

    return total;
}

// Driver program to test the function
int main() {
    int n = 3; // Number of fence posts
    int k = 2; // Number of colors

    printf("Number of ways to paint the fence: %d\n", countWays(n, k));

    return 0;
}
