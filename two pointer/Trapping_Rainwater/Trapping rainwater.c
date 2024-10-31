#include <stdio.h>

int maxWater(int arr[], int n) {
    int left = 1;
    int right = n - 2;
    int lMax = arr[0];
    int rMax = arr[n - 1];
    int res = 0;

    while (left <= right) {
        if (rMax <= lMax) {
            res += (rMax - arr[right] > 0) ? (rMax - arr[right]) : 0;
            rMax = (rMax > arr[right]) ? rMax : arr[right];
            right--;
        } else {
            res += (lMax - arr[left] > 0) ? (lMax - arr[left]) : 0;
            lMax = (lMax > arr[left]) ? lMax : arr[left];
            left++;
        }
    }
    return res;
}

int main() {
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Maximum water that can be trapped: %d\n", maxWater(arr, n));
    return 0;
}