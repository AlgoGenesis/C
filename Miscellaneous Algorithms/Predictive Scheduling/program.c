#include <stdio.h>

#define MAX_PROCESSES 10

struct Process {
    int pid;
    int burstTime;
    int predictedBurst;
};

// Function to calculate predicted burst time using exponential averaging
int predictBurstTime(int previousBurst, int prevPredicted, float alpha) {
    return (int)(alpha * previousBurst + (1 - alpha) * prevPredicted);
}

void sortByPredictedBurst(struct Process processes[], int n) {
    struct Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].predictedBurst > processes[j].predictedBurst) {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    float alpha = 0.5; // Smoothing factor for prediction (0 < alpha < 1)

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process processes[MAX_PROCESSES];

    // Input burst times for each process
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter burst time for process %d: ", processes[i].pid);
        scanf("%d", &processes[i].burstTime);

        // Initial prediction, assume it’s the same as the first burst time
        processes[i].predictedBurst = processes[i].burstTime;
    }

    // Predict burst time for each process (starting from the second burst)
    for (int i = 1; i < n; i++) {
        processes[i].predictedBurst = predictBurstTime(processes[i - 1].burstTime, processes[i - 1].predictedBurst, alpha);
    }

    // Sort processes by predicted burst time
    sortByPredictedBurst(processes, n);

    printf("\nScheduled Processes (in order of predicted burst time):\n");
    printf("PID\tBurst Time\tPredicted Burst Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", processes[i].pid, processes[i].burstTime, processes[i].predictedBurst);
    }

    return 0;
}
