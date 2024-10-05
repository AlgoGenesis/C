#include <stdio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
      
        // Assume the current position holds
        // the minimum element
        int min = i;
        
        // Iterate through the unsorted portion
        // to find the actual minimum
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
              
                // Update min_idx if a smaller element is found
                min = j;
            }
        }
        
        // If a new minimum is found,
        // swap it with the element at index i
        if (min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of array : ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter the elements of array : ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    printf("Original array: ");
    print(arr, n);
    
    selectionSort(arr, n);
    
    printf("Sorted array: ");
    print(arr, n);
    
    return 0;
}