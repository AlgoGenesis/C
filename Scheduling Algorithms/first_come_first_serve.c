#include <stdio.h>

void fcfs(int processes[], int n, int burst_time[]) {
    int waiting_time[n], turnaround_time[n], total_wait = 0, total_turnaround = 0;

    // Calculate waiting time
    waiting_time[0] = 0;
    for (int i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];
    }

    // Calculate turnaround time
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = waiting_time[i] + burst_time[i];
        total_wait += waiting_time[i];
        total_turnaround += turnaround_time[i];
    }

    printf("Process | Burst Time | Waiting Time | Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t     %d\t       %d\t         %d\n", 
               processes[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    printf("Average Waiting Time: %.2f\n", (float)total_wait / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround / n);
}

int main() {
    int processes[] = {1, 2, 3, 4};
    int burst_time[] = {4, 3, 2, 1};
    int n = sizeof(processes) / sizeof(processes[0]);

    fcfs(processes, n, burst_time);
    return 0;
}
