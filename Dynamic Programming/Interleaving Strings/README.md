# Interleaving Strings Algorithm

## Overview

The Interleaving Strings problem is a classic dynamic programming problem that determines if a string `C` can be formed by interleaving two other strings `A` and `B` while preserving the order of characters from both strings.

## Problem Statement

Given three strings `A`, `B`, and `C`, determine if `C` can be formed by interleaving `A` and `B`. The interleaving must maintain the relative order of characters from both strings.

### Conditions
1. The length of `C` must equal the sum of the lengths of `A` and `B`:
   \[
   \text{len}(C) = \text{len}(A) + \text{len}(B)
   \]
2. The characters in `C` must be a combination of characters from `A` and `B`, maintaining their original order.

## Approach

We use a dynamic programming approach:

1. **Initialize a DP Table**: Create a 2D boolean array `dp` where `dp[i][j]` indicates whether the first `i` characters of `A` and the first `j` characters of `B` can form the first `i + j` characters of `C`.

2. **Base Case**: Set `dp[0][0]` to `true` since two empty strings can form an empty string.

3. **Fill the DP Table**: Update the DP table based on character matches between `A`, `B`, and `C`.

4. **Result**: The value at `dp[len(A)][len(B)]` indicates whether `C` can be formed by interleaving `A` and `B`.

## Complexity

- **Time Complexity**: O(len(A) * len(B))
- **Space Complexity**: O(len(A) * len(B))

## Example

### Input
- `A = "aab"`
- `B = "xyz"`
- `C = "aaxbyz"`

### Output
- Result: `True`

### Explanation
The string `C` can be formed by interleaving `A` and `B` as follows:
- Take `a` from `A`
- Take `a` from `A`
- Take `x` from `B`
- Take `b` from `A`
- Take `y` from `B`
- Take `z` from `B`

## Code Example

```c
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isInterleave(char *A, char *B, char *C) {
    int lenA = strlen(A);
    int lenB = strlen(B);
    int lenC = strlen(C);

    if (lenA + lenB != lenC) {
        return false;
    }

    bool dp[lenA + 1][lenB + 1];
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;

    for (int j = 1; j <= lenB; j++) {
        dp[0][j] = dp[0][j - 1] && (B[j - 1] == C[j - 1]);
    }

    for (int i = 1; i <= lenA; i++) {
        dp[i][0] = dp[i - 1][0] && (A[i - 1] == C[i - 1]);
    }

    for (int i = 1; i <= lenA; i++) {
        for (int j = 1; j <= lenB; j++) {
            dp[i][j] = (dp[i - 1][j] && (A[i - 1] == C[i + j - 1])) ||
                       (dp[i][j - 1] && (B[j - 1] == C[i + j - 1]));
        }
    }

    return dp[lenA][lenB];
}

int main() {
    char A[] = "aab";
    char B[] = "xyz";
    char C[] = "aaxbyz";

    if (isInterleave(A, B, C)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}