# Pigeonhole Sort

## Description

Pigeonhole Sort is a sorting algorithm that is based on the idea of distributing elements into a series of "pigeonholes" or bins, based on their value. Once the elements are distributed into these pigeonholes, they are collected back in sorted order. Pigeonhole Sort is efficient when the range of elements is small compared to the number of elements.

### Problem Definition

Given:
- An array of integers where the values fall within a known range.

Objective:
- Sort the array using the Pigeonhole Sort algorithm.

### Algorithm Overview

1. **Find the Minimum and Maximum**: Identify the minimum and maximum elements in the input array.
2. **Create Pigeonholes**: Create an array of pigeonholes (buckets), where each pigeonhole corresponds to a range of values in the input array.
3. **Place Elements into Pigeonholes**: For each element in the array, determine its corresponding pigeonhole and place the element in that pigeonhole.
4. **Sort and Collect**: After placing all elements in their respective pigeonholes, the elements in each pigeonhole are sorted (in this case, they are collected in the order they appear, as they are already sorted by the pigeonhole distribution).