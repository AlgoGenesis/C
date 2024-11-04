#include <stdio.h>

typedef struct {
    int id;         // Process ID
    int arrival;    // Arrival Time
    int burst;      // Burst Time
    int wait;       // Waiting Time
    int turnAround; // Turnaround Time
    float response; // Response Ratio
} Process;

void calculateHRRN(Process processes[], int n) {
    int completed = 0, time = 0;
    int idx = -1;

    while (completed != n) {
        float maxRatio = -1;

        // Calculate Response Ratio for each process
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival <= time && processes[i].burst > 0) {
                float ratio = (float)(time - processes[i].arrival + processes[i].burst) / processes[i].burst;
                if (ratio > maxRatio) {
                    maxRatio = ratio;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            time++;
            continue;
        }

        // Process the selected task
        time += processes[idx].burst;
        processes[idx].wait = time - processes[idx].arrival - processes[idx].burst;
        processes[idx].turnAround = time - processes[idx].arrival;
        processes[idx].response = maxRatio;
        processes[idx].burst = 0;
        completed++;
    }
}

void printProcesses(Process processes[], int n) {
    printf("ID\tArrival\tBurst\tWaiting\tTurnaround\tResponse\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t\t%.2f\n", 
                processes[i].id, processes[i].arrival, processes[i].burst,
                processes[i].wait, processes[i].turnAround, processes[i].response);
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter arrival and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival, &processes[i].burst);
        processes[i].wait = 0;
        processes[i].turnAround = 0;
        processes[i].response = 0.0;
    }

    calculateHRRN(processes, n);
    printProcesses(processes, n);

    return 0;
}
