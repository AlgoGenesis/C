// C program to Count Inversions in an array 
// using nested loop

#include <stdio.h>

// Function to count inversions in the array
int inversionCount(int arr[], int n) {
    int invCount = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            
            // If the current element is greater than the next,
            // increment the count
            if (arr[i] > arr[j])
                invCount++;
        }
    }
    return invCount;
}

int main() {
    int arr[] = {4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    printf("%d\n", inversionCount(arr, n));
    return 0;
}