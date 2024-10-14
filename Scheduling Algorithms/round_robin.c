#include <stdio.h>
#include <stdbool.h>

void round_robin(int processes[], int n, int burst_time[], int quantum) {
    int remaining_burst[n], waiting_time[n], turnaround_time[n];
    int time = 0, total_wait = 0, total_turnaround = 0;
    bool done;

    // Copy burst times to remaining burst time array
    for (int i = 0; i < n; i++) 
        remaining_burst[i] = burst_time[i];

    // Round Robin Scheduling
    do {
        done = true;
        for (int i = 0; i < n; i++) {
            if (remaining_burst[i] > 0) {
                done = false;
                if (remaining_burst[i] > quantum) {
                    time += quantum;
                    remaining_burst[i] -= quantum;
                } else {
                    time += remaining_burst[i];
                    waiting_time[i] = time - burst_time[i];
                    remaining_burst[i] = 0;
                }
            }
        }
    } while (!done);

    // Calculate turnaround time
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
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
    int quantum = 2;
    int n = sizeof(processes) / sizeof(processes[0]);

    round_robin(processes, n, burst_time, quantum);
    return 0;
}
