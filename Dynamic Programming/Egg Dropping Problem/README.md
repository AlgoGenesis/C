# Egg Dropping Problem - Dynamic Programming

## Problem Statement
The **Egg Dropping Problem** is a classic problem in dynamic programming. It involves determining the minimum number of attempts needed to find the highest floor from which an egg can be dropped without breaking, given a certain number of eggs and floors.

### Example
Given:
- Number of eggs: 2
- Number of floors: 10

The minimum number of attempts required to find the critical floor is `4`.

## Algorithm Overview
1. **Define the Problem State**: Use a 2D dynamic programming array `dp[][]` where `dp[i][j]` represents the minimum number of attempts needed for `i` eggs and `j` floors.
2. **Base Cases**:
   - If there are no floors, `0` attempts are needed.
   - If there is one floor, `1` attempt is needed, regardless of the number of eggs.
3. **Dynamic Programming Approach**:
   - For each combination of eggs and floors, calculate the minimum attempts by simulating dropping an egg from each floor and considering the worst-case scenario.

### Dynamic Programming Formula
The relationship to update `dp[i][j]` is:
dp[i][j] = min(max(dp[i - 1][x - 1], dp[i][j - x]) + 1) for all x in [1, j]
- For each floor `x`, if the egg breaks, you must check the floors below (`dp[i - 1][x - 1]`), and if it doesn’t break, you must check the floors above (`dp[i][j - x]`).

### Pseudocode
```c
function eggDrop(eggs, floors): 
    create a 2D array dp of size (eggs + 1) x (floors + 1)
    for i from 0 to eggs:
    dp[i][0] = 0  // 0 floors require 0 attempts

    for j from 0 to floors:
        dp[1][j] = j  // 1 egg requires j attempts for j floors

    for i from 2 to eggs:
        for j from 1 to floors:
            dp[i][j] = infinity  // Initialize with a large number
            for x from 1 to j:
                res = 1 + max(dp[i - 1][x - 1], dp[i][j - x])
                dp[i][j] = min(dp[i][j], res)

return dp[eggs][floors]

```
## Time Complexity
- **Time Complexity**: `O(eggs * floors^2)`
  - Where `eggs` is the number of eggs and `floors` is the number of floors. This is due to the nested loops over floors.
- **Space Complexity**: `O(eggs * floors)`
  - The `dp[][]` array requires space proportional to the product of the number of eggs and floors.
