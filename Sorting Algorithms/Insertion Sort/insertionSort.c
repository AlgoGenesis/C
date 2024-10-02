#include <stdio.h>

void Print(int A[], int n, const char* label) {
    printf("%s: [", label);
    for (int i = 0; i < n; i++) {
        printf("%d", A[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void InsertionSort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int main() {
    int A[] = {19, 17, 15, 13, 11, 9, 7, 5, 3, 1};
    int n = sizeof(A) / sizeof(A[0]);

    Print(A, n, "       A");

    InsertionSort(A, n);
    Print(A, n, "Sorted A");

    return 0;
}
