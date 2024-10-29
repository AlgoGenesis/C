# Increasing Triplet Subsequence Problem

## Description

This program determines whether there exists an increasing triplet subsequence within a list of integers provided by the user. It employs a linear-time algorithm that maintains a prefix minimum and a suffix maximum to efficiently check for the presence of the triplet.

## Structures

1. **Input Data**

   - Description: An array to hold the input integers.
   - Members:
     - `int *nums`: A pointer to an array of integers representing the input sequence.

## Functions

**bool increasingTriplet(int* nums, int n)**

   - **Parameters**:
     - `int* nums`: A pointer to the array of integers.
     - `int n`: The number of elements in the array.
   - **Returns**:
     - `true` if there exists an increasing triplet subsequence.
     - `false` otherwise.

   - **Description**: This function checks for the existence of an increasing triplet subsequence in the input array by:
     - Initializing a prefix minimum to track the smallest element encountered so far.
     - Iterating through the array to check for the triplet condition.

## Main Function

- **Description**: The entry point of the program.
- **Details**:
  - Prompts the user to enter the number of elements in the array (n).
  - Prompts the user to enter the elements of the array.
  - Calls the `increasingTriplet` function to check for the existence of the triplet subsequence.
  - Prints whether an increasing triplet subsequence exists in the array.

## Example

### Input

```
Enter the number of elements in the array: 5
Enter the elements of the array (space-separated): 1 2 3 4 5
```

### Output

```
An increasing triplet subsequence exists in the array.
```

### Additional Examples

**Example 1:**

- Input: `nums = [5,4,3,2,1]`
- Output: `false`
- Explanation: No triplet exists.

---

**Example 2:**

- Input: `nums = [2,1,5,0,4,6]`
- Output: `true`
- Explanation: The triplet `(3, 4, 5)` is valid because `nums[3] == 0 < nums[4] == 4 < nums[5] == 6`.


## Notes

- The algorithm runs in O(n) time complexity and O(n) space complexity due to the auxiliary array used for suffix maximums.
- This program is designed to handle inputs of varying lengths and values, ensuring robustness and efficiency.