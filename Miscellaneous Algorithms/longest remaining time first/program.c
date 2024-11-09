#include <stdio.h>

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
};

void calculateLRTF(struct Process processes[], int n) {
    int time = 0, completed = 0, maxIndex;
    while (completed != n) {
        maxIndex = -1;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= time && processes[i].remainingTime > 0) {
                if (maxIndex == -1 || processes[i].remainingTime > processes[maxIndex].remainingTime) {
                    maxIndex = i;
                }
            }
        }
        
        if (maxIndex == -1) {
            time++; // No process is ready to execute
        } else {
            processes[maxIndex].remainingTime--;
            time++;

            if (processes[maxIndex].remainingTime == 0) { // Process completed
                completed++;
                processes[maxIndex].completionTime = time;
                processes[maxIndex].turnaroundTime = processes[maxIndex].completionTime - processes[maxIndex].arrivalTime;
                processes[maxIndex].waitingTime = processes[maxIndex].turnaroundTime - processes[maxIndex].burstTime;
            }
        }
    }
}

void displayProcesses(struct Process processes[], int n) {
    printf("PID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", 
               processes[i].pid, processes[i].arrivalTime, processes[i].burstTime, 
               processes[i].completionTime, processes[i].turnaroundTime, 
               processes[i].waitingTime);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter arrival time and burst time for process %d: ", processes[i].pid);
        scanf("%d %d", &processes[i].arrivalTime, &processes[i].burstTime);
        processes[i].remainingTime = processes[i].burstTime;
    }

    calculateLRTF(processes, n);
    displayProcesses(processes, n);

    return 0;
}
