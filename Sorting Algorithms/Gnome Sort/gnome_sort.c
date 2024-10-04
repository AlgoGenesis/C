#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void gnomeSort(int arr[], int n) {
    int index = 0;

    while (index < n) {
        if (index == 0)
            index++;
        if (arr[index] >= arr[index - 1])
            index++;
        else {
            swap(&arr[index], &arr[index - 1]);
            index--;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {34, 2, 10, -9, 5, 23, 0, 7, -5, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    gnomeSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}