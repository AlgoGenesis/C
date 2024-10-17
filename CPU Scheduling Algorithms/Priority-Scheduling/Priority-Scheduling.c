#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[], int priority[]) {
    int rt[n];
    for (int i = 0; i < n; i++)
        rt[i] = bt[i];
    
    for (int t = 0; t < n; t++) {
        int min_index = -1;
        for (int j = 0; j < n; j++) {
            if (rt[j] > 0 && (min_index == -1 || priority[j] < priority[min_index])) {
                min_index = j;
            }
        }
        if (min_index != -1) {
            rt[min_index]--;
            if (rt[min_index] == 0) {
                wt[min_index] = t - bt[min_index];
            }
        }
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findavgTime(int processes[], int n, int bt[], int priority[]) {
    int wt[n], tat[n];
    findWaitingTime(processes, n, bt, wt, priority);
    findTurnAroundTime(processes, n, bt, wt, tat);
    
    printf("Processes   Burst Time   Waiting Time   Turn-Around Time\n");
    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf(" %d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }
    printf("Average waiting time = %.2f\n", (float)total_wt / n);
    printf("Average turn-around time = %.2f\n", (float)total_tat / n);
}

int main() {
    int processes[] = {1, 2, 3};
    int n = sizeof(processes) / sizeof(processes[0]);
    int burst_time[] = {10, 5, 8};
    int priority[] = {1, 3, 2}; // Lower value indicates higher priority
    findavgTime(processes, n, burst_time, priority);
    return 0;
}
