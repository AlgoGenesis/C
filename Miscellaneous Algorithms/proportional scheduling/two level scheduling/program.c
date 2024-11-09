#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_CPUS 2      // Number of CPUs available
#define NUM_PROCESSES 5 // Number of processes

// Structure for process details
struct Process {
    int pid;         // Process ID
    int burstTime;   // CPU burst time needed
    int assignedCPU; // Assigned CPU ID
};

// Function to perform round-robin scheduling on a CPU
void roundRobinScheduler(struct Process processes[], int numProcesses, int cpuID, int timeQuantum) {
    printf("\nCPU %d scheduling processes:\n", cpuID);

    int timeElapsed = 0;
    int allDone;

    do {
        allDone = 1;
        for (int i = 0; i < numProcesses; i++) {
            // Skip processes not assigned to this CPU
            if (processes[i].assignedCPU != cpuID)
                continue;

            if (processes[i].burstTime > 0) {
                allDone = 0;
                int execTime = (processes[i].burstTime > timeQuantum) ? timeQuantum : processes[i].burstTime;
                
                processes[i].burstTime -= execTime;
                timeElapsed += execTime;

                printf("Process %d ran for %d units on CPU %d. Remaining burst time: %d\n", 
                       processes[i].pid, execTime, cpuID, processes[i].burstTime);

                if (processes[i].burstTime == 0) {
                    printf("Process %d completed on CPU %d at time %d\n", processes[i].pid, cpuID, timeElapsed);
                }
            }
        }
    } while (!allDone);
}

// Function to perform high-level CPU assignment for processes
void twoLevelScheduling(struct Process processes[], int numProcesses, int numCPUs, int timeQuantum) {
    printf("Assigning processes to CPUs...\n");

    // High-level scheduling: assign each process to a CPU in a round-robin fashion
    for (int i = 0; i < numProcesses; i++) {
        processes[i].assignedCPU = i % numCPUs;
        printf("Process %d assigned to CPU %d\n", processes[i].pid, processes[i].assignedCPU);
    }

    // Low-level scheduling: each CPU runs a round-robin scheduler for its assigned processes
    for (int cpuID = 0; cpuID < numCPUs; cpuID++) {
        roundRobinScheduler(processes, numProcesses, cpuID, timeQuantum);
    }
}

int main() {
    struct Process processes[NUM_PROCESSES] = {
        {1, 10, -1}, // Process ID, Burst Time, Assigned CPU (-1 indicates not assigned yet)
        {2, 5, -1},
        {3, 8, -1},
        {4, 6, -1},
        {5, 12, -1}
    };

    int timeQuantum = 3; // Time quantum for round-robin scheduling
    twoLevelScheduling(processes, NUM_PROCESSES, NUM_CPUS, timeQuantum);

    return 0;
}
