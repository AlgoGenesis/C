#include <stdio.h>

struct Process {
    int id;
    int burstTime;
    int remainingTime;
    int waitTime;
    int turnAroundTime;
    int completed;
};

// Function to determine the time slice based on burst time
int calculateTimeSlice(int burstTime) {
    if (burstTime <= 5)
        return 2;  // Short burst, shorter time slice
    else if (burstTime <= 10)
        return 4;  // Medium burst, moderate time slice
    else
        return 6;  // Long burst, longer time slice
}

// SmartSlice Scheduling Function
void smartSliceScheduling(struct Process proc[], int n) {
    int time = 0;
    int completedProcesses = 0;

    while (completedProcesses < n) {
        int allDone = 1;  // Flag to check if all processes are done

        for (int i = 0; i < n; i++) {
            if (proc[i].remainingTime > 0) {
                allDone = 0;
                
                int timeSlice = calculateTimeSlice(proc[i].burstTime);  // Dynamic time slice
                int execTime = (proc[i].remainingTime > timeSlice) ? timeSlice : proc[i].remainingTime;

                printf("Process %d executing from time %d to %d\n", proc[i].id, time, time + execTime);

                time += execTime;
                proc[i].remainingTime -= execTime;

                if (proc[i].remainingTime == 0) {
                    proc[i].completed = 1;
                    proc[i].turnAroundTime = time;
                    proc[i].waitTime = proc[i].turnAroundTime - proc[i].burstTime;
                    completedProcesses++;
                }
            }
        }
        if (allDone) break;  // Exit if all processes are done
    }

    // Calculate and display results
    printf("\nProcess\tBurst Time\tWait Time\tTurnaround Time\n");
    int totalWaitTime = 0, totalTurnAroundTime = 0;
    for (int i = 0; i < n; i++) {
        totalWaitTime += proc[i].waitTime;
        totalTurnAroundTime += proc[i].turnAroundTime;
        printf("%d\t%d\t\t%d\t\t%d\n", proc[i].id, proc[i].burstTime, proc[i].waitTime, proc[i].turnAroundTime);
    }
    printf("\nAverage Wait Time: %.2f\n", (float)totalWaitTime / n);
    printf("Average Turnaround Time: %.2f\n", (float)totalTurnAroundTime / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &proc[i].burstTime);
        proc[i].id = i + 1;
        proc[i].remainingTime = proc[i].burstTime;
        proc[i].completed = 0;
        proc[i].waitTime = 0;
        proc[i].turnAroundTime = 0;
    }

    printf("\nExecuting SmartSlice Scheduling...\n");
    smartSliceScheduling(proc, n);

    return 0;
}
