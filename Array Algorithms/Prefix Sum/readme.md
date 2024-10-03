# Prefix Sum Algorithm

## Description

The **Prefix Sum Algorithm** is an efficient way to preprocess an array so that range sum queries can be answered quickly. It creates a prefix sum array, where each element at index `i` contains the sum of all elements from the start of the array up to index `i`.

### How It Works

1. Construct a `prefix[]` array where `prefix[i]` stores the sum of elements from the original array up to index `i`.
2. To get the sum of elements between indices `l` and `r`, use the formula:
   - `Sum(l, r) = prefix[r] - prefix[l-1]`
   - If `l == 0`, the sum is just `prefix[r]`.

### Time Complexity

- **Preprocessing Time**: O(n)
- **Query Time**: O(1)

### Example

For the array `arr[] = {1, 2, 3, 4, 5}`, the prefix sum array would be `prefix[] = {1, 3, 6, 10, 15}`.  
To find the sum of elements from index `1` to `3`, compute:  
`prefix[3] - prefix[0] = 10 - 1 = 9`


