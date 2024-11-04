#include <stdio.h>

struct Process {
    int pid;        // Process ID
    int bt;         // Burst Time
    int at;         // Arrival Time
    int rt;         // Remaining Time
    int ct;         // Completion Time
    int wt;         // Waiting Time
    int tat;        // Turnaround Time
};

void findAvgTime(struct Process proc[], int n) {
    int completed = 0, time = 0, min_rt = __INT_MAX__;
    int shortest = -1, finish_time;
    int total_wt = 0, total_tat = 0;

    while (completed != n) {
        for (int i = 0; i < n; i++) {
            if (proc[i].at <= time && proc[i].rt > 0 && proc[i].rt < min_rt) {
                min_rt = proc[i].rt;
                shortest = i;
            }
        }

        if (shortest == -1) {
            time++;
            continue;
        }

        proc[shortest].rt--;
        min_rt = proc[shortest].rt;

        if (min_rt == 0) {
            min_rt = __INT_MAX__;
            completed++;
            finish_time = time + 1;
            proc[shortest].ct = finish_time;
            proc[shortest].tat = proc[shortest].ct - proc[shortest].at;
            proc[shortest].wt = proc[shortest].tat - proc[shortest].bt;

            total_wt += proc[shortest].wt;
            total_tat += proc[shortest].tat;
        }
        time++;
    }

    printf("\nProcesses | Burst Time | Arrival Time | Waiting Time | Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].bt, proc[i].at, proc[i].wt, proc[i].tat);
    }

    printf("\nAverage Waiting Time = %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time = %.2f", (float)total_tat / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];
    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        printf("Enter burst time and arrival time for process P%d: ", proc[i].pid);
        scanf("%d %d", &proc[i].bt, &proc[i].at);
        proc[i].rt = proc[i].bt;
    }

    findAvgTime(proc, n);
    return 0;
}
