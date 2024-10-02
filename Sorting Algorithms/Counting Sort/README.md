# Counting Sort

## What is Counting Sort?

Counting Sort is a non-comparison-based sorting algorithm that works well when there is limited range of input values. It works by counting the number of objects having distinct key values, and using arithmetic to determine the positions of each key value in the output sequence.

## How it works:

1. Find the range of input values (min to max).
2. Count the occurrences of each value in the input.
3. Calculate the position of each element in the sorted array.
4. Build the output array using the calculated positions.

## When to use:

- When the range of potential items in the input is known and reasonably small
- When dealing with integers or data that can be mapped to integers

## Pros and Cons:

Pros:
- Linear time complexity O(n+k) where k is the range of input
- Stable sorting algorithm
- Efficient for datasets with small ranges

Cons:
- Requires extra space proportional to the range of input
- Not suitable for sorting non-integer data directly
- Inefficient when the range of input values is large compared to the number of elements

## Time Complexity:
- Best case: O(n+k)
- Average case: O(n+k)
- Worst case: O(n+k)

Where n is the number of elements and k is the range of input.