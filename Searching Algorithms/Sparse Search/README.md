<h1>Sparse search</h1>
A sparse search is specifically designed for scenarios where an array is sorted but contains “sparse” elements like empty strings or placeholders. Standard binary search algorithms may fail in such situations because they assume all elements in the array are valid and comparable. Sparse search adapts the binary search algorithm to handle these gaps, allowing it to efficiently find the target element even when many elements are empty.

<h2>Sparse Search Algorithm Explained</h2>
Array Setup: You have a sorted array where some positions contain valid strings, while others are empty (e.g., ["", "apple", "", "", "banana", "", "cherry"]). The algorithm needs to search for a target string efficiently despite the presence of these empty slots.

<h3>Binary Search:</h3>

Sparse search is a variant of binary search. The array is divided into two halves repeatedly until the target element is found or the search space is exhausted.
In a regular binary search, the middle element of the array is used for comparison. If the middle element matches the target, the search is successful. If it's less or more than the target, the search continues in either the left or right half of the array.
Handling Empty Strings:

If the middle element in a sparse search is non-empty, it can be directly compared with the target.
If the middle element is empty, the algorithm cannot directly compare it to the target. It must look for the nearest non-empty element. This is done by moving both left and right from the middle index until a non-empty element is found. If no non-empty element is found within the current search boundaries, the search terminates.
Comparing and Recursing:

Once a non-empty element is found, it is compared to the target:
If it matches, the search is complete, and the index is returned.
If the non-empty element is less than the target, the search continues in the right half of the array.
If the non-empty element is greater, the search continues in the left half of the array.

<h3>Termination:</h3>

The search continues recursively until the target is found or the left and right boundaries cross, indicating that the target is not in the array.
Example Walkthrough
Consider the array ["", "apple", "", "", "banana", "", "", "cherry", "", "", "date"] and the target "banana":

<h3>First Iteration:</h3>

Calculate the middle index: (0 + 10) / 2 = 5.
The middle element is "" (empty).
Find the nearest non-empty element: moving left and right, "banana" is found at index 4.
Compare "banana" with the target "banana": it's a match, and the index 4 is returned.
<h3>Other Cases:</h3>

If the target were "cherry", the algorithm would continue searching in the right half after finding "banana" and eventually find "cherry".
If the target were not present, the search would exhaust all possibilities and return -1.
<h2>Optimizations and Complexity</h2>
Time Complexity: In the best case (when there are few empty strings), sparse search operates in O(log n) time, similar to binary search. However, if the array has many empty strings, the complexity can degrade because the algorithm needs to search for the nearest non-empty string, potentially scanning parts of the array linearly. In the worst case, the time complexity becomes O(n).
Space Complexity: The algorithm uses O(log n) space due to the recursive nature of the search, similar to binary search.
