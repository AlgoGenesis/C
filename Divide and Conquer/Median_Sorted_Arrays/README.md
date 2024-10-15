# Median of Two Sorted Arrays (Divide and Conquer)

## Problem Description
The task is to find the median of two sorted arrays. Given two sorted arrays `nums1` and `nums2` of sizes `m` and `n` respectively, we need to return the median of these two sorted arrays. The overall run-time complexity should be O(log(min(m,n))).

## Solution Approach: Divide and Conquer

### Algorithm
The divide-and-conquer approach is efficient and leverages binary search to find the median. The idea is to partition both arrays in such a way that all elements on the left side of the partition are smaller than those on the right side.

### Steps:
1. **Partitioning the Arrays**: 
   - We perform binary search on the smaller of the two arrays (`nums1` or `nums2`).
   - For each partitioning, we ensure that the elements on the left partition of both arrays are less than or equal to the elements on the right partition.
   
2. **Check Median Conditions**:
   - If the total number of elements is odd, the median is the maximum of the left partitions.
   - If the total number of elements is even, the median is the average of the maximum of the left partitions and the minimum of the right partitions.
   
3. **Adjust Partitioning**:
   - If the maximum element on the left side of one partition is greater than the minimum element on the right side of the other partition, adjust the binary search bounds.

### Time Complexity:
The time complexity is O(log(min(m, n))) because we're performing binary search on the smaller array.
