###Find Duplicate

##Problem Statement
Given an array A of size N + 1. Each element in array A is between 1 and N. Write a program to find one of the duplicates in array A. If there are multiple answers, then print any.

## Solution Approach
The solution approach for finding the duplicate number in the array leverages binary search, which is an efficient algorithm for finding an item from a sorted list by repeatedly dividing the search interval in half. Although the array itself is not sorted, we use binary search on the range of possible numbers (1 to n) to find the duplicate.

## Description
Given an array of n integers. The task is to find all elements that have more than one occurrences. The output should only one occurrence of a number irrespective of number of occurrences in the input array.


## Examples: 

Input: {2, 10,10, 100, 2, 10, 81,2,81,2}
Output: 2 10 81


Input: {50, 8, 1, 8, 100, 1, 50, 1}
Output: 50 8 1

## Time and Space Complexity
The time complexity of the given code snippet is O(n * log n). This is because the bisect_left function performs binary search, which has a time complexity of O(log n), and it calls the f function on each step of the binary search. The f function has a time complexity of O(n) since it iterates over all n elements in the nums list to calculate the sum of all elements less than or equal to x. Since the binary search is performed in the range of len(nums), which is n, the f function is called O(log n) times, resulting in an overall time complexity of O(n * log n).

The space complexity of the code is O(1). The code uses a constant amount of additional space: the f function and the binary search do not use any extra space that grows with the input size. Therefore, regardless of the size of the input list nums, the additional space required by the algorithm remains constant.