# Subset Sum using Backtracking

## Description

This program solves the **Subset Sum Problem** using a backtracking approach. Given a set of elements and a target sum, the program finds all possible subsets of the given set whose sum is equal to the target sum. The backtracking technique is used to explore all potential subsets and discard those that exceed the target sum.

## Problem Definition

The **Subset Sum Problem** is defined as follows:

- You are given a set of integers.
- You are also given a target sum `S`.
- The goal is to find all subsets of the given set whose sum is equal to the target sum `S`.

The program checks if a solution exists by comparing the total sum of the given set with the target sum. If the total sum is less than the target sum, no solution exists, and the program outputs an appropriate message.

## Algorithm Overview

The algorithm uses **backtracking** to generate and test subsets of the given set. It operates as follows:

1. **Input Phase**:
   - Accept the number of elements in the set.
   - Accept the actual elements (weights).
   - Accept the required target sum.

2. **Check Feasibility**:
   - If the total sum of the set is less than the target sum, it is impossible to find a valid subset, and the program terminates.

3. **Recursive Backtracking**:
   - The algorithm attempts to build subsets by recursively including or excluding elements.
   - If the current sum equals the target sum, a valid subset is printed.
   - If the current sum exceeds the target sum, or all elements have been processed, the recursive call is terminated (backtracking step).

4. **Base Case**:
   - If the subset sum matches the target sum, the subset is printed.
   - If the index exceeds the number of elements, or if no more valid subsets are possible, the recursion stops.

## Time Complexity

The time complexity of the algorithm is **O(2^n)**, where `n` is the number of elements in the set. This is because there are `2^n` possible subsets of a set with `n` elements, and the algorithm explores all of them in the worst case.

- **Worst-case time complexity**: O(2^n)
- **Space complexity**: O(n) (due to recursion stack and subset storage)

## Example Usage

```bash
Enter the number of elements: 5
Enter the elements: 3 34 4 12 5
Enter the required sum: 9
Subset found: 3 4 5
