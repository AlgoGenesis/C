#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10
#define MAX_QUEUES 3

// Process Structure
struct Process {
    int pid;       // Process ID
    int burstTime; // Burst time
    int remainingTime; // Remaining burst time
    int priority;  // Queue level (0 = high priority, 1 = medium, 2 = low)
    int arrivalTime; // Arrival time for process
};

// Function to simulate Round Robin Scheduling on each queue
void roundRobin(struct Process processes[], int numProcesses, int timeQuantum) {
    int time = 0;
    int completed = 0;

    while (completed < numProcesses) {
        for (int i = 0; i < numProcesses; i++) {
            if (processes[i].remainingTime > 0) {
                printf("At time %d, executing Process %d\n", time, processes[i].pid);
                if (processes[i].remainingTime > timeQuantum) {
                    processes[i].remainingTime -= timeQuantum;
                    time += timeQuantum;
                } else {
                    time += processes[i].remainingTime;
                    processes[i].remainingTime = 0;
                    completed++;
                    printf("Process %d completed at time %d\n", processes[i].pid, time);
                }
            }
        }
    }
}

// Function to simulate MLFQ Scheduling
void mlfqScheduling(struct Process processes[], int numProcesses, int timeQuantums[]) {
    // Each queue (0 = high priority, 1 = medium priority, 2 = low priority)
    struct Process queue[MAX_PROCESSES][MAX_QUEUES];
    int qFront[MAX_QUEUES] = {0}; // Queue front pointers
    int qRear[MAX_QUEUES] = {0};  // Queue rear pointers

    // Sort processes into queues based on their priority
    for (int i = 0; i < numProcesses; i++) {
        queue[processes[i].priority][qRear[processes[i].priority]++] = processes[i];
    }

    // Execute processes in each queue, starting from high priority
    for (int i = 0; i < MAX_QUEUES; i++) {
        printf("\nExecuting Queue %d (Priority %d) with Time Quantum %d\n", i, i, timeQuantums[i]);
        roundRobin(queue[i], qRear[i], timeQuantums[i]);
    }
}

int main() {
    int numProcesses, timeQuantums[MAX_QUEUES];
    struct Process processes[MAX_PROCESSES];

    // Take user input for processes
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    for (int i = 0; i < numProcesses; i++) {
        printf("\nEnter details for Process %d:\n", i + 1);
        processes[i].pid = i + 1;
        printf("Burst Time: ");
        scanf("%d", &processes[i].burstTime);
        printf("Priority (0 = high, 1 = medium, 2 = low): ");
        scanf("%d", &processes[i].priority);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrivalTime);
        processes[i].remainingTime = processes[i].burstTime;  // Initialize remaining time
    }

    // Take user input for time quantum for each queue
    for (int i = 0; i < MAX_QUEUES; i++) {
        printf("\nEnter time quantum for Queue %d (Priority %d): ", i, i);
        scanf("%d", &timeQuantums[i]);
    }

    // Run MLFQ Scheduling
    mlfqScheduling(processes, numProcesses, timeQuantums);

    return 0;
}
