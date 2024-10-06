#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int distance; // Distance from the town
    int petrol;   // Petrol available at the stop
} Stop;

// Comparison function to sort stops based on distance from the truck (ascending order)
int compare(const void *a, const void *b) {
    Stop *stopA = (Stop *)a;
    Stop *stopB = (Stop *)b;
    return stopA->distance - stopB->distance; // Sort in ascending order
}

// Function to find the minimum number of stops
int min_stops(int n, Stop *arr, int initial_distance, int initial_petrol) {
    // Calculate the distance from the truck
    for (int i = 0; i < n; i++) {
        arr[i].distance = initial_distance - arr[i].distance;
    }

    // Sort stops based on distance from the truck
    qsort(arr, n, sizeof(Stop), compare);

    // Create a dynamic array to simulate a max heap
    int *max = (int *)malloc(n * sizeof(int));
    int max_size = 0;
    int ans = 0;
    int fuel = initial_petrol;

    for (int i = 0; i < n; i++) {
        if (fuel >= initial_distance) {
            break;
        }

        // While the fuel is less than the distance to the next stop
        while (fuel < arr[i].distance) {
            if (max_size == 0) {
                return -1; // Not possible to reach the destination
            }
            // Find the stop with the maximum petrol
            ans++;
            fuel += max[max_size - 1]; // Add petrol from the max heap
            max_size--; // Reduce size of the heap
        }

        // Push the current stop's petrol into the max heap
        max[max_size] = arr[i].petrol;
        max_size++;
        // Maintain max heap property (sort in descending order)
        for (int j = max_size - 1; j > 0 && max[j] > max[j - 1]; j--) {
            int temp = max[j];
            max[j] = max[j - 1];
            max[j - 1] = temp;
        }
    }

    // Final check if we can reach the destination
    while (max_size > 0 && fuel < initial_distance) {
        fuel += max[max_size - 1]; // Add petrol from the max heap
        max_size--; // Reduce size of the heap
        ans++;
    }

    free(max); // Free allocated memory
    return (fuel < initial_distance) ? -1 : ans; // Return result
}

int main() {
    int t;
    printf("Enter t: ");
    scanf("%d", &t);
    while (t--) {
        int n;
        printf("Enter number of stops: ");
        scanf("%d", &n);

        Stop *arr = (Stop *)malloc(n * sizeof(Stop));
        for (int i = 0; i < n; i++) {
            printf("Enter distance from town and petrol: ");
            scanf("%d %d", &arr[i].distance, &arr[i].petrol);
        }

        int initial_distance, initial_petrol;
        printf("Enter initial distance of truck from town and petrol: ");
        scanf("%d %d", &initial_distance, &initial_petrol);

        int result = min_stops(n, arr, initial_distance, initial_petrol);
        if (result == -1) {
            printf("-1\n");
        } else {
            printf("%d\n", result);
        }

        free(arr); // Free allocated memory for stops
    }
    return 0;
}
