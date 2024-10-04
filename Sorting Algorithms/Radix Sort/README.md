# Radix Sort

# Description

Radix sort is a non-comparative, integer sorting algorithm that processes numbers digit by digit , starting from least significant (LSD) to the most significant digit(MSD), or vice versa. It utilizes a stable sub-sorting algorithm, such as counting sort , to sort the numbers based on individual digits.

# Problem Definition

Given:
-An array `arr` of `n` elements.

Objectives:
-Sort the array in ascending order using the Radix Sort algorithm.

# Algorithm Overview

1. Determine the maximum numbers in the array to know the numbers of digits of the largest number.
2. Iterate through each digit place (unit,tens,etc).
3. Sort the array based on the current digit using sub sorting algorithm(e.g., counting sort).
4. Repeat steps 2 and 3 until all digit places have been processed.

# Counting sort for Radix sort

Counting sort is used as a subroutine because it is stable and has a linear time complexity.

# Time complexity

The time complexity of radix sort is o(d.(n+k)), where:

- d is the number of digits in maximum number.
- n is the number of elements in the array.
- k is the range of digit (0 to 9 for decimal system).

Since d and k are constants, the time complexity simplifies to O (n) for practical purposes, making Radix sort efficient for large datasets with a fixed rage of digits.

# Auxiliary Space: 

Radix sort also has a space complexity of O(n + b), 
-  n is the number of elements.
-  b is the base of the number system.

 This space complexity comes from the need to create buckets for each digit value and to copy the elements back to the original array after each digit has been sorted.

# Advantages

- Linear Time Complexity
- Non- comparative

# Disadvantages

- Restricted to Integers
- Additional space
