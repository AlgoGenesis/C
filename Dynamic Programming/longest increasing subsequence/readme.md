
# Longest Increasing Subsequence (LIS) - Recursive Approach

## Problem Description

The Longest Increasing Subsequence (LIS) problem is about finding the length of the longest subsequence in an array of integers, such that all elements of the subsequence are sorted in increasing order. The subsequence does not need to be contiguous, but it must maintain the relative order of elements from the original array.

### Example

#### Input:
```plaintext
arr = [10, 22, 9, 33, 21, 50, 41, 60]
```

#### Output:
```plaintext
Length of LIS = 5
```

#### Explanation:
The longest increasing subsequence is `[10, 22, 33, 50, 60]`, and its length is 5.

## Solution Approach

This solution is implemented using a recursive approach where the LIS ending at each index `i` is calculated by checking all previous elements `arr[prev]` (where `prev < i`), and finding the maximum LIS that can be formed by including `arr[i]`.

### Key Points:
- **`lisEndAtI(arr, i)`**: A utility function that returns the length of the longest increasing subsequence that ends at index `i`. It recursively computes the LIS for all elements before `i`.
- **`lis(arr, n)`**: The main function that computes the overall LIS for the given array by considering each index as the potential end of the subsequence.

### Time Complexity:
The solution has an exponential time complexity of **O(2^n)** due to the recursive nature of the function.

## Code Explanation

### `max(int a, int b)`
A utility function that returns the maximum of two integers.

### `lisEndAtI(int arr[], int i)`
- This function calculates the LIS ending at index `i` by recursively checking the subsequences ending at all indices `prev < i` and updating the maximum length.
- **Base case**: If `i == 0`, the subsequence contains just the element `arr[0]`, so the LIS is 1.

### `lis(int arr[], int n)`
- This function computes the LIS for the entire array by calling `lisEndAtI()` for each index from `1` to `n-1`.
- It tracks the maximum LIS found across all indices and returns the result.

### Example Run
For the input:
```c
int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
```

- The longest increasing subsequence is `[10, 22, 33, 50, 60]`, which has a length of **5**.
- The program prints: 
```plaintext
Length of lis is 5
```



### Expected Output:
```plaintext
Length of lis is 5
```

## Limitations

- This recursive approach has a high time complexity of **O(2^n)**, which makes it inefficient for larger input arrays.
- An optimized dynamic programming or binary search approach is generally preferred for solving the LIS problem.



This README introduces the problem, explains the recursive approach, and provides usage instructions for running the program.