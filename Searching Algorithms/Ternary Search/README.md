### Problem Statement

Ternary search is a divide-and-conquer algorithm used to find the position of a specific value (target) within a sorted array. The array must be sorted in ascending order for the algorithm to work correctly. The main idea is to divide the array into three parts and determine which part the target value lies in, then recursively search in that part.

### Algorithm Overview

1. **Divide the Array**: 
   - Calculate two mid points, `mid1` and `mid2`. These divide the array into three parts.
   - `mid1` is calculated as `low + (high - low) / 3`.
   - `mid2` is calculated as `high - (high - low) / 3`.

2. **Compare the Target**:
   - If the target is equal to the element at `mid1`, return `mid1`.
   - If the target is equal to the element at `mid2`, return `mid2`.

3. **Recursive Search**:
   - If the target is less than the element at `mid1`, recursively search the left third.
   - If the target is greater than the element at `mid2`, recursively search the right third.
   - Otherwise, recursively search the middle third.

4. **Base Case**:
   - If `low` exceeds `high`, the target is not present in the array.

### Time Complexity

The time complexity of ternary search is \(O(\log_3 n)\), where \(n\) is the number of elements in the array. This is because each step of the algorithm reduces the search space to two-thirds of the current space.
