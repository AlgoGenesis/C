# Longest Bitonic Subsequence

## Problem Description

A **bitonic subsequence** of a sequence is a subsequence that first increases and then decreases. The **Longest Bitonic Subsequence (LBS)** problem is to find the length of the longest subsequence in a given sequence that is bitonic.

In this specific implementation, we are working with a string and finding the longest bitonic subsequence by treating each character as an element in the sequence.

### Example

**Input:**  
`str = "character"`

**Output:**  
`Length of Longest Bitonic Subsequence is 5`

**Explanation:**  
The longest bitonic subsequence here is `"charer"`, which first increases (`c -> h -> a -> r`) and then decreases (`r -> e -> r`), resulting in a length of 5.

## Approach

We solve this problem using **Dynamic Programming** by breaking it into two main parts:
1. **Longest Increasing Subsequence (LIS):** For each character in the sequence, calculate the length of the longest subsequence ending at that character.
2. **Longest Decreasing Subsequence (LDS):** For each character in the sequence, calculate the length of the longest subsequence starting from that character.

For each position `i`, the length of the longest bitonic subsequence passing through `i` is `LIS[i] + LDS[i] - 1`.

### Time Complexity
The solution has a time complexity of **O(n²)**, where `n` is the length of the input string.

### Space Complexity
The space complexity is **O(n)** for the `inc` and `dec` arrays.