#include <stdio.h>

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
};

void calculate_waiting_and_turnaround_time(struct Process processes[], int n) {
    processes[0].waiting_time = 0; // First process has no waiting time

    // Calculate waiting time
    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
    }

    // Calculate turnaround time
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

void sort_processes(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].arrival_time > processes[j].arrival_time || 
                (processes[i].arrival_time == processes[j].arrival_time && processes[i].priority > processes[j].priority)) {
                struct Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

void print_processes(struct Process processes[], int n) {
    printf("Process ID\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
               processes[i].id, 
               processes[i].arrival_time, 
               processes[i].burst_time, 
               processes[i].priority, 
               processes[i].waiting_time, 
               processes[i].turnaround_time);
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1; // Process ID
        printf("Enter arrival time, burst time, and priority for Process %d: ", processes[i].id);
        scanf("%d %d %d", &processes[i].arrival_time, &processes[i].burst_time, &processes[i].priority);
    }

    // Sort processes by arrival time and priority
    sort_processes(processes, n);
    calculate_waiting_and_turnaround_time(processes, n);
    print_processes(processes, n);

    return 0;
}