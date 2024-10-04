#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void cycleSort(int arr[], int n) {
    for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++) {
        int item = arr[cycle_start];
        int pos = cycle_start;

        for (int i = cycle_start + 1; i < n; i++)
            if (arr[i] < item)
                pos++;

        if (pos == cycle_start)
            continue;

        while (item == arr[pos])
            pos++;

        if (pos != cycle_start) {
            swap(&item, &arr[pos]);
        }

        while (pos != cycle_start) {
            pos = cycle_start;

            for (int i = cycle_start + 1; i < n; i++)
                if (arr[i] < item)
                    pos++;

            while (item == arr[pos])
                pos++;

            if (item != arr[pos]) {
                swap(&item, &arr[pos]);
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
    int arr[] = {1, 8, 3, 9, 10, 10, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    cycleSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}