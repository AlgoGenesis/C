#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

// Comparison function to sort intervals based on their ending time
int compare(const void *a, const void *b) {
    Interval *intervalA = (Interval *)a;
    Interval *intervalB = (Interval *)b;
    return intervalA->end - intervalB->end;
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    
    // Allocate memory for intervals
    Interval *arr = (Interval *)malloc(n * sizeof(Interval));
    for (int i = 0; i < n; i++) {
        printf("Enter start and end time for interval %d: ", i + 1);
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    // Sort intervals based on their ending time
    qsort(arr, n, sizeof(Interval), compare);

    int take = 1;
    int end = arr[0].end;
    for (int i = 1; i < n; i++) {
        if (arr[i].start >= end) { // If starting time of next interval >= end time of previous interval
            take++;                // Take this interval
            end = arr[i].end;      // Update the end time
        }
    }

    printf("Maximum number of non-overlapping intervals: %d\n", take);
    
    // Free allocated memory
    free(arr);
    return 0;
}
