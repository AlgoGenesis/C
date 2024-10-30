##include <stdio.h>
#include <stdlib.h>

// Structure to represent an interval
typedef struct {
    int start;
    int end;
} Interval;

// Comparison function to sort intervals based on their start time
int compare(const void *a, const void *b) {
    Interval *intervalA = (Interval *)a;
    Interval *intervalB = (Interval *)b;
    return intervalA->start - intervalB->start;
}

// Function to merge overlapping intervals
Interval* mergeIntervals(Interval* intervals, int intervalsSize, int* returnSize) {
    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    // Sort the intervals based on the start time
    qsort(intervals, intervalsSize, sizeof(Interval), compare);

    // Allocate memory for the merged intervals
    Interval* merged = (Interval*)malloc(intervalsSize * sizeof(Interval));
    int mergedIndex = 0;

    // Start with the first interval
    merged[mergedIndex++] = intervals[0];

    for (int i = 1; i < intervalsSize; i++) {
        // If the current interval overlaps with the last merged interval
        if (intervals[i].start <= merged[mergedIndex - 1].end) {
            // Merge the intervals by updating the end time
            if (intervals[i].end > merged[mergedIndex - 1].end) {
                merged[mergedIndex - 1].end = intervals[i].end;
            }
        } else {
            // No overlap, add the current interval to merged
            merged[mergedIndex++] = intervals[i];
        }
    }

    *returnSize = mergedIndex;
    return merged;
}

// Helper function to print intervals
void printIntervals(Interval* intervals, int size) {
    for (int i = 0; i < size; i++) {
        printf("[%d, %d] ", intervals[i].start, intervals[i].end);
    }
    printf("\n");
}

// Main function to test the mergeIntervals function
int main() {
    Interval intervals[] = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    int intervalsSize = sizeof(intervals) / sizeof(intervals[0]);
    int returnSize;

    Interval* mergedIntervals = mergeIntervals(intervals, intervalsSize, &returnSize);
    printf("Merged Intervals: ");
    printIntervals(mergedIntervals, returnSize);

    // Free allocated memory
    free(mergedIntervals);
    return 0;
}