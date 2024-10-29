# Bead Sort Algorithm

## Description

Bead Sort, also known as Gravity Sort, is a natural sorting algorithm that mimics the physical process of beads falling due to gravity. The algorithm represents each number in the array by beads stacked vertically and simulates how gravity would naturally cause them to align in sorted order. It works best when sorting integers and is particularly intuitive, resembling an abacus-style sorting method.

# Problem Definition
Given:

An array arr of n non-negative integers.
## Objective:

Sort the array in ascending order using the Bead Sort algorithm by simulating the natural alignment of beads under gravity.
## Algorithm Overview
Create a Bead Grid: Represent the array as a 2D grid where each row corresponds to an element of the array, and each column represents a bead.
Simulate Gravity: Let the beads "fall" vertically in each column, simulating the effect of gravity pulling the beads downward.
Count the Beads: Once the beads have fallen, count the beads in each row to reconstruct the sorted array.
End Sorting: After all beads have aligned, the elements of the array are sorted in ascending order.
Time Complexity
The time complexity of Bead Sort is determined by the sum of the values in the array. This leads to the following time complexity:

# Best Case: O(n) when the elements are already sorted and the values are small.
# Average Case: O(S), where S is the sum of the elements in the array.
# Worst Case: O(S), where S is large, making it inefficient for very large numbers.
## Advantages
Simple and intuitive algorithm, especially for small integers.
Can be parallelized in certain situations, allowing for better performance in specific hardware environments.
Requires no comparisons between elements, which makes it different from most comparison-based sorting algorithms.
## Disadvantages
Limited to sorting non-negative integers and may not work well with larger numbers due to its reliance on the sum of values.
Not practical for floating-point numbers or very large ranges of values.
Inefficient compared to more general sorting algorithms (e.g., Quick Sort, Merge Sort) for large datasets with wide ranges of values.
## Conclusion
Bead Sort is an interesting algorithm that mimics a physical sorting process and works well with small, non-negative integer arrays. Although it has its limitations, especially for large numbers or ranges, it provides an intuitive, gravity-based approach to sorting and can be applied in parallel computing environments where its simplicity may offer advantages.

