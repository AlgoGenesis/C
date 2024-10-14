#include <stdio.h>

// Structure to store process details
struct Process {
    int pid;      // Process ID
    int arrival;  // Arrival time
    int burst;    // Burst time
    int waiting;  // Waiting time
    int turnaround; // Turnaround time
};

// Function to calculate waiting and turnaround times
void calculateTimes(struct Process processes[], int n) {
    int completionTime = 0;

    // Calculate waiting time and turnaround time for each process
    for (int i = 0; i < n; i++) {
        if (completionTime < processes[i].arrival) {
            completionTime = processes[i].arrival; // Idle time handling
        }
        completionTime += processes[i].burst;

        processes[i].turnaround = completionTime - processes[i].arrival;
        processes[i].waiting = processes[i].turnaround - processes[i].burst;
    }
}

// Function to display process information
void printProcesses(struct Process processes[], int n) {
    printf("PID\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", 
               processes[i].pid, 
               processes[i].arrival, 
               processes[i].burst, 
               processes[i].waiting, 
               processes[i].turnaround);
    }
}

// Function to calculate average waiting and turnaround times
void printAverages(struct Process processes[], int n) {
    float totalWaiting = 0, totalTurnaround = 0;

    for (int i = 0; i < n; i++) {
        totalWaiting += processes[i].waiting;
        totalTurnaround += processes[i].turnaround;
    }

    printf("\nAverage Waiting Time: %.2f\n", totalWaiting / n);
    printf("Average Turnaround Time: %.2f\n", totalTurnaround / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival, &processes[i].burst);
    }

    // Calculate waiting and turnaround times
    calculateTimes(processes, n);

    // Display process details and averages
    printf("\nProcess Execution Order (FCFS):\n");
    printProcesses(processes, n);
    printAverages(processes, n);

    return 0;
}
