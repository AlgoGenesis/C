#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100

// Structure to store each disk request with track number and status
typedef struct {
    int track;
    int is_serviced;
} DiskRequest;

// Function to calculate absolute difference
int abs_diff(int a, int b) {
    return a > b ? a - b : b - a;
}

// Function to reorder requests dynamically based on current disk position
void reorder_requests(DiskRequest requests[], int num_requests, int current_head) {
    for (int i = 0; i < num_requests - 1; i++) {
        for (int j = i + 1; j < num_requests; j++) {
            // Sort requests based on proximity to current head position
            if (abs_diff(requests[i].track, current_head) > abs_diff(requests[j].track, current_head)) {
                DiskRequest temp = requests[i];
                requests[i] = requests[j];
                requests[j] = temp;
            }
        }
    }
}

// Adaptive Disk Reordering (ADR) algorithm implementation
void adaptive_disk_reordering(DiskRequest requests[], int num_requests, int initial_head) {
    int current_head = initial_head;
    int total_seek_time = 0;

    printf("Seek Sequence: %d", current_head);

    for (int i = 0; i < num_requests; i++) {
        reorder_requests(requests, num_requests, current_head);

        // Find the nearest unserviced request
        for (int j = 0; j < num_requests; j++) {
            if (!requests[j].is_serviced) {
                int seek_time = abs_diff(current_head, requests[j].track);
                total_seek_time += seek_time;
                current_head = requests[j].track;
                requests[j].is_serviced = 1;
                
                printf(" -> %d", current_head);
                break;
            }
        }
    }

    printf("\nTotal Seek Time: %d\n", total_seek_time);
    printf("Average Seek Time: %.2f\n", (float)total_seek_time / num_requests);
}

int main() {
    int num_requests, initial_head;

    printf("Enter number of disk requests: ");
    scanf("%d", &num_requests);

    DiskRequest requests[MAX_REQUESTS];
    printf("Enter track numbers for the requests:\n");
    for (int i = 0; i < num_requests; i++) {
        printf("Request %d: ", i + 1);
        scanf("%d", &requests[i].track);
        requests[i].is_serviced = 0;
    }

    printf("Enter initial head position: ");
    scanf("%d", &initial_head);

    adaptive_disk_reordering(requests, num_requests, initial_head);

    return 0;
}
