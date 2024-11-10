#include <stdio.h>

#define NUM_PROCESSES 3

typedef struct {
    int id;
    int weight;
    int remainingTime;
    float finishTime;
} Process;

void weightedFairQueueing(Process processes[], int numProcesses, int quantum) {
    float currentTime = 0;
    int completed = 0;

    // Calculate the service rate for each process based on its weight
    while (completed < numProcesses) {
        for (int i = 0; i < numProcesses; i++) {
            if (processes[i].remainingTime > 0) {
                // Calculate effective time quantum for the process
                int effectiveQuantum = quantum * processes[i].weight;

                // Process execution
                if (processes[i].remainingTime > effectiveQuantum) {
                    processes[i].remainingTime -= effectiveQuantum;
                    currentTime += effectiveQuantum;
                } else {
                    currentTime += processes[i].remainingTime;
                    processes[i].finishTime = currentTime;
                    processes[i].remainingTime = 0;
                    completed++;
                }

                printf("Process %d executed for %d units. Remaining time: %d\n",
                       processes[i].id, effectiveQuantum, processes[i].remainingTime);
            }
        }
    }
}

int main() {
    Process processes[NUM_PROCESSES] = {
        {1, 1, 10, 0.0},  // Process ID 1, Weight 1, Burst Time 10
        {2, 3, 15, 0.0},  // Process ID 2, Weight 3, Burst Time 15
        {3, 2, 20, 0.0}   // Process ID 3, Weight 2, Burst Time 20
    };

    int quantum = 2;

    printf("Starting Weighted Fair Queueing (WFQ) scheduling:\n");
    weightedFairQueueing(processes, NUM_PROCESSES, quantum);

    printf("\nProcess completion times:\n");
    for (int i = 0; i < NUM_PROCESSES; i++) {
        printf("Process %d finished at time %.2f\n", processes[i].id, processes[i].finishTime);
    }

    return 0;
}
