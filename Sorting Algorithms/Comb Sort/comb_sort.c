#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int getNextGap(int gap) {
    gap = (gap * 10) / 13;
    if (gap < 1)
        return 1;
    return gap;
}

void combSort(int arr[], int n) {
    int gap = n;
    bool swapped = true;

    while (gap != 1 || swapped == true) {
        gap = getNextGap(gap);
        swapped = false;

        for (int i = 0; i < n - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(&arr[i], &arr[i + gap]);
                swapped = true;
            }
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {8, 4, 1, 56, 3, -44, 23, -6, 28, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    combSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}