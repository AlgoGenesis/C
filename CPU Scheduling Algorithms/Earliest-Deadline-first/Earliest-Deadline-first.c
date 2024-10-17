#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int arrival[], int wt[]) {
    // Initialize waiting time for all processes
    for (int i = 0; i < n; i++)
        wt[i] = 0;

    int current_time = 0;
    for (int i = 0; i < n; i++) {
        if (current_time < arrival[i]) {
            current_time = arrival[i]; // Idle until the process arrives
        }
        wt[i] = current_time - arrival[i];
        current_time += bt[i]; // Update current time
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findAvgTime(int processes[], int n, int bt[], int arrival[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, bt, arrival, wt);
    findTurnAroundTime(processes, n, bt, wt, tat);

    printf("Processes  Burst time  Arrival time  Waiting time  Turnaround time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("   %d ", processes[i]);
        printf("       %d ", bt[i]);
        printf("           %d ", arrival[i]);
        printf("           %d ", wt[i]);
        printf("               %d\n", tat[i]);
    }
    printf("Average waiting time = %.2f\n", (float)total_wt / n);
    printf("Average turnaround time = %.2f\n", (float)total_tat / n);
}

int main() {
    int processes[] = {1, 2, 3};
    int n = sizeof(processes) / sizeof(processes[0]);
    int burst_time[] = {5, 3, 8};
    int arrival_time[] = {0, 1, 2};

    findAvgTime(processes, n, burst_time, arrival_time);
    
    return 0;
}
