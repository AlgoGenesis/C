#include <stdio.h>

void findIntersection(int arr1[], int arr2[], int n1, int n2) {
    printf("Intersection of the two arrays: ");
    int i = 0;
    while (i < n1) {
        int j = 0;
        while (j < n2) {
            if (arr1[i] == arr2[j]) {
                printf("%d ", arr1[i]);
                break;  // Move to the next element in arr1 after finding a match
            }
            j++;
        }
        i++;
    }
    printf("\n");
}

int main() {
    int n1, n2;

    // Take the size of the first array from the user
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n1);
    int arr1[n1];
    printf("Enter the elements of the first array:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    // Take the size of the second array from the user
    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n2);
    int arr2[n2];
    printf("Enter the elements of the second array:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    // Find and print the intersection of the two arrays
    findIntersection(arr1, arr2, n1, n2);

    return 0;
}
