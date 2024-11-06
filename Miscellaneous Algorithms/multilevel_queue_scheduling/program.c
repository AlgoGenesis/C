#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int pid;        // Process ID
    int burstTime;  // Burst Time
    int queue;      // Queue Type: 1=System, 2=Interactive, 3=Batch
} Process;

// Function to sort processes based on queue priority
void sortProcessesByQueue(Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].queue > processes[j + 1].queue) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

// Function to calculate waiting time and turn around time
void calculateTimes(Process processes[], int n) {
    int waitingTime[MAX], turnAroundTime[MAX];
    int totalWaitingTime = 0, totalTurnAroundTime = 0;
    int completionTime = 0;

    printf("\nProcess Execution Order:\n");

    for (int i = 0; i < n; i++) {
        waitingTime[i] = completionTime;
        completionTime += processes[i].burstTime;
        turnAroundTime[i] = waitingTime[i] + processes[i].burstTime;

        totalWaitingTime += waitingTime[i];
        totalTurnAroundTime += turnAroundTime[i];

        printf("Process %d (Queue %d): Waiting Time = %d, Turnaround Time = %d\n",
               processes[i].pid, processes[i].queue, waitingTime[i], turnAroundTime[i]);
    }

    printf("\nAverage Waiting Time = %.2f", (float)totalWaitingTime / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)totalTurnAroundTime / n);
}

int main() {
    Process processes[MAX];
    int n;

    printf("Enter the number of processes (max %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX) {
        printf("Number of processes should be less than or equal to %d.\n", MAX);
        return 1;
    }

    // Input process details
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Process %d:\n", i + 1);
        printf("Process ID: ");
        scanf("%d", &processes[i].pid);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burstTime);
        printf("Queue (1=System, 2=Interactive, 3=Batch): ");
        scanf("%d", &processes[i].queue);

        if (processes[i].queue < 1 || processes[i].queue > 3) {
            printf("Invalid queue type. Please enter 1, 2, or 3.\n");
            i--; // Retry current process input
        }
    }

    // Sort processes by queue priority
    sortProcessesByQueue(processes, n);

    // Calculate and display times
    calculateTimes(processes, n);

    return 0;
}
