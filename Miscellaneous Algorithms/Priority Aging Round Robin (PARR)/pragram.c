#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10
#define TIME_QUANTUM 10

// Structure to represent a process
typedef struct {
    int id;             // Process ID
    int priority;       // Process priority
    int remaining_time; // Remaining time to complete execution
} Process;

// Function to apply priority aging
void priorityAging(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        if (processes[i].remaining_time > 0) {
            processes[i].priority++; // Increase priority for waiting processes
        }
    }
}

// Function to perform Round Robin scheduling with priority aging
void roundRobin(Process processes[], int n) {
    int completed = 0;

    // Execute until all processes are completed
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                // Execute the process for TIME_QUANTUM or remaining time
                printf("Executing process %d with priority %d\n", processes[i].id, processes[i].priority);
                
                int execution_time = (processes[i].remaining_time <= TIME_QUANTUM) ? processes[i].remaining_time : TIME_QUANTUM;
                processes[i].remaining_time -= execution_time;

                // Check if the process is completed
                if (processes[i].remaining_time == 0) {
                    printf("Process %d completed.\n", processes[i].id);
                    completed++;
                }
            }
        }

        // Apply priority aging after each round
        priorityAging(processes, n);
    }
}

// Main function to execute the PARR algorithm
int main() {
    // Define processes with their IDs, initial priorities, and remaining times
    Process processes[MAX_PROCESSES] = {
        {1, 1, 50},
        {2, 2, 30},
        {3, 3, 40},
        {4, 1, 20}
    };

    int n = 4;  // Number of processes

    // Execute Round Robin scheduling with priority aging
    roundRobin(processes, n);

    return 0;
}
