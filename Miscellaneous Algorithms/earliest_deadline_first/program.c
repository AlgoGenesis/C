#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 10

typedef struct {
    int id;         // Task ID
    int deadline;   // Deadline (time units)
    int burst_time; // Execution time (time units)
} Task;

// Function to compare tasks by deadline for qsort
int compare(const void *a, const void *b) {
    Task *taskA = (Task *)a;
    Task *taskB = (Task *)b;
    return taskA->deadline - taskB->deadline;
}

// Function to implement Earliest Deadline First (EDF) scheduling
void scheduleEDF(Task tasks[], int n) {
    // Sort tasks by deadline
    qsort(tasks, n, sizeof(Task), compare);

    printf("Task Execution Order:\n");
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        printf("Executing Task %d (Deadline: %d, Burst Time: %d) at time %d\n",
               tasks[i].id, tasks[i].deadline, tasks[i].burst_time, currentTime);

        // Update current time
        currentTime += tasks[i].burst_time;

        // Check if task missed its deadline
        if (currentTime > tasks[i].deadline) {
            printf("Task %d missed its deadline!\n", tasks[i].id);
        }
    }
}

int main() {
    int n;
    Task tasks[MAX_TASKS];

    printf("Enter the number of tasks (max %d): ", MAX_TASKS);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter details for Task %d:\n", i + 1);
        tasks[i].id = i + 1;
        printf("Deadline: ");
        scanf("%d", &tasks[i].deadline);
        printf("Burst Time: ");
        scanf("%d", &tasks[i].burst_time);
    }

    // Schedule tasks using EDF
    scheduleEDF(tasks, n);

    return 0;
}
