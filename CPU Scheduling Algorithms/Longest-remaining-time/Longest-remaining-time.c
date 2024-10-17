#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    // Initialize waiting time for all processes
    for (int i = 0; i < n; i++)
        wt[i] = 0;

    // Remaining burst times
    int remaining_bt[n];
    for (int i = 0; i < n; i++)
        remaining_bt[i] = bt[i];

    int complete = 0, t = 0;
    while (complete < n) {
        int max_index = -1;
        int max_time = -1;

        // Find process with longest remaining time
        for (int i = 0; i < n; i++) {
            if (remaining_bt[i] > max_time && remaining_bt[i] > 0) {
                max_time = remaining_bt[i];
                max_index = i;
            }
        }

        if (max_index != -1) {
            remaining_bt[max_index]--;
            if (remaining_bt[max_index] == 0) {
                complete++;
                wt[max_index] = t + 1 - bt[max_index]; // Calculate waiting time
            }
        }
        t++;
    }
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

int main() {
    int processes[] = {1, 2, 3};
    int n = sizeof(processes) / sizeof(processes[0]);
    int burst_time[] = {8, 4, 9};

    findAvgTime(processes, n, burst_time);
    
    return 0;
}
