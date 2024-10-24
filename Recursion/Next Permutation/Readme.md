## Next Permutation

# Problem Statement
Given an array arr[] of size n, the task is to print the lexicographically next greater permutation of the given array. If there does not exist any greater permutation, then find the lexicographically smallest permutation of the given array.

# Approach
The very basic idea that comes to our mind is that we would first generate all possible permutations of a given array and sort them. Once sorted, we locate the current permutation within this list. The next permutation is simply the next arrangement in the sorted order. If the current arrangement is the last in the list then display the first permutation (smallest permutation).

# Example
If we give any of the above (except the last) as input, we need to find the next one in sequence. If we give last as input, we need to return the first one.

Examples:

Input: arr = {2, 4, 1, 7, 5, 0}
Output: { 2, 4, 5, 0, 1, 7 }
Explanation: The next permutation of the given array is 2 4 5 0 1 7


Input: arr = {3, 2, 1}
Output: {1, 2, 3}
Explanation: As arr[] is the last permutation. So, the next permutation is the lowest one.

# Time and Space Complexity
Time Complexity: O(n!*n*log(n!)), n represents the number of elements present in the input sequence represent all possible permutation.
Auxiliary Space: O(n!), for storing the permutations