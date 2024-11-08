#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

// Define a structure for processes
typedef struct {
    int id;
    int priority;      // Lower number means higher priority
    int burstTime;
    int waitingTime;
    int turnaroundTime;
} Process;

// Function to perform Ripple Effect Scheduling (RES)
void rippleEffectScheduling(Process processes[], int n) {
    // Sort processes by priority (ascending order for higher priority first)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].priority > processes[j].priority) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Initialize waiting time for the first process
    processes[0].waitingTime = 0;

    // Calculate waiting time for each process
    for (int i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;

        // Ripple effect: give small wait reduction to next lower-priority process
        if (i < n - 1 && processes[i].priority < processes[i + 1].priority) {
            processes[i + 1].waitingTime -= processes[i + 1].priority - processes[i].priority;
            if (processes[i + 1].waitingTime < 0) {
                processes[i + 1].waitingTime = 0; // Avoid negative waiting time
            }
        }
    }

    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++) {
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
    }
}

// Function to print process details
void printProcesses(Process processes[], int n) {
    float totalWaitingTime = 0, totalTurnaroundTime = 0;

    printf("ID\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", 
               processes[i].id, processes[i].priority, 
               processes[i].burstTime, processes[i].waitingTime, 
               processes[i].turnaroundTime);
    }

    printf("\nAverage Waiting Time: %.2f\n", totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", totalTurnaroundTime / n);
}

int main() {
    Process processes[MAX_PROCESSES];
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input details for each process
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter priority and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].priority, &processes[i].burstTime);
    }

    // Perform Ripple Effect Scheduling
    rippleEffectScheduling(processes, n);

    // Print process details and average times
    printProcesses(processes, n);

    return 0;
}
