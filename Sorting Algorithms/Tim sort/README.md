# 👉🏻Tim sort Algorithm

# Description

TimSort is a hybrid sorting algorithm that combines Merge Sort and Insertion Sort. It was designed to perform exceptionally well on real-world data, where arrays often contain partially sorted subsequences. TimSort takes advantage of these natural orderings by dividing the input array into small subarrays (called runs) and sorting each run individually with Insertion Sort. Then, the algorithm merges the sorted runs using a Merge Sort-like approach.

# Problem Definition

Given:
-An array arr of n elements.

Objectives:
-Sort the array efficiently using the TimSort algorithm by utilizing both Insertion Sort for small runs and Merge Sort for merging larger segments.

# Algorithm Overview

TimSort is a highly efficient sorting algorithm, especially for real-world applications where data is often partially sorted. Its combination of Insertion Sort for small datasets and Merge Sort for combining larger datasets allows it to achieve optimal performance across a variety of scenarios. The use of stable sorting ensures that the order of equal elements remains consistent throughout the sorting process.

## Time Complexity

**Best Case:**

O(n): When the array is already sorted, TimSort performs optimally. The insertion sort step takes linear time, and the merge step does not need to do much work since the runs are already sorted.

**Average Case:**

**O(n log n):** This occurs for random arrays. The insertion sort runs in linear time for each run, and the merging of runs takes logarithmic time due to the divide-and-conquer approach.
Worst Case:

**O(n log n):** In the worst case, the merging process will dominate the time complexity, similar to other efficient sorting algorithms.
ted array. Suitable for small dataset.


## Space Complexity 
O(n)-TimSort requires additional space for temporary arrays used during the merge process. Specifically, it creates two temporary arrays (LeftArray and RightArray) for merging, each proportional to the size of the runs being merged.
