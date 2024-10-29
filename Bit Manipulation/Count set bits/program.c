#include <stdio.h>

int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        n = n & (n - 1);  // Removes the rightmost set bit
        count++;
    }
    return count;
}

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    int result = countSetBits(num);
    printf("Number of set bits in %d is %d\n", num, result);

    return 0;
}
