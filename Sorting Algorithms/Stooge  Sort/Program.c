#include <stdio.h>

void stooge_sort(int arr[], int l, int h) {
    if (l >= h) {
        return;
    }

    // If first element is greater than the last, swap them
    if (arr[l] > arr[h]) {
        int temp = arr[l];
        arr[l] = arr[h];
        arr[h] = temp;
    }

    // If there are more than 2 elements in the array
    if (h - l + 1 > 2) {
        int t = (h - l + 1) / 3;
        stooge_sort(arr, l, h - t);   // Sort the first 2/3
        stooge_sort(arr, l + t, h);   // Sort the last 2/3
        stooge_sort(arr, l, h - t);   // Again sort the first 2/3
    }
}

int main() {
    int arr[] = {2, 4, 5, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    stooge_sort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
