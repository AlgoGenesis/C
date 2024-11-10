#include <stdio.h>
#include <stdlib.h>

void scanAlgorithm(int requests[], int n, int head, int direction, int disk_size) {
    int seek_time = 0;
    int distance, current_track;
    int left[n], right[n];
    int l = 0, r = 0;

    // Separate requests into two arrays based on their position relative to the head
    for (int i = 0; i < n; i++) {
        if (requests[i] < head) {
            left[l++] = requests[i];
        } else {
            right[r++] = requests[i];
        }
    }

    // Sort left and right arrays
    qsort(left, l, sizeof(int), (int (*)(const void*, const void*))compare);
    qsort(right, r, sizeof(int), (int (*)(const void*, const void*))compare);

    // SCAN movement based on the initial direction
    printf("Seek Sequence: ");
    if (direction == 1) { // Move toward the larger tracks (right)
        for (int i = 0; i < r; i++) {
            current_track = right[i];
            printf("%d ", current_track);
            distance = abs(current_track - head);
            seek_time += distance;
            head = current_track;
        }

        // Move to the end of the disk, if needed
        if (head != disk_size - 1) {
            seek_time += abs(disk_size - 1 - head);
            head = disk_size - 1;
        }

        // Move back in the opposite direction (left)
        for (int i = l - 1; i >= 0; i--) {
            current_track = left[i];
            printf("%d ", current_track);
            distance = abs(current_track - head);
            seek_time += distance;
            head = current_track;
        }
    } else { // Move toward the smaller tracks (left)
        for (int i = l - 1; i >= 0; i--) {
            current_track = left[i];
            printf("%d ", current_track);
            distance = abs(current_track - head);
            seek_time += distance;
            head = current_track;
        }

        // Move to the start of the disk, if needed
        if (head != 0) {
            seek_time += head;
            head = 0;
        }

        // Move back in the opposite direction (right)
        for (int i = 0; i < r; i++) {
            current_track = right[i];
            printf("%d ", current_track);
            distance = abs(current_track - head);
            seek_time += distance;
            head = current_track;
        }
    }

    printf("\nTotal Seek Time: %d\n", seek_time);
    printf("Average Seek Time: %.2f\n", (float)seek_time / n);
}

// Comparison function for qsort
int compare(const int *a, const int *b) {
    return *a - *b;
}

int main() {
    int n, head, direction, disk_size;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int requests[n];
    printf("Enter the requests:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter the disk size: ");
    scanf("%d", &disk_size);

    printf("Enter the initial direction (1 for high, 0 for low): ");
    scanf("%d", &direction);

    scanAlgorithm(requests, n, head, direction, disk_size);

    return 0;
}
