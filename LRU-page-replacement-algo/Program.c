#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 10

int findLRU(int time[], int n) {
    int minimum = time[0], pos = 0;
    for (int i = 1; i < n; ++i) {
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

void lruPageReplacement(int pages[], int n, int frames) {
    int pageFaults = 0;
    int frame[MAX_FRAMES], time[MAX_FRAMES];
    int isPageFault = 0;

    for (int i = 0; i < frames; i++) {
        frame[i] = -1; // Initialize frames as empty
    }

    for (int i = 0; i < n; i++) {
        isPageFault = 0;
        for (int j = 0; j < frames; j++) {
            // Check if the page is already in a frame
            if (frame[j] == pages[i]) {
                isPageFault = 1;
                time[j] = i; // Update the time of access
                break;
            }
        }

        // Page fault occurs
        if (!isPageFault) {
            int lruIndex = findLRU(time, frames);
            frame[lruIndex] = pages[i]; // Replace the LRU page
            time[lruIndex] = i; // Update the time of the new page
            pageFaults++;
        }

        // Display current state of frames
        printf("Current Frames: ");
        for (int j = 0; j < frames; j++) {
            printf("%d ", frame[j]);
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 0, 7, 0, 1};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frames = 3; // Number of frames

    lruPageReplacement(pages, n, frames);
    return 0;
}
