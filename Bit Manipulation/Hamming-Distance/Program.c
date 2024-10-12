#include <stdio.h>

// Function to calculate the Hamming distance between two integers
int hammingDistance(int x, int y) {
    // XOR the two numbers to find positions where bits differ
    int xor = x ^ y;
    
    // Count the number of 1's in the XOR result (which gives the Hamming distance)
    int distance = 0;
    while (xor > 0) {
        // Increment the count if the least significant bit is 1
        distance += (xor & 1);
        
        // Right shift the XOR result to check the next bit
        xor >>= 1;
    }
    
    return distance;
}

int main() {
    int x, y;
    
    // Input two integers
    printf("Enter two integers:\n");
    scanf("%d %d", &x, &y);
    
    // Calculate and print the Hamming distance
    printf("Hamming Distance: %d\n", hammingDistance(x, y));
    
    return 0;
}
