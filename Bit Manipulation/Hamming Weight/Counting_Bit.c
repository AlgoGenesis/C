
#include <stdio.h>

//  count the number of 1 bits 
int hammingWeight(unsigned int n) {
    int count = 0;
    while (n) {
        count += n & 1; //Increment count if the least significant bit is 1
        n >>= 1;        // Right shift n by 1 to check the next bit
    }
    return count;
}

int main() {
    unsigned int num;
    
    printf("Enter a non-negative integer: ");
    scanf("%u", &num);
    
    int result = hammingWeight(num);
    
    printf("The number of 1 bits in %u is: %d\n", num, result);
    
    return 0;
}
