# Maximum Sum of Non-Adjacent Elements

## Description
This project implements an algorithm to find the maximum sum of non-adjacent elements in an array. The challenge is to select elements such that no two selected elements are adjacent, maximizing the total sum.

### Problem Definition
Given an array of integers, the task is to compute the maximum sum of non-adjacent elements. This means if you select an element at index `i`, you cannot select the elements at indices `i-1` and `i+1`. The objective is to determine the maximum possible sum you can obtain by selecting the appropriate non-adjacent elements.

### Algorithm Overview
The algorithm uses dynamic programming to solve the problem efficiently. The main idea is to maintain a running maximum of sums by deciding for each element whether to include it in the current maximum sum or skip it.

#### Steps
1. **Initialization**: Create two variables, `include` and `exclude`. `include` holds the maximum sum including the current element, while `exclude` holds the maximum sum excluding the current element.
2. **Iterate through the array**: For each element in the array:
   - Calculate a new value for `include`, which is the previous `exclude` value plus the current element.
   - Calculate a new value for `exclude`, which is the maximum of the previous `include` and `exclude`.
3. **Update the values**: Update `include` and `exclude` with the newly calculated values.
4. **Result**: After processing all elements, the result will be the maximum of `include` and `exclude`.

### Time Complexity
The time complexity of this algorithm is O(n), where n is the number of elements in the array, as we only iterate through the array once.




