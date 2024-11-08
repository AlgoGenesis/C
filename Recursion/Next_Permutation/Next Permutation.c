#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int* nums, int start, int end) {
    while (start < end) {
        swap(&nums[start], &nums[end]);
        start++;
        end--;
    }
}

void nextPermutation(int* nums, int numsSize) {
    if (numsSize <= 1) return;

    // Step 1: Find the largest index k such that nums[k] < nums[k + 1]
    int k = -1;
    for (int i = numsSize - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            k = i;
            break;
        }
    }

    // If no such index exists, the permutation is the last permutation
    if (k == -1) {
        reverse(nums, 0, numsSize - 1);
        return;
    }

    // Step 2: Find the largest index l greater than k such that nums[k] < nums[l]
    int l = -1;
    for (int i = numsSize - 1; i > k; i--) {
        if (nums[i] > nums[k]) {
            l = i;
            break;
        }
    }

    // Step 3: Swap the value of nums[k] with that of nums[l]
    swap(&nums[k], &nums[l]);

    // Step 4: Reverse the sequence from nums[k + 1] to the end
    reverse(nums, k + 1, numsSize - 1);
}

// Helper function to print the array
void printArray(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main() {
    int nums[] = {1, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    printf("Original array: ");
    printArray(nums, numsSize);

    nextPermutation(nums, numsSize);

    printf("Next permutation: ");
    printArray(nums, numsSize);

    return 0;
}