#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to reverse the array from start to end index
void reverse(int arr[], int start, int end) {
    while (start < end) {
        swap(&arr[start], &arr[end]);
        start++;
        end--;
    }
}

// Function to find the next lexicographical permutation
void nextPermutation(int arr[], int n) {
    int i = n - 2;

    '''rightmost pair where arr[i] < arr[i + 1]'''
    while (i >= 0 && arr[i] >= arr[i + 1]) {
        i--;
    }

    '''If such an index is found, find the smallest element to the right of arr[i] that is greater than arr[i]'''
    if (i >= 0) {
        int j = n - 1;
        while (arr[j] <= arr[i]) {
            j--;
        }
        // Swap arr[i] and arr[j]
        swap(&arr[i], &arr[j]);
    }

    '''Reverse the elements from i+1 to end of the array'''
    reverse(arr, i + 1, n - 1);
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
  
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    nextPermutation(arr, n);

    printf("Next permutation:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
