#include <stdio.h>

int Rotatedsearch(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if we found the target
        if (nums[mid] == target) {
            return mid;
        }

        // Determine which side is sorted
        if (nums[left] <= nums[mid]) {
            // Left side is sorted
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1; // Search in the left half
            } else {
                left = mid + 1; // Search in the right half
            }
        } else {
            // Right side is sorted
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1; // Search in the right half
            } else {
                right = mid - 1; // Search in the left half
            }
        }
    }

    return -1; // Target not found
}

int main() {
    int nums[] = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = Rotatedsearch(nums, size, target);
    if (result != -1) {
        printf("Target found at index: %d\n", result);
    } else {
        printf("Target not found\n");
    }

    return 0;
}