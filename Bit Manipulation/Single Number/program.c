#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
    int num = 0;
    for (int i = 0; i < numsSize; i++) {
        num ^= nums[i];
    }
    return num;
}

int main() {
    int n;
    
    // Input the size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int nums[n];
    
    // Input the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Call the function and print the result
    int result = singleNumber(nums, n);
    printf("The single number is: %d\n", result);

    return 0;
} 
