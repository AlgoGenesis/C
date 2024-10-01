# Insertion Sort

## Description

### Problem Definition

Given:
- An array of integers.

Objective:
- Sort the array using the Insertion Sort algorithm.

### Algorithm Overview

1. **Iterate Through the Array**: Start from the second element (index 1) and iterate through the array.
2. **Select the Current Element**: For each element, store it as the key and initialize a pointer to the previous element.
3. **Shift Elements**: Compare the key with the elements in the sorted portion of the array (to its left). Shift elements that are greater than the key to the right until the correct position for the key is found.
4. **Insert the Key**: Place the key in its correct position in the sorted portion of the array.

### Time Complexity

The average and worst-case time complexity of Insertion Sort is \( O(n^2) \), where \( n \) is the number of elements in the array. The best-case time complexity is \( O(n) \), which occurs when the array is already sorted.

