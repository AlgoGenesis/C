# Counting Sort

# Description

Counting sort is

# Problem Definition

Given:
-An array `arr` of `n` elements.

Objectives:
-Sort the array in ascending order using the Radix Sort algorithm.

# Algorithm Overview

1. Count occurrences: Create a count array that keeps the track of number of occurances of each integer int the input array.
2. Calculate positions: Modify the count array so that each element at aech index represents the position of that integer in the output array.
3. Build the output array: Use the count array to place the elements in their correct sorted order in the output array.

# Time Complexity

Time complexity of counting sort is o(n+k);

- Best case: O(n+k);
- Average case: O(n+k);
- Worst case: O(n+k);

where:
-- n is the number of elements in the input array
-- k is the range of the input (difference between maximum and minimum values).

# Space complexity

The space complexity is O(k+n) due to the additional count and output arrays.

# Advantages

- Stable Sort
- Linear Time Complexity
- Non-comparative

# Disadvantages

- Space Complexity
- Limited to integers
