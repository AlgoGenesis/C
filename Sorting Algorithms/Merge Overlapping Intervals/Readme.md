## Merge Overlapping Interval

## Problem Statement
Given a set of time intervals in any order, our task is to merge all overlapping intervals into one and output the result which should have only mutually exclusive intervals.

## Proposed Solution
Approach
The steps are as follows:

First, we will group the closer intervals by sorting the given array of intervals(if it is not already sorted).
After that, we will select one interval at a time using a loop(say i) and insert it into our answer list(if the answer list is empty or the current interval cannot be merged with the last interval of the answer list). While traversing and inserting we will skip the intervals that lie in the last inserted interval of our answer list.
Now, for each interval arr[i], using another loop (say j) we are going to check the rest of the intervals(i.e. From index i+1 to n-1) if they can be merged with the selected interval.
Inside loop j, we will continue to merge all the intervals that lie in the selected interval. 
How to check if the current interval can be merged with the selected interval:
We will compare the current interval’s start with the end of the selected interval. If the start is smaller or equal to the end, we can conclude the current interval can be a part of the selected interval. So, we will update the selected interval’s end with the maximum(current interval’s end, selected interval’s end) in the answer list(not in the original array).
We will break out of loop j, from the first element that cannot be a part of the selected interval.
How to check if the current interval is not a part of the selected interval:
We will compare the current interval’s start with the end of the selected interval. If the start is greater than the end, we can conclude the current interval cannot be a part of the selected interval.
Finally, we will return the answer list.

## Complexity Analysis
Time Complexity: O(N*logN) + O(2*N), where N = the size of the given array.
Reason: Sorting the given array takes  O(N*logN) time complexity. Now, after that, we are using 2 loops i and j. But while using loop i, we skip all the intervals that are merged with loop j. So, we can conclude that every interval is roughly visited twice(roughly, once for checking or skipping and once for merging). So, the time complexity will be 2*N instead of N2.

Space Complexity: O(N), as we are using an answer list to store the merged intervals. Except for the answer array, we are not using any extra space.
