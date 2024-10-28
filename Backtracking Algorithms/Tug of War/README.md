# Tug of War Problem using Backtracking

## Table of Contents

- [Introduction](#introduction)
- [Problem Statement](#problem-statement)
- [Approach](#approach)
- [Algorithm](#algorithm)
- [Complexity Analysis](#complexity-analysis)
- [Implementation](#implementation)
- [Usage](#usage)
- [Example](#example)
- [Possible Improvements](#possible-improvements)
- [License](#license)

## Introduction

The **Tug of War** problem is a famous combinatorial problem that demonstrates the application of **backtracking**. The problem requires dividing a set of numbers into two subsets such that the absolute difference between the sums of the two subsets is minimized. This mirrors the concept of a "tug of war" game where two teams pull with as equal strength as possible.

This problem is especially useful in understanding recursive backtracking approaches, where we try all possible combinations of subsets to find the optimal solution.

## Problem Statement

Given an array of integers, divide it into two subsets of (almost) equal size such that the difference between their sums is as small as possible.

### Input:
- A set of integers (which may include negative values).

### Output:
- Two subsets with a minimal difference between their sums.

## Approach

The solution uses **backtracking** to explore all possible subsets. The key idea is to select half of the elements for one subset and compute the difference between the two subsets' sums. We aim to minimize this difference.

### Steps:
1. Recursively explore subsets by including/excluding elements.
2. Track the sum of the current subset and compare it with the other subset.
3. Continue exploring until you find the optimal split that minimizes the difference.

## Algorithm

### Backtracking Algorithm:
1. **Base Case:** 
   - When half the elements are included in the current subset, calculate the difference and update the result if it's smaller than the current minimum difference.
   
2. **Recursive Case:** 
   - Try including the current element in the subset.
   - Try excluding the current element and recurse further.

3. **Result:** 
   - At the end of the recursive exploration, we will have the two subsets with the smallest possible difference in their sums.

### Complexity Analysis
- **Time Complexity:**  
  The time complexity of this approach is **O(2^n)** because we explore all subsets, and there are \( 2^n \) possible subsets for an array of size `n`.

- **Space Complexity:**  
  The space complexity is **O(n)** due to the space used by recursion and arrays storing the subsets.

## Implementation

The code is implemented in **C** and leverages recursion for the backtracking process.

### Functions:
- **`calculateTotalSum`:** Computes the total sum of the array.
- **`printSubset`:** Prints a subset of the array.
- **`tugOfWarUtil`:** Recursively explores subsets to find the optimal split.
- **`tugOfWar`:** Main function that initializes variables and calls the recursive utility function.

## Usage

### Compilation:
To compile the code, use any C compiler, such as `gcc`:

```bash
gcc tug_of_war.c -o tug_of_war