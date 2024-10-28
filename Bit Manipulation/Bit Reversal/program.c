#include <stdio.h>

// Function to reverse the bits of a given integer
unsigned int reverseBits(unsigned int n) {
    unsigned int reversed = 0; // Variable to store the reversed bits
    unsigned int bitCount = sizeof(n) * 8; // Total number of bits in the integer

    // Iterate through each bit of the integer
    for (unsigned int i = 0; i < bitCount; i++) {
        // Check if the i-th bit in n is set
        if ((n & (1 << i))) {
            // Set the corresponding bit in the reversed variable
            reversed |= 1 << ((bitCount - 1) - i);
        }
    }
    return reversed;
}

// Function to test the reverseBits function
void testReverseBits() {
    unsigned int num; // Variable to store the input number

    // Prompt the user to enter a number
    printf("Enter a number: ");
    scanf("%u", &num); // Read the number from standard input

    // Call the reverseBits function to reverse the bits of the number
    unsigned int reversedNum = reverseBits(num);

    // Display the original and reversed numbers
    printf("Original number: %u\n", num);
    printf("Reversed number: %u\n", reversedNum);
}

// Main function
int main() {
    // Call the test function to demonstrate the bit reversal
    testReverseBits();

    return 0; // Successful completion of the program
}
