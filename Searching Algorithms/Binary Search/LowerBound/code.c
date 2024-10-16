#include <stdio.h>

// Function to find the lower bound of 'target' in the sorted array 'arr'
int lowerBound(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    int ans = n; // Initialize 'ans' as 'n' (out of bounds initially)

    // Binary search loop
    while (low <= high) {
        // Calculate mid-point
        int mid = (low + high) / 2;

        // Check if mid element is greater than or equal to 'target'
        if (arr[mid] >= target) {
            // 'arr[mid]' is a potential answer, so store 'mid' in 'ans'
            ans = mid;

            // Try to find a smaller index on the left side
            high = mid - 1;
        } 
        else {
            // If 'arr[mid]' is less than 'target', move to the right side
            low = mid + 1;
        }
    }

    // Return the index of the first element greater than or equal to 'target'
    return ans;
}

int main() {
    // Example sorted array
    int arr[] = {2, 4, 6, 9, 13, 17}; // The array is sorted
    int n = 6; // Number of elements in the array
    int target = 10; // Value for which we are finding the lower bound
    
    // Find the lower bound (index of the first element >= 'target')
    int ind = lowerBound(arr, n, target);
    
    // Output the result
    printf("The lower bound is the index: %d\n", ind);
    
    return 0;
}
