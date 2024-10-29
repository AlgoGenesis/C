#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// Function to check if the given output is a stack permutation of input
bool isStackPermutation(int input[], int output[], int n) {
    int stack[MAX];
    int top = -1;
    int j = 0;

    for (int i = 0; i < n; i++) {
        // Push the current element of the input queue to stack
        stack[++top] = input[i];

        // Check if the top of stack matches the output queue
        while (top >= 0 && stack[top] == output[j]) {
            top--; 
            j++;  
        }
    }

    // If j has reached n, then output is a valid permutation
    return (j == n);
}

int main() {
    int input[] = {1, 2, 3};
    int output[] = {2, 1, 3};
    int n = sizeof(input) / sizeof(input[0]);

    if (isStackPermutation(input, output, n))
        printf("Yes, it is a stack permutation\n");
    else
        printf("No, it is not a stack permutation\n");

    return 0;
}
