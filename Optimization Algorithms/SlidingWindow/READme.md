# Sliding Window Algorithm

## Description
The Sliding Window technique is an *optimization approach* used for solving problems that involve a subset (or window) of consecutive elements in linear data structures like arrays or strings. It enables efficient traversal of a subset by "sliding" the window across the data structure instead of recalculating the subset from scratch at each position.

## Problem Definition
Given: an array (or string) and a specific window size

Objective: find a result based on the elements within the sliding window (e.g., maximum sum of elements within a specific window size, longest substring without repeating characters, etc.)

## Example Problem: Maximum Sum Subarray of Fixed Length

In this example, we solve the problem of finding the maximum sum of a subarray with a fixed length in a given array.

### Solution Overview
1. Initialize the sum of the first window.
2. Slide the window across the array by adding the element entering the window and subtracting the one leaving it.
3. Track and update the maximum sum encountered as the window slides.
4. Return the maximum sum found.

### Code
```python
def max_sum_subarray(arr, k):
    # Step 1: Initialize sum of the first window
    window_sum = sum(arr[:k])
    max_sum = window_sum
    
    # Step 2: Slide the window across the array
    for i in range(k, len(arr)):
        window_sum += arr[i] - arr[i - k]  # add the next element and remove the first element of the previous window
        max_sum = max(max_sum, window_sum)  # update max sum if the current window sum is greater
    
    # Step 4: Return the maximum sum found
    return max_sum
