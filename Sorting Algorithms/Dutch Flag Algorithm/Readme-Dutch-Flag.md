
# Dutch National Flag Algorithm

The Dutch National Flag algorithm, proposed by Edsger Dijkstra, is an efficient way to sort an array of three distinct values. The goal is to rearrange the array in a single pass without using any additional space. This algorithm is particularly useful for problems that involve sorting elements into three categories, like sorting 0s, 1s, and 2s.

## Problem Statement

Given an array containing only three distinct values (commonly represented as 0, 1, and 2), sort the array in such a way that all 0s come first, followed by all 1s, and then all 2s.

## Algorithm Overview

The algorithm uses three pointers:
- `low`: Indicates the position where the next 0 should be placed.
- `mid`: Current element pointer that scans through the array.
- `high`: Indicates the position where the next 2 should be placed.

### Steps

1. **Initialization**: Set `low` to 0, `mid` to 0, and `high` to the last index of the array.
2. **Iterate**: Loop through the array while `mid` is less than or equal to `high`:
   - If the element at `mid` is 0, swap it with the element at `low`, then increment both `low` and `mid`.
   - If the element at `mid` is 1, simply move the `mid` pointer forward.
   - If the element at `mid` is 2, swap it with the element at `high`, and decrement `high`. Do not move `mid` in this case, as the swapped element needs to be evaluated.
3. **Completion**: The loop continues until `mid` surpasses `high`, ensuring that all elements are sorted in one pass.

### Time Complexity

- **O(n)**: The algorithm makes a single pass through the array, where `n` is the number of elements in the array.

### Space Complexity

- **O(1)**: The algorithm sorts the array in place and uses a constant amount of additional space.

## C++ Implementation

Here’s a sample implementation of the Dutch National Flag algorithm in C++:

```cpp
#include <iostream>
#include <vector>

using namespace std;

void dutchFlagSort(vector<int>& arr) {
    int low = 0;       // Pointer for the next position of 0
    int mid = 0;       // Pointer for the current element
    int high = arr.size() - 1; // Pointer for the next position of 2

    while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                swap(arr[low++], arr[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid], arr[high--]);
                break;
        }
    }
}

int main() {
    vector<int> arr = {2, 0, 2, 1, 1, 0}; // Example array
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    dutchFlagSort(arr); // Sorting the array using the Dutch Flag algorithm

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
```

## Conclusion

The Dutch National Flag algorithm is a highly efficient and effective method for sorting an array with three distinct values. Its linear time complexity and constant space usage make it suitable for a wide range of applications.

For any further questions or clarifications regarding the algorithm, feel free to reach out!

