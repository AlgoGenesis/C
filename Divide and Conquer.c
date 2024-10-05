#include <stdio.h>

void merger(int array1[], int len1, int array2[], int len2, int result[]) {
    int i = 0, j = 0, k = 0;
    while (i < len1 && j < len2) {
        if (array1[i] < array2[j]) {
            result[k++] = array1[i++];
        } else {
            result[k++] = array2[j++];
        }
    }
    while (i < len1) {
        result[k++] = array1[i++];
    }
    while (j < len2) {
        result[k++] = array2[j++];
    }
}

void main() {
    int arr1[] = {2, 3, 6, 7, 9};
    int arr2[] = {1, 4, 8, 10};
    int k = 5;

    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);
    int merged[n + m];
    merger(arr1, n, arr2, m, merged);
    printf("%d", merged[k-1]);
}
