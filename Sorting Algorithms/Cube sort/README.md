# Cube Sort

## Overview

Cube Sort is a sorting algorithm designed to efficiently sort data points in a multi-dimensional space, particularly in three dimensions. This algorithm is particularly useful in applications such as computer graphics, spatial databases, and multidimensional data processing. It utilizes a divide-and-conquer strategy to partition the data into smaller cubes, sort them, and then merge them back into a single sorted output.

## Features

- **Multi-Dimensional Sorting**: Handles sorting in three dimensions, making it suitable for spatial data.
- **Efficiency**: Can be more efficient than traditional sorting algorithms for uniformly distributed datasets.
- **Divide and Conquer**: Divides the data space into sub-cubes, sorts each, and merges them.

## Applications

- Computer graphics (sorting objects based on spatial positions)
- Spatial databases
- Multidimensional data analysis

## Algorithm Steps

1. **Partitioning**: Divide the data into smaller cubes based on their dimensional attributes.
2. **Sorting**: Sort each sub-cube using a conventional sorting algorithm (e.g., quicksort or mergesort).
3. **Merging**: Combine the sorted sub-cubes into a final sorted output.

## Complexity

The time complexity of Cube Sort can vary based on the size and distribution of the dataset. In general, it may perform better than O(n log n) for specific datasets in high-dimensional spaces.

## How to Compile and Run

1. Save the code in a file named `cube_sort.c`.
2. Open a terminal and navigate to the directory containing the file.
3. Compile the code using GCC:
