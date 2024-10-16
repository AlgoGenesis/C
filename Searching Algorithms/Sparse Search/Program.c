#include <stdio.h>
#include <string.h>

// Helper function to find the nearest non-empty string
int findNonEmpty(char* arr[], int left, int mid, int right) {
    int l = mid - 1;
    int r = mid + 1;

    // Search left and right for the nearest non-empty string
    while (l >= left || r <= right) {
        if (l >= left && arr[l][0] != '\0') {
            return l;
        }
        if (r <= right && arr[r][0] != '\0') {
            return r;
        }
        l--;
        r++;
    }
    return -1;
}

// Sparse search function
int sparseSearch(char* arr[], int left, int right, char* target) {
    if (left > right) {
        return -1; // Target not found
    }

    int mid = (left + right) / 2;

    // If mid is empty, find the nearest non-empty element
    if (arr[mid][0] == '\0') {
        mid = findNonEmpty(arr, left, mid, right);
        if (mid == -1) {
            return -1; // No non-empty elements left
        }
    }

    // Compare the middle element with the target
    int cmp = strcmp(arr[mid], target);
    if (cmp == 0) {
        return mid; // Target found
    } else if (cmp < 0) {
        return sparseSearch(arr, mid + 1, right, target);
    } else {
        return sparseSearch(arr, left, mid - 1, target);
    }
}

// Main function to test sparse search
int main() {
    char* arr[] = {"", "apple", "", "", "banana", "", "", "cherry", "", "", "date"};
    int size = sizeof(arr) / sizeof(arr[0]);
    char* target = "banana";
    int index = sparseSearch(arr, 0, size - 1, target);

    if (index != -1) {
        printf("'%s' found at index %d\n", target, index);
    } else {
        printf("'%s' not found\n", target);
    }

    return 0;
}
