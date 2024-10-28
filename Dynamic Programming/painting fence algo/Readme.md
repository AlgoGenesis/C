


# Painting Fence Algorithm

## Problem Description

The **Painting Fence Algorithm** addresses the problem of determining how many ways there are to paint a fence with `n` posts using `k` colors such that no more than two adjacent posts have the same color. This problem is commonly solved using dynamic programming.

### Example

#### Input:
```plaintext
n = 3, k = 2
```

#### Output:
```plaintext
Number of ways to paint the fence: 6
```

### Explanation:
With 3 posts and 2 colors, there are 6 possible ways to paint the fence while ensuring no more than two adjacent posts have the same color.

## Solution Approach

This solution uses dynamic programming to count the number of valid ways to paint the fence. The key idea is to keep track of two cases:
- same: The number of ways to paint the posts where the last two posts have the same color.
- diff: The number of ways to paint the posts where the last two posts have different colors.

For each post, we update the number of ways based on whether the current post is painted the same as or different from the previous post.

### Key Points:
- If there's only one post (`n == 1`), it can be painted in `k` ways.
- If there are two posts (`n == 2`), both posts can be painted in `k * k` ways.
- For more than two posts, we recursively compute the total number of ways to paint by updating the `same` and `diff` values at each step.

### Dynamic Programming Formula:
- `same = diff`
- `diff = total * (k - 1)`
- `total = same + diff`

### Time Complexity:
The solution runs in O(n) time, where `n` is the number of posts, as it iterates over the posts once.

## Code Implementation

```c
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
```



### Expected Output:
```plaintext
Number of ways to paint the fence: 6
```

## Input Description

- `n`: The number of fence posts.
- `k`: The number of available colors.

### Example Input:
```c
int n = 3; // Number of fence posts
int k = 2; // Number of colors
```

### Example Output:
```plaintext
Number of ways to paint the fence: 6
```

## Limitations

- The current algorithm solves the problem with a time complexity of O(n), which is efficient for moderate values of `n`. 
- For very large `n`, further optimizations or alternate approaches may be needed.




This README provides an overview of the problem, the solution approach, code implementation, and instructions for running the program.