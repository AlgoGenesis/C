## Merge k Sorted Lists

# Problem Description
The problem of merging k sorted linked lists involves taking k linked lists, each sorted in ascending order, and merging them into a single sorted linked list. The challenge is to do this efficiently, both in terms of time and space.

# Example
Given the following k sorted linked lists:

List 1: 1 -> 4 -> 5
List 2: 1 -> 3 -> 4
List 3: 2 -> 6
The merged sorted linked list should be:

1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6

# Solution Approach
Min-Heap (Priority Queue):

Use a min-heap (or priority queue) to efficiently retrieve the smallest element among the heads of the k lists.
Push the head of each linked list into the min-heap.
Repeatedly extract the minimum element from the heap, adding it to the merged list, and push the next element from the same linked list into the heap.
Continue this process until all elements from all lists have been processed.
Iterative Merging:

Alternatively, you could merge the lists iteratively, but this is less efficient than using a min-heap.