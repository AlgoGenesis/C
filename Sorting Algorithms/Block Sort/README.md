# Block Sort

## Overview
Block Sort is a sorting algorithm that divides the input array into smaller blocks, sorts each block individually, and then combines the results. This technique can enhance performance, particularly for specific data distributions.

## How it Works
1. **Divide**: The input array is divided into blocks of a specified size, often chosen to be the square root of the total number of elements.
2. **Sort Each Block**: Each block is sorted independently using a sorting function (e.g., Quick Sort).
3. **Merge**: After sorting the blocks, the entire array is sorted again to ensure the blocks are correctly ordered.

## Time Complexity
- **Best Case**: O(n log n) when blocks are well-distributed.
- **Average Case**: O(n log n).
- **Worst Case**: O(n log n) for large datasets.

## Space Complexity
- O(n) due to the need for temporary storage during sorting.

## Conclusion
Block Sort can be an efficient sorting method for specific types of datasets. Its performance relies on the size of the blocks and the data distribution within the array.