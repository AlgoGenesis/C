### Rotated Sorted Array

### Description

A *rotated sorted array* is an array that was initially sorted but then rotated at some unknown pivot. For example, an array [1, 2, 3, 4, 5] might be rotated to [4, 5, 1, 2, 3]. A *rotated binary search* is a modified version of binary search that works efficiently on such arrays to find a target element.

### Problem Definition

You are given an array that was initially sorted in ascending order but then rotated at some unknown index. The task is to search for a specific target element in this rotated sorted array and return its index if found. If the element is not present, return -1.

#### Input:
- A rotated sorted array arr[] of n integers.
- An integer target representing the element to be searched.

#### Output:
- Return the index of the target element if it exists in the array. Otherwise, return -1.

#### Constraints:
- The array does not contain duplicate elements.
- The solution should be completed with a time complexity better than O(n) (linear search).

### Example:

#### Input:
- Array: [4, 5,7 , 8, 0, 1, 2]
- Target: 7

#### Output:
- Index of target: 2

### Algorithm Review

The approach for solving the problem is to apply a modified version of *binary search*. In a binary search, we usually assume the array is fully sorted, but in a rotated sorted array, only one part is sorted, and the other part is rotated. 

The algorithm identifies which part of the array is sorted and narrows down the search space accordingly.

#### Steps:

1. *Initialize Low and High Pointers*: Set low = 0 and high = n-1.
2. *Check Middle Element*: Calculate the middle index mid = low + (high - low) / 2.
3. *Check if Target is at Mid*: If arr[mid] == target, return mid.
4. *Determine Sorted Side*:
   - If the left part (arr[low] to arr[mid]) is sorted (arr[low] <= arr[mid]):
     - Check if the target is within this sorted range (arr[low] <= target <= arr[mid]). If yes, continue searching in this range (high = mid - 1). Otherwise, search in the right part (low = mid + 1).
   - If the right part (arr[mid] to arr[high]) is sorted (arr[mid] <= arr[high]):
     - Check if the target is within this sorted range (arr[mid] <= target <= arr[high]). If yes, continue searching in this range (low = mid + 1). Otherwise, search in the left part (high = mid - 1).
5. *Repeat Until Target is Found*: Continue adjusting the search space until the target is found or the search space is exhausted.

## Time Complexity
The time complexity of the rotated binary search algorithm is O(log n), where n is the number of elements in the array. This is because the array is halved in each iteration of the binary search:
