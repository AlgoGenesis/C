## Lower Bound Algorithm
#### Overview
- The Lower Bound Algorithm is used to find the smallest index in a sorted array where the value at that index is greater than or equal to a given target x. This algorithm is useful when working with sorted data, where you need to quickly find the position of the first element that satisfies the condition of being greater than or equal to the target.

- The algorithm efficiently solves this problem using binary search, making it run in O(log n) time complexity, where n is the size of the array.

#### Definition
The Lower Bound is defined as the smallest index ind such that:

```cpp
arr[ind] >= target
```
If such an index is not found, the algorithm returns n, which is the size of the array, indicating that all elements are smaller than x.

#### Algorithm Explanation

(1). Initialization:

- We will declare two pointers, low and high, and an ans variable, initialized to n (size of the array).
The ans variable will store the result, and if no such index is found, we will return n.

(2). Set the Pointers:

- low starts at the first index (0).
- high starts at the last index (n-1).

(3). Binary Search Loop:

Calculate the middle index (mid) using the formula:
```cpp
mid = (low + (high-low)) // 2
```

Compare the value at the mid index with the target value x:
- Case 1: If arr[mid] >= x, this means that mid might be the answer. We store mid in ans and continue searching for a potentially smaller index on the left side (high = mid - 1).
- Case 2: If arr[mid] < x, this means mid cannot be the answer, so we continue searching in the right half (low = mid + 1).

#### Return the Result:

After the loop, the ans variable contains the smallest index where arr[ind] >= x. If no such index is found, it will return n.

#### Time Complexity
- Time complexity: O(log n) due to the binary search.
- Space complexity: O(1) since we use only a few extra variables.