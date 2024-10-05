#include <stdio.h>

// Function to find the majority element
int findCandidate(int arr[], int size) {
    int majorityIndex = 0, count = 1;
    for (int i = 1; i < size; i++) {
        if (arr[majorityIndex] == arr[i])
            count++;
        else
            count--;
        if (count == 0) {
            majorityIndex = i;
            count = 1;
        }
    }
    return arr[majorityIndex];
}

// Function to check if the candidate is actually a majority element
int isMajority(int arr[], int size, int candidate) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == candidate)
            count++;
    }
    if (count > size/2)
        return 1;
    else
        return 0;
}

// Main function to find and print the majority element
void printMajorityElement(int arr[], int size) {
    int candidate = findCandidate(arr, size);
    
    if (isMajority(arr, size, candidate))
        printf("Majority element: %d\n", candidate);
    else
        printf("No majority element found\n");
}

int main() {
    int arr[] = {2, 2, 1, 1, 2, 2, 3, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printMajorityElement(arr, size);
    
    return 0;
}
