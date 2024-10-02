#include <stdio.h>
#include <stdlib.h>

void merge(int A[], int l, int mid, int h) {
    int i = l, j = mid + 1, k = 0;
    int *B = (int *)malloc((h - l + 1) * sizeof(int)); // Dynamic allocation for B

    while (i <= mid && j <= h) {
        if (A[i] < A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }

    // Copy remaining elements from left half, if any
    while (i <= mid) {
        B[k++] = A[i++];
    }
    // Copy remaining elements from right half, if any
    while (j <= h) {
        B[k++] = A[j++];
    }

    // Copy merged elements back to the original array
    for (i = l; i <= h; i++) {
        A[i] = B[i - l];
    }

    free(B); // Free the dynamically allocated memory
}

void IMergeSort(int A[], int n) {
    int p, l, h, mid, i;
    for (p = 2; p <= n; p *= 2) {
        for (i = 0; i + p - 1 < n; i += p) {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge(A, l, mid, h);
        }
        if (n - i > p / 2) { // Handle leftover elements
            l = i;
            h = n - 1;
            mid = (l + h) / 2;
            merge(A, l, mid, h);
        }
    }
}

int main() {
    int A[] = {11, 5, 14, 2, 6, 3, 1};
    int n = sizeof(A) / sizeof(A[0]); // Dynamically calculate the size of A
    int i;

    IMergeSort(A, n);
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
