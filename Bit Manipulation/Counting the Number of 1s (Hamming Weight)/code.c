#include <stdio.h>

// Function to count the number of 1s (Hamming weight) in an integer's binary representation
int hammingWeight(unsigned int n) {
    int count = 0; // Initialize count of 1s to 0

    // Loop until n becomes 0
    while (n) {
        count += n & 1; // Increment count if the least significant bit (LSB) is 1
        n >>= 1; // Right shift n by one bit to process the next bit
    }

    return count; // Return the total count of 1s
}

// Main function to test the hammingWeight function
int main() {
    unsigned int num = 29; // Example number (in binary: 11101)
    printf("Number of 1s in the binary representation of %u is: %d\n", num, hammingWeight(num));

    return 0;
}
