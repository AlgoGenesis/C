#include <stdio.h>
#include <stdlib.h>

// Function to partition the array
int partition(int* arr, int left, int right, int pivotIndex) {
    int pivotValue = arr[pivotIndex];
    // Move pivot to end
    int temp = arr[pivotIndex];
    arr[pivotIndex] = arr[right];
    arr[right] = temp;
    int storeIndex = left;

    for (int i = left; i < right; i++) {
        if (arr[i] > pivotValue) { // Change to > for k-th largest
            temp = arr[storeIndex];
            arr[storeIndex] = arr[i];
            arr[i] = temp;
            storeIndex++;
        }
    }
    // Move pivot to its final place
    temp = arr[right];
    arr[right] = arr[storeIndex];
    arr[storeIndex] = temp;
    return storeIndex;
}

// Quickselect function to find k-th largest element
int quickSelect(int* arr, int left, int right, int k) {
    if (left == right) {
        return arr[left];
    }
    int pivotIndex = left + rand() % (right - left + 1);
    pivotIndex = partition(arr, left, right, pivotIndex);

    if (k == pivotIndex) {
        return arr[k];
    } else if (k < pivotIndex) {
        return quickSelect(arr, left, pivotIndex - 1, k);
    } else {
        return quickSelect(arr, pivotIndex + 1, right, k);
    }
}

// Function to find the k-th largest element
int findKthLargest(int* nums, int numsSize, int k) {
    return quickSelect(nums, 0, numsSize - 1, k - 1);
}

int main() {
    int nums[] = {3, 2, 1, 5, 6, 4};
    int k = 2;
    int size = sizeof(nums) / sizeof(nums[0]);
    int result = findKthLargest(nums, size, k);
    printf("The %d-th largest element is %d\n", k, result);
    return 0;
}