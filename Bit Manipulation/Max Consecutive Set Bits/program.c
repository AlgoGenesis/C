#include <stdio.h>

int maxConsecutiveOnes(int n) {
    int maxCount = 0, currentCount = 0;

    while (n > 0) {
        // Check if the last bit is 1
        if (n & 1) {
            currentCount++;
            if (currentCount > maxCount)
                maxCount = currentCount;
        } else {
            currentCount = 0;
        }
        // Right shift the bits of n by 1 to check the next bit
        n >>= 1;
    }
    return maxCount;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int result = maxConsecutiveOnes(n);
    printf("Maximum consecutive set bits: %d\n", result);

    return 0;
}
