# Radix Sort

## What is Radix Sort?

Radix Sort is a non-comparative integer sorting algorithm that sorts data with integer keys by grouping the keys by individual digits that share the same significant position and value. It sorts the elements by processing each digit or character position, starting from the least significant digit to the most significant digit.

## How it works:

1. Find the maximum element to know the number of digits.
2. Do counting sort for every digit. Note that instead of passing digit number, exp is passed. exp is 10^i where i is the current digit number.
3. Start from the least significant digit (ones place) and move towards the most significant digit.

## When to use:

- When dealing with numbers in a fixed range
- When sorting strings or integers
- When a stable sort is required

## Pros and Cons:

Pros:
- Can be faster than O(n log n) comparison-based sorting algorithms for certain types of data
- Stable sorting algorithm
- Works well with fixed-size integers or strings

Cons:
- Requires extra space
- Performance depends on the number of digits or characters in the input elements
- Not suitable for floating-point numbers without special consideration

## Time Complexity:
- Best case: O(nk) where n is the number of elements and k is the number of digits in the maximum element
- Average case: O(nk)
- Worst case: O(nk)

Note: Radix sort can be faster than O(n log n) algorithms for integers with a limited number of digits.