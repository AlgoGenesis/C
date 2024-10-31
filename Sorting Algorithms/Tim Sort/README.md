# TimSort Algorithm

## Overview
This implementation of TimSort is a hybrid sorting algorithm that combines **Insertion Sort** for smaller segments and **Merge Sort** for merging these segments. It is particularly optimized for real-world data, often partially sorted, making TimSort the default sorting algorithm in languages like Python.

## Code Explanation

### `insertionSort(arr, left, right)`

**Purpose:**  
Sorts a small chunk (or "run") of the array in place using **Insertion Sort**.

**Parameters:**
- `arr[]`: The array to be sorted.
- `left`: Starting index of the chunk.
- `right`: Ending index of the chunk.

**Explanation:**
- **Insertion Sort** is efficient for sorting small subarrays due to its simplicity and minimal overhead. It works by repeatedly picking an element from the unsorted part of the array and inserting it in its correct position within the sorted portion of the array.
- In this function, we start from the `left` index and go up to the `right` index.
- For each element starting from `left + 1`, we pick the element and find the correct position by shifting elements in the sorted portion one position to the right until we find the correct position for the picked element.
- Once positioned, the sorted chunk within `arr[left...right]` is in ascending order.

**Example:**  
If the chunk to be sorted is `[34, 7, 23, 32]`, applying `insertionSort` will yield `[7, 23, 32, 34]`.


### `merge(arr, left, mid, right)`

**Purpose:**  
Merges two sorted runs within the array into a single sorted segment, implementing the **Merge Sort** merge operation.

**Parameters:**
- `arr[]`: The array containing the sorted runs to merge.
- `left`: Starting index of the first sorted run.
- `mid`: Ending index of the first sorted run; `mid + 1` is the starting index of the second sorted run.
- `right`: Ending index of the second sorted run.

**Explanation:**
- This function divides the specified section of the array into two parts: `arr[left...mid]` and `arr[mid+1...right]`, both of which are already sorted (from previous Insertion Sort or merge steps).
- It then creates two temporary arrays: `leftArr[]` for the left run and `rightArr[]` for the right run, copying values from `arr[]` into these.
- A two-pointer technique is applied: pointers `i` and `j` traverse `leftArr` and `rightArr` respectively, comparing the elements at each step and placing the smaller one back into `arr[]` at index `k`.
- This ensures that `arr[left...right]` is sorted once merging completes.

**Example:**  
Given two sorted runs `[7, 23]` and `[5, 62]`, merging them will yield `[5, 7, 23, 62]`.

### `timSort(arr, n)`

**Purpose:**  
Implements the main Tim Sort logic by dividing the array into small "runs," sorting each run with **Insertion Sort**, and merging these runs progressively using **Merge Sort**.

**Parameters:**
- `arr[]`: The array to be fully sorted.
- `n`: Size of the array.

**Explanation:**
- **Step 1**: The function first sorts individual chunks or "runs" of size `RUN` (32 by default) using `insertionSort()`. This is because Insertion Sort is efficient for small subarrays.
- **Step 2**: After sorting all individual runs, it repeatedly merges runs of increasing sizes (from 32 to 64, 128, and so on) to build larger sorted sections. It uses the `merge()` function for each merging operation.
  - For each step, the `size` of the run doubles, ensuring that all runs in the array are progressively combined into larger sorted sections until the entire array is sorted.
- By the end of `timSort()`, `arr[]` is fully sorted in ascending order.

**Example Walkthrough:**  
For an array `[34, 7, 23, 32, 5, 62]`:
1. **Run Sorting**: First, Insertion Sort is applied to the entire array, producing `[5, 7, 23, 32, 34, 62]` as each element is part of a single run.
2. **Merging**: Since the entire array is sorted in a single run, no further merging is required.

Here's a dry run example for Tim Sort on an array `[34, 7, 23, 32, 5, 62]` with a `RUN` size of 3. This example will demonstrate how Tim Sort operates on smaller chunks and then merges these sorted chunks.

### Initial Array
```
Array: [34, 7, 23, 32, 5, 62]
```

### Step-by-Step Dry Run

#### Step 1: Sorting Runs with Insertion Sort

1. **First Run `[34, 7, 23]`**:
   - Apply `insertionSort()` on `[34, 7, 23]`.
   - After sorting: `[7, 23, 34]`.

2. **Second Run `[32, 5, 62]`**:
   - Apply `insertionSort()` on `[32, 5, 62]`.
   - After sorting: `[5, 32, 62]`.

After sorting the runs, we have:
```
Array after sorting runs: [7, 23, 34, 5, 32, 62]
```

#### Step 2: Merging Runs

Since the array size is 6 and each run size is 3, we now merge these two sorted runs `[7, 23, 34]` and `[5, 32, 62]`.

1. **Merging `[7, 23, 34]` and `[5, 32, 62]`**:
   - Compare the first elements of each run: `7` and `5`.
   - Insert `5` (smallest) into the merged array.
   - Next, compare `7` and `32`. Insert `7`.
   - Next, compare `23` and `32`. Insert `23`.
   - Next, compare `34` and `32`. Insert `32`.
   - Finally, insert the remaining elements `34` and `62`.
   
Result after merging:
```
Array after merging: [5, 7, 23, 32, 34, 62]
```

### Final Sorted Array
The fully sorted array is:
```
[5, 7, 23, 32, 34, 62]
```

### Summary of the Dry Run

- **Initial Runs**: `[34, 7, 23]` → `[7, 23, 34]`, `[32, 5, 62]` → `[5, 32, 62]`.
- **First Merge**: `[7, 23, 34]` and `[5, 32, 62]` → `[5, 7, 23, 32, 34, 62]`.
- **Final Output**: `[5, 7, 23, 32, 34, 62]`.

### Time Complexity
Tim Sort's time complexity can be analyzed in two parts:
1. **Insertion Sort** (for sorting small runs): `O(RUN * n/RUN) = O(n)`. Here, `RUN` is a constant (typically 32 or 64).
2. **Merge Sort** (for merging sorted runs): `O(n log n)`.

Combining both, the overall time complexity is:
- **Best Case**: `O(n)` when the array is already nearly sorted due to efficient run merging.
- **Average Case**: `O(n log n)`.
- **Worst Case**: `O(n log n)`, typical for random data or worst-case scenarios.

### Space Complexity
Tim Sort requires extra space for merging, which has a **space complexity of `O(n)`** for storing temporary arrays during the merging process.



## Advantages of Using TimSort
- **Optimized for Real-World Data**: Performs exceptionally well on partially sorted data, common in real-world scenarios.
- **Combination of Two Algorithms**: Combines Insertion Sort’s efficiency for small data sets with Merge Sort’s efficiency for large data sets.
- **Stable Sort**: Retains the order of equal elements in the array.

---