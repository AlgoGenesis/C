#include <stdio.h>

// Function to swap two integers using XOR bitwise operation
void swap(int *a, int *b) {
    // Only swap if the two pointers do not point to the same variable
    if (a != b) { 
        // Perform the XOR swap
        *a = *a ^ *b; // Step 1: a becomes a XOR b
        *b = *a ^ *b; // Step 2: b becomes the original value of a
        *a = *a ^ *b; // Step 3: a becomes the original value of b
    } 
}

int main() {
    int x, y; // Declare two integers

    // Prompt the user to enter two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y); // Read the numbers from standard input

    // Display the values before swapping
    printf("Before swapping: x = %d, y = %d\n", x, y);
    
    // Call the swap function to swap the values of x and y
    swap(&x, &y);

    // Display the values after swapping
    printf("After swapping: x = %d, y = %d\n", x, y);
    
    return 0; // Successful completion of the program
}


