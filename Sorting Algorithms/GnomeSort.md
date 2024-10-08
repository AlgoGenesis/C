---
id: gnome-sort-algo  
sidebar_position: 13  
title: Gnome Sort  
sidebar_label: Gnome Sort  
---

### Definition:

Gnome sort is a simple, in-place sorting algorithm that resembles insertion sort. It operates by iterating through the array and swapping elements that are out of order. The algorithm is named after the way it is said to "walk" through the array—like a gnome tending a garden.

### Characteristics:

- **In-Place Sorting**: 
  - Gnome sort requires no additional storage for sorting; it sorts the array in place.

- **Stable**: 
  - Gnome sort is a stable sorting algorithm, meaning it maintains the relative order of equal elements.

- **Easy to Understand**: 
  - The algorithm is straightforward to implement and understand, making it a good choice for educational purposes.

### Time Complexity:

- **Best Case: O(n)**  
  If the array is already sorted, Gnome sort only requires one pass through the array.

- **Average Case: O(n²)**  
  In most cases, it performs a quadratic number of comparisons and swaps, similar to selection sort and bubble sort.

- **Worst Case: O(n²)**  
  In the worst case, Gnome sort has a time complexity of O(n²), which occurs when the elements are in reverse order.

### Space Complexity:

- **Space Complexity: O(1)**  
  Gnome sort is an in-place algorithm, requiring no additional memory besides the input array.

### C++ Implementation:

```cpp
#include <iostream>
using namespace std;

// Function to perform gnome sort
void gnomeSort(int arr[], int size) {
    int index = 0;

    while (index < size) {
        if (index == 0) {
            index++;
        }
        if (arr[index] >= arr[index - 1]) {
            index++;
        } else {
            swap(arr[index], arr[index - 1]);
            index--;
        }
    }
}

int main() {
    int arr[] = {34, 2, 10, -9};
    int size = sizeof(arr) / sizeof(arr[0]);

    gnomeSort(arr, size);

    cout << "Sorted array: \n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
### Explanation:

1. **Iteration and Swapping**:
   - The algorithm starts at the beginning of the array. It compares the current element with the previous one. If they are in the correct order (i.e., the current element is greater than or equal to the previous element), it moves forward. If not, it swaps them and moves one step back.

2. **Backtracking**:
   - If a swap is made, the algorithm backtracks one position to check if the swapped element is in the correct order with the new previous element. This continues until the entire array is sorted.

3. **Simple Logic**:
   - Gnome sort uses simple logic and operations, making it easy to implement and understand, although not the most efficient.

### Summary:

Gnome sort is a straightforward sorting algorithm that is simple to implement and understand. However, its quadratic time complexity makes it less efficient for larger datasets compared to more advanced sorting algorithms like quick sort or merge sort. Its primary use case is educational, illustrating basic sorting concepts and algorithms. While it performs well on small or nearly sorted datasets, it is not suitable for general-purpose sorting in performance-critical applications.
