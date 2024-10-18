## Find the Longest Subarray with All Distinct Numbers

### Problem Statement

Given an array of integers, find the length of the longest subarray where all the elements are unique.

- **Input**: The first line contains an integer `n` (the number of elements in the array). The second line contains `n` integers representing the array.
- **Output**: Print the length of the longest subarray where no elements are repeated.

### Algorithm / Intuition

1. **Initialize**:
   - `i` and `j` as pointers, both starting at the beginning of the array (`i = 0`, `j = 0`).
   - `v` as 0 to keep track of the maximum length of unique elements found so far.
   - A hashmap (`k`) to store the last index of each element.

2. **Expand the Window**:
   - While `j` is within the array:
     - If the element `b[j]` is not in the current window (it hasn’t been seen before or was removed earlier):
       - Add it to the hashmap `k`.
       - Calculate the current window length as `(j - i + 1)`.
       - Update `v` if the current length is the largest so far.
       - Move `j` one step to the right to expand the window.
     - If the element `b[j]` is already in the window (seen before):
       - Find its last position in the hashmap.
       - Move `i` (the start of the window) to the next position after this last occurrence to remove duplicates.
       - Update the hashmap with the new index of `b[j]` and move `j` one step to the right.

3. **Output the Result**:
   - After iterating through the entire array, print the maximum length `v` found.

### Complexity Analysis

#### Time Complexity
- The program runs in **O(n)** time, where `n` is the number of elements in the array.
- It uses two pointers (`i` and `j`), moving them to expand and shrink the window of unique elements.
- Each element is checked at most twice (once when expanding and once when shrinking the window).
- Therefore, the total operations are roughly `2 * n`, which simplifies to **O(n)**.

#### Space Complexity
- The space complexity is **O(n)** in the worst case.
- We use a hashmap (`k`) to keep track of the last position of each element. At most, it holds `n` elements (if all are unique).
- The array `b` also takes **O(n)** space.
- Other variables take constant space, so the total space used is **O(n)**.