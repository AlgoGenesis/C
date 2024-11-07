#include <stdio.h>

int findMissingNumberXOR(int nums[], int n) {
    int xorAll = 0;
    int xorArray = 0;

    // XOR all numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        xorAll ^= i;
    }

    // XOR all elements in the array
    for (int i = 0; i < n - 1; i++) {
        xorArray ^= nums[i];
    }

    // XOR of xorAll and xorArray gives the missing number
    return xorAll ^ xorArray;
}

int main() {
    int nums[] = {1, 2, 4, 5};  
    int n = 5;  

    int missingNumber = findMissingNumberXOR(nums, n);
    printf("Missing number is: %d\n", missingNumber);

    return 0;
}
