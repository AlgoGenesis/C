# Library Sort

## Description

Library Sort is a sorting algorithm that is a variant of insertion sort. It maintains a sorted array with gaps to allow for efficient insertion of new elements. This algorithm is also known as gapped insertion sort.

## Problem Definition

Given:
- An array `arr` of `n` elements.

Objectives:
- Sort an array in ascending order using library sort.

## Algorithm Overview

1. **Initialize**: Start with an empty sorted array with gaps.
2. **Insert**: For each element in the input array, find the correct position in the sorted array and insert it, shifting elements as necessary.
3. **Rebalance**: Periodically rebalance the array to maintain gaps for efficient insertion.

## Time Complexity

The time complexity of Library Sort is `O(n log n)` on average, but it can degrade to `O(n^2)` in the worst case if the gaps are not managed properly. It is efficient for datasets where insertions are frequent and the array needs to remain sorted.