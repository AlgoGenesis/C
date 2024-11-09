Kth Largest Element of the Array
 
# Problem Description
The problem is to find the k-th largest element in an unsorted array. The k-th largest element is the element that would be in the k-th position if the array were sorted in descending order.

# Example
Input:
Array: [3, 2, 1, 5, 6, 4]
k = 2
Output:
5
Explanation: The second largest element in the array is 5.

# Solution Approach
There are several ways to solve this problem:

Sorting:

Sort the array in descending order and return the element at index k-1.
Time Complexity: O(n log n) due to sorting.
Space Complexity: O(1) if sorting in place.
Min-Heap:

Use a min-heap of size k. Insert elements into the heap. If the size of the heap exceeds k, remove the smallest element. After processing all elements, the root of the heap will be the k-th largest element.


# Time Complexity: O(n log k).
# Space Complexity: O(k).

# Time and Space Complexity
Time Complexity: O(n) on average, O(n^2) in the worst case (when the pivot is always the smallest or largest element).
Space Complexity: O(1) for the iterative version, as it uses only a constant amount of extra space.