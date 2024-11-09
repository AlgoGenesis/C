#include <stdio.h>

void flip(int arr[], int i) {
    int temp, start = 0;
    while (start < i) {
        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        start++;
        i--;
    }
}

int findMax(int arr[], int n) {
    int maxIdx = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxIdx])
            maxIdx = i;
    }
    return maxIdx;
}

void pancakeSort(int arr[], int n) {
    for (int curr_size = n; curr_size > 1; curr_size--) {
        int maxIdx = findMax(arr, curr_size);
        if (maxIdx != curr_size - 1) {
            flip(arr, maxIdx);
            flip(arr, curr_size - 1);
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {3, 6, 2, 7, 4, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    pancakeSort(arr, n);
    printArray(arr, n);
    return 0;
}
