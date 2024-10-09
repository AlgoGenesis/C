#include <stdio.h>

void findNextGreaterElements(int arr[], int n) {
    int stack[n];  // Stack to keep track of the indices
    int top = -1;  // Initialize stack pointer as empty (-1)
    int nge[n];    // Array to store the result (Next Greater Elements)
    
    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Pop elements from the stack that are less than or equal to arr[i]
        while (top != -1 && arr[stack[top]] <= arr[i]) {
            top--;
        }
        
        // If the stack is empty, no greater element to the right
        if (top == -1) {
            nge[i] = -1;
        } else {
            nge[i] = arr[stack[top]];
        }
        
        // Push the current element's index onto the stack
        stack[++top] = i;
    }
    
    // Print the Next Greater Elements for each element
    printf("Next Greater Elements: \n");
    for (int i = 0; i < n; i++) {
        printf("%d -> %d\n", arr[i], nge[i]);
    }
}

int main() {
    int n;

    // Get the size of the array from the user
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];  // Declare array of size n

    // Get the elements of the array from the user
    printf("Enter the elements of the array: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call function to find next greater elements
    findNextGreaterElements(arr, n);

    return 0;
}
