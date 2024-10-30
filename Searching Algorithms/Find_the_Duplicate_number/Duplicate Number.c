#include <stdio.h>

int findDuplicateNum(int* nums, int numsSize) {
    // Step 1: Initialize the tortoise and hare
    int tortoise = nums[0];
    int hare = nums[0];

    // Step 2: Find the intersection point
    do {
        tortoise = nums[tortoise]; // Move tortoise by 1 step
        hare = nums[nums[hare]];    // Move hare by 2 steps
    } while (tortoise != hare);

    // Step 3: Find the entrance to the cycle
    tortoise = nums[0];
    while (tortoise != hare) {
        tortoise = nums[tortoise]; // Move tortoise by 1 step
        hare = nums[hare];         // Move hare by 1 step
    }

    return hare; // or tortoise, both are the same at this point
}

int main() {
    int nums[] = {1, 3, 4, 2, 2};
    int size = sizeof(nums) / sizeof(nums[0]);
    int duplicate = findDuplicateNum(nums, size);
    printf("The duplicate number is: %d\n", duplicate);
    return 0;
}