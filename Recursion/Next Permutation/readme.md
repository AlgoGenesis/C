## Optimized Approach

To find the next permutation, we can eliminate the need for generating all permutations and sorting them by directly using a more efficient algorithm that runs in \(O(n)\) time. Here’s how:

### Steps in the Optimized Code

1. **Find the Pivot**:
   - Traverse the array from the end to find the first index "i" where " {arr}[i] < {arr}[i + 1] ".
   - This step determines the position "i" where we need to make the smallest change to reach the next lexicographical permutation.
   - **Why?**: The last increasing order identifies the position where a change is required to get to the next permutation.

2. **Find the Rightmost Successor**:
   - If such an index "i" is found, then from the end of the array, locate the smallest element that is larger than " {arr}[i] " and swap them.
   - **Why?**: Swapping with the smallest larger element ensures the smallest change to reach the next permutation.

3. **Reverse the Suffix**:
   - Reverse the portion of the array from " (i + 1) " to the end of the array. This gives the smallest lexicographical arrangement for that segment, ensuring we get the next permutation.
   - **Why?**: Reversing the suffix places the elements in ascending order, providing the smallest possible permutation from this point onward.
