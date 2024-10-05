# Moore's Voting Algorithm

## Overview

Moore's Voting Algorithm is an efficient algorithm used to find a majority element in a given array or list. A majority element is defined as an element that appears more than `n/2` times in the array, where `n` is the number of elements in the array.

This algorithm works in **O(n)** time and requires **O(1)** extra space, making it highly efficient for solving the problem.

## Algorithm Steps

1. **Find a Candidate**:

   - The algorithm first tries to find a potential majority candidate by iterating through the array. It maintains a count variable to track how many times the current element appears compared to other elements.
   - If the count is 0, it resets the current element as the new candidate.

2. **Verify the Candidate**:
   - After selecting the candidate, the algorithm iterates through the array again to check if the candidate actually occurs more than `n/2` times.

## Pseudo-Code:

1. **Initialization**: Set the first element as the candidate and initialize the count to 1.
2. **Iteration**: Traverse the array and:
   - Increment the count if the current element matches the candidate.
   - Decrement the count if it doesn't match.
   - If the count becomes 0, set the current element as the new candidate.
3. **Verification**: Check if the candidate is the majority element by counting its occurrences in the array.

## Example:

Given an array `[2, 2, 1, 1, 2, 2, 3, 2]`, Moore's Voting Algorithm will:

1. Identify `2` as the candidate majority element after iterating through the array.
2. Verify that `2` appears more than `n/2` times, and thus declare it as the majority element.

## Time and Space Complexity:

- **Time Complexity**: `O(n)`, where `n` is the number of elements in the array.
- **Space Complexity**: `O(1)` as it uses constant extra space.
