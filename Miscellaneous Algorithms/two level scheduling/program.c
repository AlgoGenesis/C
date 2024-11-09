#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_PROCESSES 5

// Structure for process details
struct Process {
    int pid;        // Process ID
    int burstTime;  // Burst time of the process
    int group;      // Group ID (for proportional scheduling)
};

// Function to simulate proportional scheduling
void proportionalScheduling(struct Process processes[], int numProcesses) {
    int timeQuantum = 2; // Time quantum for each round
    int timeElapsed = 0;

    // Keep track of remaining burst times
    int remainingBurst[numProcesses];
    for (int i = 0; i < numProcesses; i++) {
        remainingBurst[i] = processes[i].burstTime;
    }

    printf("Starting Proportional Scheduling...\n");

    // Continue until all processes are done
    while (1) {
        int allDone = 1;

        for (int i = 0; i < numProcesses; i++) {
            if (remainingBurst[i] > 0) {
                allDone = 0;

                // Execute for time quantum or remaining burst time
                int execTime = (remainingBurst[i] > timeQuantum) ? timeQuantum : remainingBurst[i];
                remainingBurst[i] -= execTime;
                timeElapsed += execTime;

                printf("Process %d (Group %d) ran for %d units\n", processes[i].pid, processes[i].group, execTime);
                
                // If process finished
                if (remainingBurst[i] == 0) {
                    printf("Process %d completed at time %d\n", processes[i].pid, timeElapsed);
                }
            }
        }

        // Check if all processes are done
        if (allDone) break;
    }
}

int main() {
    struct Process processes[NUM_PROCESSES] = {
        {1, 8, 1}, // Process ID, Burst Time, Group
        {2, 4, 2},
        {3, 9, 1},
        {4, 5, 2},
        {5, 7, 1}
    };

    proportionalScheduling(processes, NUM_PROCESSES);

    return 0;
}
