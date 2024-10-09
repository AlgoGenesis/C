#include <stdio.h>

void findNextGreaterElementsCircular(int arr[], int n) {
    int nge[n];    // Array to store the result (Next Greater Elements)
    int stack[n];  // Stack to keep track of the indices
    int top = -1;  // Initialize stack pointer as empty (-1)

    // Initialize the result array with -1
    for (int i = 0; i < n; i++) {
        nge[i] = -1;
    }

    // Traverse the array twice to simulate circular behavior
    for (int i = 0; i < 2 * n; i++) {
        // Modulo operation to simulate circular array
        int index = i % n;
        
        // Pop elements from the stack that are less than the current element
        while (top != -1 && arr[stack[top]] < arr[index]) {
            nge[stack[top]] = arr[index];  // Update NGE for the element at stack[top]
            top--;  // Remove the element from the stack
        }
        
        // Only push the index of the first 'n' elements into the stack
        if (i < n) {
            stack[++top] = i;
        }
    }

    // Print the Next Greater Elements for each element
    printf("Next Greater Elements in Circular Array: \n");
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

    // Call function to find next greater elements in circular array
    findNextGreaterElementsCircular(arr, n);

    return 0;
}
