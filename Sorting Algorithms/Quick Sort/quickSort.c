#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int A[], int l, int h) {
    int pivot = A[l];
    int i = l + 1; // Start from the next element after pivot
    int j = h;

    do {
        while (i <= h && A[i] <= pivot) i++; // Increment i while A[i] <= pivot
        while (A[j] > pivot) j--; // Decrement j while A[j] > pivot

        if (i < j) {
            swap(&A[i], &A[j]); // Swap A[i] and A[j]
        }
    } while (i < j);

    swap(&A[l], &A[j]); // Swap pivot with A[j]
    return j; // Return the index of the pivot
}

void QuickSort(int A[], int l, int h) {
    if (l < h) {
        int j = partition(A, l, h);
        QuickSort(A, l, j - 1); // Sort the left part
        QuickSort(A, j + 1, h); // Sort the right part
    }
}

int main() {
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int n = sizeof(A) / sizeof(A[0]); // Determine number of elements
    int i;

    QuickSort(A, 0, n - 1); // Call QuickSort with correct bounds

    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
