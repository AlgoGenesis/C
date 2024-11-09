#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_REQUESTS 100
#define DISK_SIZE 200  // Represents the number of tracks on the disk
#define LOW_POWER_THRESHOLD 20  // Threshold for "low-power" mode

// Function to sort requests
void sort_requests(int requests[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (requests[i] > requests[j]) {
                int temp = requests[i];
                requests[i] = requests[j];
                requests[j] = temp;
            }
        }
    }
}

int power_aware_scan(int requests[], int n, int head, int direction) {
    int seek_time = 0;
    int total_seek_time = 0;
    int distance;
    int current_head = head;
    bool low_power_mode = false;

    // Sort requests for efficient scan-based scheduling
    sort_requests(requests, n);

    // Separate requests to the left and right of the head
    int left[MAX_REQUESTS], right[MAX_REQUESTS];
    int left_count = 0, right_count = 0;

    for (int i = 0; i < n; i++) {
        if (requests[i] < head) {
            left[left_count++] = requests[i];
        } else {
            right[right_count++] = requests[i];
        }
    }

    // Implement the SCAN algorithm with power-awareness
    if (direction == 1) {  // Moving towards higher tracks
        for (int i = 0; i < right_count; i++) {
            distance = abs(current_head - right[i]);
            if (distance > LOW_POWER_THRESHOLD) {
                printf("Entering low-power mode to save energy.\n");
                low_power_mode = true;
            } else {
                printf("Servicing request at track %d\n", right[i]);
                seek_time = distance;
                current_head = right[i];
                total_seek_time += seek_time;
                low_power_mode = false;
            }
        }
        // Reverse direction after reaching the highest track
        for (int i = left_count - 1; i >= 0; i--) {
            distance = abs(current_head - left[i]);
            if (distance > LOW_POWER_THRESHOLD) {
                printf("Entering low-power mode to save energy.\n");
                low_power_mode = true;
            } else {
                printf("Servicing request at track %d\n", left[i]);
                seek_time = distance;
                current_head = left[i];
                total_seek_time += seek_time;
                low_power_mode = false;
            }
        }
    } else {  // Moving towards lower tracks
        for (int i = left_count - 1; i >= 0; i--) {
            distance = abs(current_head - left[i]);
            if (distance > LOW_POWER_THRESHOLD) {
                printf("Entering low-power mode to save energy.\n");
                low_power_mode = true;
            } else {
                printf("Servicing request at track %d\n", left[i]);
                seek_time = distance;
                current_head = left[i];
                total_seek_time += seek_time;
                low_power_mode = false;
            }
        }
        // Reverse direction after reaching the lowest track
        for (int i = 0; i < right_count; i++) {
            distance = abs(current_head - right[i]);
            if (distance > LOW_POWER_THRESHOLD) {
                printf("Entering low-power mode to save energy.\n");
                low_power_mode = true;
            } else {
                printf("Servicing request at track %d\n", right[i]);
                seek_time = distance;
                current_head = right[i];
                total_seek_time += seek_time;
                low_power_mode = false;
            }
        }
    }

    return total_seek_time;
}

int main() {
    int n, head, direction;
    int requests[MAX_REQUESTS];

    // Get input for requests
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    printf("Enter the disk requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }
    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);
    printf("Enter the initial direction (1 for high, 0 for low): ");
    scanf("%d", &direction);

    // Run the power-aware scan algorithm
    int total_seek_time = power_aware_scan(requests, n, head, direction);

    printf("Total seek time: %d\n", total_seek_time);
    printf("Average seek time: %.2f\n", (float)total_seek_time / n);

    return 0;
}
