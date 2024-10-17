#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    // Initialize waiting time for first process
    wt[0] = 0;

    // Calculate waiting time for each process
    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findAvgTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, bt, wt);
    findTurnAroundTime(processes, n, bt, wt, tat);

    printf("Processes  Burst time  Waiting time  Turnaround time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("   %d ", processes[i]);
        printf("       %d ", bt[i]);
        printf("           %d ", wt[i]);
        printf("               %d\n", tat[i]);
    }
    printf("Average waiting time = %.2f\n", (float)total_wt / n);
    printf("Average turnaround time = %.2f\n", (float)total_tat / n);
}

void sortProcessesByBurstTime(int processes[], int n, int bt[]) {
    // Simple Bubble Sort to sort processes by burst time (LJF)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (bt[j] < bt[j + 1]) { // Sort in descending order
                // Swap burst times
                int temp_bt = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp_bt;

                // Swap process IDs
                int temp_pid = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp_pid;
            }
        }
    }
}

int main() {
    int processes[] = {1, 2, 3};
    int n = sizeof(processes) / sizeof(processes[0]);
    int burst_time[] = {10, 5, 8};

    // Sort processes by burst time for LJF
    sortProcessesByBurstTime(processes, n, burst_time);
    findAvgTime(processes, n, burst_time);
    
    return 0;
}
