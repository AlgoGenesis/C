#include <stdio.h>

struct Process {
    int id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
};

void calculate_times(struct Process processes[], int n, int quantum) {
    int remaining_time[n];
    for (int i = 0; i < n; i++) {
        remaining_time[i] = processes[i].burst_time;
    }

    int t = 0; // Current time
    while (1) {
        int done = 1; // Check if all processes are done
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = 0; // There is a process pending
                if (remaining_time[i] > quantum) {
                    t += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    t += remaining_time[i];
                    processes[i].waiting_time = t - processes[i].burst_time - processes[i].arrival_time;
                    remaining_time[i] = 0;
                }
            }
        }
        if (done) break; // All processes are done
    }

    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

void print_processes(struct Process processes[], int n) {
    printf("Process ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
               processes[i].id, 
               processes[i].burst_time, 
               processes[i].arrival_time, 
               processes[i].waiting_time, 
               processes[i].turnaround_time);
    }
}

int main() {
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1; // Process ID
        printf("Enter burst time and arrival time for Process %d: ", processes[i].id);
        scanf("%d %d", &processes[i].burst_time, &processes[i].arrival_time);
    }

    printf("Enter quantum time: ");
    scanf("%d", &quantum);

    calculate_times(processes, n, quantum);
    print_processes(processes, n);

    return 0;
}