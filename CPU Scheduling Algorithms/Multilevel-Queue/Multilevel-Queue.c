#include <stdio.h>

void findavgTime(int processes[], int n, int bt[], int priority[]) {
    int wt[n], tat[n];
    for (int i = 0; i < n; i++) {
        if (priority[i] == 1) {
            // Execute high priority first
            wt[i] = (i == 0) ? 0 : wt[i - 1] + bt[i - 1];
        } else {
            // Execute low priority last
            wt[i] = (i == 0) ? 0 : wt[i - 1] + bt[i - 1] + (bt[i - 1] / 2);
        }
        tat[i] = bt[i] + wt[i];
    }
    
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
    int priority[] = {1, 2, 1}; // 1 for high priority, 2 for low priority
    findavgTime(processes, n, burst_time, priority);
    return 0;
}
