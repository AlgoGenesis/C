# Sliding window Technique

## Description

Sliding Window Technique is a method used to efficiently solve problems that involve defining a window or range in the input data (arrays or strings) and then moving that window across the data to perform some operation within the window. This technique is commonly used in algorithms like finding subarrays with a specific sum, finding the longest substring with unique characters, or solving problems that require a fixed-size window to process elements efficiently.

### Problem defination 

Problem: Find the sum of all contiguous subarrays of size k in a given array arr.

Solution:

Initialize the window:
-Calculate the sum of the first k elements to initialize the window.

Slide the window:
-For each subsequent element:
Add the new element to the window's sum.
Subtract the element that is going out of the window.
Print the current window's sum.

### Algorithm overview

Initialization:
-Set a variable sum to 0.
-Calculate the sum of the first k elements of the array and store it in sum. 
-This represents the sum of the initial window.

Sliding the Window:
-Iterate over the remaining elements of the array, starting from the k-th index.

For each element at index i:
-Add the current element arr[i] to the sum.
-Subtract the element that is going out of the window, which is arr[i-k].
-Print the current sum as the sum of the window ending at index i.

### Time complexity

Time Complexity: O(N)
Space Complexity: O(1)

### Advantages

Advantages of Sliding Window Algorithm:

-Efficiency: It significantly reduces time complexity, often from quadratic to linear, by avoiding redundant calculations.
-Simplicity: The concept is relatively straightforward to understand and implement.
-Versatility: It can be applied to a wide range of problems, including array, string, and data stream processing.

### Disadvantages

-Problem-specific: The optimal window size and the specific operations within the window can vary depending on the problem.
-Implementation Complexity: While the core concept is simple, the implementation details can become more complex for intricate problems.
-Limited Applicability: It's primarily suited for problems involving contiguous subarrays or substrings. It may not be directly applicable to problems that require non-contiguous or arbitrary subsets.

### Conclusion

The sliding window technique allows us to efficiently calculate the sum of a subarray of size k by adding the new element and removing the old element in constant time.
This avoids the need to re-calculate the sum for each subarray, leading to a linear time complexity.

the sliding window algorithm is a powerful tool for solving a variety of problems efficiently. By understanding its core principles and limitations, you can effectively apply it to optimize your algorithms and improve their performance.





