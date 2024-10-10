# Rod Cutting Problem - Dynamic Programming

## Problem Statement
The **Rod Cutting Problem** is to maximize the profit obtained by cutting a rod of length `n` into smaller pieces. Each piece of length `i` has a corresponding price `price[i]`. The goal is to determine the maximum profit that can be obtained by cutting the rod into multiple pieces or not cutting it at all.

### Example
- Given the following prices for a rod of length 8:
- Price for length 1: 1 
- Price for length 2: 5
- Price for length 3: 8 
- Price for length 4: 9 
- Price for length 5: 10 
- Price for length 6: 17 
- Price for length 7: 17 
- Price for length 8: 20

- The maximum obtainable profit is `22`, obtained by cutting the rod into two pieces of length `2` and `6`.

## Algorithm Overview
1. **Initialize the `dp[]` Array**: The array `dp[i]` stores the maximum profit obtainable for a rod of length `i`.
2. **Dynamic Programming Approach**:
   - Build the `dp[]` array in a bottom-up manner by considering each possible cut for each length `i`.
   - For each rod length `i`, iterate through all possible cuts and update `dp[i]` with the maximum profit obtainable by making the cut.

### Dynamic Programming Formula
The relationship to update `dp[i]` is:
    dp[i] = max(dp[i], price[j] + dp[i - j - 1]) for j = 0 to i-1
- The `dp[i]` value is calculated by considering every possible cut at `j+1` and adding the profit obtained from the cut `price[j]` to the profit of the remaining rod length `dp[i - j - 1]`.


## Time Complexity
- **Time Complexity**: `O(n^2)`
  - Where `n` is the total length of the rod.
  - The nested loop processes each length and each cut, resulting in a quadratic time complexity.
- **Space Complexity**: `O(n)`
  - The `dp[]` array requires additional space proportional to the length of the rod.

## How to Run
1. Save the `rod_cutting.c` program file.
2. Open a terminal and navigate to the directory where the file is saved.
3. Compile the program using the following command:
   ```bash
   gcc rod_cutting.c -o rod_cutting
   ```
