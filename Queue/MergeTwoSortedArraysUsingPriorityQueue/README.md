# Merging Two Sorted Arrays Using Priority Queue

To solve this problem, merge two sorted arrays using a priority queue. We will create a min priority queue, and we will push elements of both the array. After that, we will take out elements from the priority queue one by one, and we will insert that element into our final array, and then we will return the array.

# Approach

Use a priority queue (min-heap) to store elements.
Insert elements from both arrays into the min-heap.
Extract elements from the min-heap one by one to get them in sorted order.
This approach takes advantage of the heap's property to keep the smallest element at the root, ensuring that elements are retrieved in sorted order.

# Explanation

Min-Heap Creation: We create a min-heap with a capacity equal to the total size of both arrays.
Insert Elements: We insert all elements from both arrays into the min-heap, which maintains the sorted order within the heap.
Extract Elements: We then extract elements from the min-heap one by one, resulting in a merged, sorted array.

# Time-Complexity

Time Complexity:
𝑂
(
(
𝑛

- 𝑚
  )
  log
  ⁡
  (
  𝑛
- 𝑚
  )
  )
  O((n+m)log(n+m)), where
  𝑛
  n and
  𝑚
  m are the sizes of the two arrays.
  Space Complexity:
  𝑂
  (
  𝑛
- 𝑚
  )
  O(n+m), due to the auxiliary space used by the heap.

  # Example

  Input: A[] = { 5, 6, 8 }, B[] = { 4, 7, 8 }
  Output: 4 5 6 7 8 8

Input: A[] = {1, 3, 4, 5}, B[] = {2, 4, 6, 8}
Output: 1 2 3 4 4 5 6 8

Input: A[] = {5, 8, 9}, B[] = {4, 7, 8}
Output: 4 5 7 8 8 9
