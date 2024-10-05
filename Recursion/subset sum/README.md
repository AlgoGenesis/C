# Subset Sum: Sum of All Subsets

## Problem Statement

Given an array of integers, the task is to find and print all the possible sums of subsets generated from the array in increasing order.

### Example 1:

**Input:**
N = 3 arr = [5, 2, 1]

**Output:**
0, 1, 2, 3, 5, 6, 7, 8

**Explanation:**
The subsets generated are:  
`[]`, `[1]`, `[2]`, `[2,1]`, `[5]`, `[5,1]`, `[5,2]`, `[5,2,1]`  
The subset sums are:  
`0, 1, 2, 3, 5, 6, 7, 8`

### Example 2:

**Input:**
N = 3 arr = [3, 1, 2]

**Output:**
0, 1, 2, 3, 3, 4, 5, 6

**Explanation:**
The subsets generated are:  
`[]`, `[1]`, `[2]`, `[2,1]`, `[3]`, `[3,1]`, `[3,2]`, `[3,2,1]`  
The subset sums are:  
`0, 1, 2, 3, 3, 4, 5, 6`

## Approach: Recursive Solution

### Intuition

The key idea is that at every index in the array, you have two choices:

1. **Pick the element**: Add the current element to the subset sum.
2. **Don’t pick the element**: Ignore the current element.

By exploring both possibilities at every step, you generate all possible subsets. The process continues until you reach the end of the array, which is the base condition of the recursion.

### Steps:

1. For each element in the array, decide to either:
   - Include the element in the current subset sum.
   - Exclude the element and move to the next one.
2. When you reach the end of the array, add the current subset sum to the result list.

3. Recursively repeat this for all elements to generate all possible sums.

4. Finally, sort the list of sums in increasing order.

### Complexity Analysis

- **Time Complexity:** O(2^N), where N is the size of the array. This is because there are `2^N` possible subsets.
- **Space Complexity:** O(2^N), as we store all subset sums in the result array.
