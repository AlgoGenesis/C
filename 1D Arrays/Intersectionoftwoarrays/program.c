#include <stdio.h>
#include <stdbool.h>

#define MAX 10000  // Assume maximum array values are within this range

void findIntersection(int arr1[], int arr2[], int n1, int n2) {
    bool hash[MAX] = { false };
    printf("Intersection of the two arrays (unique elements only): ");

    // Mark elements in the first array in the hash table
    for (int i = 0; i < n1; i++) {
        hash[arr1[i]] = true;
    }

    // Traverse the second array and print elements if they are in hash and not printed before
    bool found = false;
    for (int j = 0; j < n2; j++) {
        if (hash[arr2[j]]) {
            printf("%d ", arr2[j]);
            hash[arr2[j]] = false;  // Mark as printed to avoid duplicates
            found = true;
        }
    }

    if (!found) {
        printf("No common elements found.");
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
